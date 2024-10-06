#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

struct MyModPass : public PassInfoMixin<MyModPass> {

  bool isFuncLogger(StringRef name) {
    return name == "instLogger";
  }

  PreservedAnalyses run(Module &M, ModuleAnalysisManager &AM) {
    for (auto &F : M) {
     if (isFuncLogger(F.getName()) || F.isDeclaration())
        continue;
      LLVMContext &Ctx = F.getContext();
      IRBuilder<> builder(Ctx);
      Type *retType = Type::getVoidTy(Ctx);

      ArrayRef<Type *> funcLogParamTypes = {builder.getInt8Ty()->getPointerTo()};
      FunctionType *funcLogFuncType = FunctionType::get(retType, funcLogParamTypes, false);
      FunctionCallee instLogFunc = M.getOrInsertFunction("instLogger", funcLogFuncType);

      for (auto &B : F) {
        for (auto &I : B) {
          Value *valueAddr = ConstantInt::get(builder.getInt64Ty(), (int64_t)(&I));
          if (auto *call = dyn_cast<CallInst>(&I)) {
             Function *callee = call->getCalledFunction();
             if (!callee || isFuncLogger(callee->getName()))
               continue;
          }
          if (auto *inst = dyn_cast<Instruction>(&I)) {
            builder.SetInsertPoint(inst);
            if (auto *inst = dyn_cast<PHINode>(&I))
              continue;

            std::string str;
            raw_string_ostream(str) << inst->getOpcodeName();
            for (auto &U : I.operands())
              if (auto *us_inst = dyn_cast<Instruction>(&U))
                raw_string_ostream(str) << " <- " << us_inst->getOpcodeName();

            Value *args[] = {builder.CreateGlobalStringPtr(str)};
            builder.CreateCall(instLogFunc, args);
          }
        }
      }
    }
    return PreservedAnalyses::none();
  };
};

PassPluginLibraryInfo getPassPluginInfo() {
  const auto callback = [](PassBuilder &PB) {
    PB.registerPipelineStartEPCallback([&](ModulePassManager &MPM, auto) {
      MPM.addPass(MyModPass{});
      return true;
    });
  };

  return {LLVM_PLUGIN_API_VERSION, "MyPlugin", "0.0.1", callback};
};

/* When a plugin is loaded by the driver, it will call this entry point to
obtain information about this plugin and about how to register its passes.
*/
extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
  return getPassPluginInfo();
}
