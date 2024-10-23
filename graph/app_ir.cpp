#include "sim.h"
#include <iostream>



#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

int main() {
  std::cout << "start\n";
  LLVMContext context;
  // ; ModuleID = 'app.c'
  // source_filename = "app.c"
  Module *module = new Module("app.c", context);
  IRBuilder<> builder(context);

  // declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef)
  // local_unnamed_addr #1
  Type *voidType = Type::getVoidTy(context);
  ArrayRef<Type *> simPutPixelParamTypes = {Type::getInt32Ty(context),
                                            Type::getInt32Ty(context),
                                            Type::getInt32Ty(context)};
  FunctionType *simPutPixelType =
      FunctionType::get(voidType, simPutPixelParamTypes, false);
  FunctionCallee simPutPixelFunc =
      module->getOrInsertFunction("simPutPixel", simPutPixelType);

  // declare void @simFlush(...) local_unnamed_addr #1
  FunctionType *simFlushType = FunctionType::get(voidType, {voidType}, false);
  FunctionCallee simFlushFunc =
      module->getOrInsertFunction("simFlush", simFlushType);

  // define dso_local void @app() local_unnamed_addr #0 {
  FunctionType *appFuncType = FunctionType::get(builder.getInt32Ty(), false);
  Function *appFunc =
      Function::Create(appFuncType, Function::ExternalLinkage, "app", module);

  // ------------------------------------------------
  // My code goes here
  // ------------------------------------------------
  FunctionType *llvmAbsI32Type = FunctionType::get(builder.getInt32Ty(), {builder.getInt32Ty(), builder.getInt1Ty()}, false);
  FunctionCallee llvmAbsI32Func =
      module->getOrInsertFunction("llvm.abs.i32", llvmAbsI32Type);
  
    //  declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #2
  FunctionType *p0i8Type = FunctionType::get(voidType, {builder.getInt64Ty(), builder.getInt8PtrTy()}, false);
  FunctionCallee p0i8Func = module->getOrInsertFunction("llvm.lifetime.start.p0i8", p0i8Type);
  
    //  declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #5
  FunctionType *memsetType = FunctionType::get(voidType, {builder.getInt8PtrTy(), builder.getInt8Ty(), builder.getInt64Ty(), builder.getInt1Ty()}, false);
    FunctionCallee memsetFunc = module->getOrInsertFunction("llvm.memset.p0i8.i64", memsetType);


    // declare i32 @simRand(...) local_unnamed_addr #3
  FunctionType *simRandType = FunctionType::get(builder.getInt32Ty(), false);
    FunctionCallee simRandFunc = module->getOrInsertFunction("simRand", simRandType);
  std::cout << "init\n";

  //  define dso_local i32 @is_good_pnt(i32 noundef %0, i32 noundef %1) local_unnamed_addr #0 {
  FunctionType *is_good_pntType = FunctionType::get(Type::getInt32Ty(context), {Type::getInt32Ty(context), Type::getInt32Ty(context)}, false);
  Function *is_good_pntFunc = Function::Create(is_good_pntType, Function::ExternalLinkage, "is_good_pnt", module);
  {
    // BasicBlocks:
    BasicBlock *BB0 = BasicBlock::Create(context, "", is_good_pntFunc);
    builder.SetInsertPoint(BB0);
    auto args = is_good_pntFunc->arg_begin();
    llvm::Value *val0 = &*args++;
    llvm::Value *val1 = &*args;
    // MAIN CODE
    Value *val3 = builder.CreateAdd(val0, builder.getInt32(-1));
    Value *val4 = builder.CreateICmpULT(val3, builder.getInt32(699));
    Value *val5 = builder.CreateAdd(val1, builder.getInt32(-1));
    Value *val6 = builder.CreateICmpULT(val5, builder.getInt32(499));
    Value *val7 = builder.CreateAnd(val4, val6);
    Value *val8 = builder.CreateZExt(val7, llvm::Type::getInt32Ty(context));
    builder.CreateRet(val8);
  }
  std::cout << "func1\n";

  //  define dso_local void @drawLine(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, i32 noundef %4) local_unnamed_addr #1 {
  FunctionType *drawLineType = FunctionType::get(voidType, {Type::getInt32Ty(context), Type::getInt32Ty(context), Type::getInt32Ty(context), Type::getInt32Ty(context), Type::getInt32Ty(context)}, false);
  Function *drawLineFunc = Function::Create(is_good_pntType, Function::ExternalLinkage, "drawLine", module);
  std::cout << "def1\n";
  {
    // BasicBlocks:
    BasicBlock *BB0 = BasicBlock::Create(context, "", drawLineFunc);
    builder.SetInsertPoint(BB0);
    BasicBlock *BB8 = BasicBlock::Create(context, "", drawLineFunc);
    BasicBlock *BB9 = BasicBlock::Create(context, "", drawLineFunc);
    BasicBlock *BB22 = BasicBlock::Create(context, "", drawLineFunc);
    BasicBlock *BB23 = BasicBlock::Create(context, "", drawLineFunc);
  std::cout << "bb1\n";
    // MAIN CODE
    auto args = is_good_pntFunc->arg_begin();
    llvm::Value *val0 = &*args++;
    llvm::Value *val1 = &*args++;
    llvm::Value *val2 = &*args++;
    llvm::Value *val3 = &*args++;
    llvm::Value *val4 = &*args;
  std::cout << "args1asfasfasf\n";
    Value *val6 = builder.CreateShl(val4, builder.getInt32(16));
  std::cout << "int16\n" << std::endl;
    Value *val7 = builder.CreateAdd(val6, builder.getInt32(-16776961));
  std::cout << "int1\n" << std::endl;
    builder.CreateBr(BB9);
  std::cout << "br1\n" << std::endl;
    builder.SetInsertPoint(BB8);
    builder.CreateRetVoid();
  std::cout << "retv1\n" << std::endl;
    builder.SetInsertPoint(BB9);
    PHINode *val10 = builder.CreatePHI(builder.getInt32Ty(), 2);
  std::cout << "phi1\n" << std::endl;
// unknown cmd: %10 = phi i32 [ 0, %5 ], [ %24, %23 ]
    Value *val11 = builder.CreateMul(val10, val2);
    Value *val12 = builder.CreateSDiv(val11, builder.getInt32(10));
    Value *val13 = builder.CreateAdd(val12, val0);
    Value *val14 = builder.CreateMul(val10, val3);
    Value *val15 = builder.CreateSDiv(val14, builder.getInt32(10));
    Value *val16 = builder.CreateAdd(val15, val1);
    Value *val17 = builder.CreateAdd(val13, builder.getInt32(-700));
  std::cout << "icmp1\n";
    Value *val18 = builder.CreateICmpULT(val17, builder.getInt32(-699));
    Value *val19 = builder.CreateAdd(val16, builder.getInt32(-500));
    Value *val20 = builder.CreateICmpULT(val19, builder.getInt32(-499));
    Value *val21 = builder.CreateOr(val18, val20);
  std::cout << "condbr1\n";
    builder.CreateCondBr(val21, BB23, BB22);
    builder.SetInsertPoint(BB22);
    builder.CreateCall(simPutPixelFunc, {val13, val16, val7});
  std::cout << "call1\n";
    builder.CreateBr(BB23);
    builder.SetInsertPoint(BB23);
    Value *val24 = builder.CreateAdd(val10, builder.getInt32(1));
    Value *val25 = builder.CreateICmpEQ(val24, builder.getInt32(10));
    builder.CreateCondBr(val25, BB8, BB9);
    std::cout << "phis1\n";
// unknown cmd: %10 = phi i32 [ 0, %5 ], [ %24, %23 ]
    val10->addIncoming(builder.getInt32(0), BB0);
    val10->addIncoming(val24, BB23);
  }
  std::cout << "func2\n";

  //  define dso_local i32 @getAbsVelocity(i32 noundef %0, i32 noundef %1) local_unnamed_addr #0 {
  FunctionType *getAbsVelocityType = FunctionType::get(Type::getInt32Ty(context), {Type::getInt32Ty(context), Type::getInt32Ty(context)}, false); 
  Function *getAbsVelocityFunc = Function::Create(getAbsVelocityType, Function::ExternalLinkage, "getAbsVelocity", module);
  {
    // BasicBlocks:
    BasicBlock *BB0 = BasicBlock::Create(context, "", getAbsVelocityFunc);
    builder.SetInsertPoint(BB0);
    // MAIN CODE
    auto args = is_good_pntFunc->arg_begin();
    llvm::Value *val0 = &*args++;
    llvm::Value *val1 = &*args;
    Value *val3 = builder.CreateCall(llvmAbsI32Func, {val0, builder.getInt1(true)});
    Value *val4 = builder.CreateCall(llvmAbsI32Func, {val1, builder.getInt1(true)});
    Value *val5 = builder.CreateAdd(val4, val3);
    Value *val6 = builder.CreateAnd(val5, builder.getInt32(255));
    builder.CreateRet(val6);
  }
  std::cout << "func3\n";

  //  define dso_local void @app() local_unnamed_addr #4 {
  {
    // BasicBlocks:
    BasicBlock *BB0 = BasicBlock::Create(context, "", appFunc);
    builder.SetInsertPoint(BB0);
    BasicBlock *BB5 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB9 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB11 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB24 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB39 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB50 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB60 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB73 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB74 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB77 = BasicBlock::Create(context, "", appFunc);
    BasicBlock *BB78 = BasicBlock::Create(context, "", appFunc);
    // MAIN CODE
    llvm::AllocaInst *val1 = builder.CreateAlloca(
        ArrayType::get(Type::getInt32Ty(context), 10),
        nullptr, "array");
    llvm::AllocaInst *val2 = builder.CreateAlloca(
        ArrayType::get(Type::getInt32Ty(context), 10),
        nullptr, "array");

    Value *val3 = builder.CreateBitCast(val1, llvm::Type::getInt8PtrTy(context));

    builder.CreateCall(p0i8Func, {builder.getInt64(40), val3});
    builder.CreateCall(memsetFunc, {val3, builder.getInt8(0), builder.getInt64(40), builder.getInt1(false)});
    Value *val4 = builder.CreateBitCast(val2, llvm::Type::getInt8PtrTy(context));
    builder.CreateCall(p0i8Func, {builder.getInt64(40), val4});
    builder.CreateCall(memsetFunc, {val4, builder.getInt8(0), builder.getInt64(40), builder.getInt1(false)});
    builder.CreateBr(BB5);
    builder.SetInsertPoint(BB5);
    PHINode *val6 = builder.CreatePHI(builder.getInt32Ty(), 2);
// unknown cmd: %6 = phi i32 [ 0, %0 ], [ %10, %9 ]
    Value *val7 = builder.CreateURem(val6, builder.getInt32(5));
    Value *val8 = builder.CreateICmpEQ(val7, builder.getInt32(0));
    builder.CreateBr(BB11);
    builder.SetInsertPoint(BB9);
    Value *val10 = builder.CreateAdd(val6, builder.getInt32(1));
    builder.CreateBr(BB5);
    builder.SetInsertPoint(BB11);
    PHINode *val12 = builder.CreatePHI(builder.getInt32Ty(), 2);
 // unknown cmd: %12 = phi i64 [ 0, %5 ], [ %81, %78 ]
    Value *val13 = builder.CreateInBoundsGEP(
          ArrayType::get(Type::getInt32Ty(context), 10), 
          val1, {val12});
// check?    unknown cmd: %13 = getelementptr inbounds [10 x i32], [10 x i32]* %1, i64 0, i64 %12
    Value *val14 = builder.CreateLoad(builder.getInt32Ty(), val13);
    Value *val15 = builder.CreateInBoundsGEP(
          ArrayType::get(Type::getInt32Ty(context), 10), 
          val2, {val12});
   //check? unknown cmd: %15 = getelementptr inbounds [10 x i32], [10 x i32]* %2, i64 0, i64 %12
    Value *val16 = builder.CreateLoad(builder.getInt32Ty(), val15);
    Value *val17 = builder.CreateSDiv(val14, builder.getInt32(100));
    Value *val18 = builder.CreateSDiv(val16, builder.getInt32(100));
    Value *val19 = builder.CreateAdd(val17, builder.getInt32(-700));
    Value *val20 = builder.CreateICmpULT(val19, builder.getInt32(-699));
    Value *val21 = builder.CreateAdd(val18, builder.getInt32(-500));
    Value *val22 = builder.CreateICmpULT(val21, builder.getInt32(-499));
    Value *val23 = builder.CreateOr(val20, val22);
    builder.CreateCondBr(val23, BB24, BB39);
    builder.SetInsertPoint(BB24);
    Value *val25 = builder.CreateCall(simRandFunc);
    Value *val26 = builder.CreateSRem(val25, builder.getInt32(700));
    Value *val27 = builder.CreateTrunc(val26, Type::getInt16Ty(context));
    Value *val28 = builder.CreateSDiv(val27, builder.getInt32(3));
    Value *val29 = builder.CreateSExt(val28, Type::getInt32Ty(context));
    Value *val30 = builder.CreateMul(val29, builder.getInt32(100));
    Value *val31 = builder.CreateAdd(val30, builder.getInt32(35000));
    Value *val32 = builder.CreateCall(simRandFunc);
    Value *val33 = builder.CreateSRem(val32, builder.getInt32(500));
    Value *val34 = builder.CreateTrunc(val33, Type::getInt16Ty(context));
    Value *val35 = builder.CreateSDiv(val34, builder.getInt32(3));
    Value *val36 = builder.CreateSExt(val35, Type::getInt32Ty(context));
    Value *val37 = builder.CreateMul(val36, builder.getInt32(100));
    Value *val38 = builder.CreateAdd(val37, builder.getInt32(25000));
    builder.CreateBr(BB39);
    builder.SetInsertPoint(BB39);
    PHINode *val40 = builder.CreatePHI(builder.getInt32Ty(), 2);
  // unknown cmd: %40 = phi i32 [ %14, %11 ], [ %31, %24 ]
    PHINode *val41 = builder.CreatePHI(builder.getInt32Ty(), 2);
  // unknown cmd: %41 = phi i32 [ %16, %11 ], [ %38, %24 ]
    Value *val42 = builder.CreateMul(val40, builder.getInt32(250));
    Value *val43 = builder.CreateMul(val41, val40);
    Value *val44 = builder.CreateSDiv(val43, builder.getInt32(100));
    Value *val45 = builder.CreateSub(val42, val44);
    Value *val46 = builder.CreateSDiv(val45, builder.getInt32(10000));
    Value *val47 = builder.CreateMul(val41, builder.getInt32(-350));
    Value *val48 = builder.CreateAdd(val44, val47);
    Value *val49 = builder.CreateSDiv(val48, builder.getInt32(10000));
    builder.CreateCondBr(val8, BB50, BB78);
    builder.SetInsertPoint(BB50);
    Value *val51 = builder.CreateSDiv(val40, builder.getInt32(100));
    Value *val52 = builder.CreateSDiv(val41, builder.getInt32(100));
    Value *val53 = builder.CreateSDiv(val45, builder.getInt32(200000));
    Value *val54 = builder.CreateSDiv(val48, builder.getInt32(200000));
    Value *val55 = builder.CreateCall(llvmAbsI32Func, {val46, builder.getInt1(true)});
    Value *val56 = builder.CreateCall(llvmAbsI32Func, {val49, builder.getInt1(true)});
    Value *val57 = builder.CreateAdd(val56, val55);
    Value *val58 = builder.CreateShl(val57, builder.getInt32(16));
    Value *val59 = builder.CreateOr(val58, builder.getInt32(-16776961));
    builder.CreateBr(BB60);
    builder.SetInsertPoint(BB60);
    PHINode *val61 = builder.CreatePHI(builder.getInt32Ty(), 2);
// unknown cmd: %61 = phi i32 [ 0, %50 ], [ %75, %74 ]
    Value *val62 = builder.CreateMul(val61, val53);
    Value *val63 = builder.CreateSDiv(val62, builder.getInt32(10));
    Value *val64 = builder.CreateAdd(val63, val51);
    Value *val65 = builder.CreateMul(val61, val54);
    Value *val66 = builder.CreateSDiv(val65, builder.getInt32(10));
    Value *val67 = builder.CreateAdd(val66, val52);
    Value *val68 = builder.CreateAdd(val64, builder.getInt32(-700));
    Value *val69 = builder.CreateICmpULT(val68, builder.getInt32(-699));
    Value *val70 = builder.CreateAdd(val67, builder.getInt32(-500));
    Value *val71 = builder.CreateICmpULT(val70, builder.getInt32(-499));
    Value *val72 = builder.CreateOr(val69, val71);
    builder.CreateCondBr(val72, BB74, BB73);
    builder.SetInsertPoint(BB73);
    builder.CreateCall(simPutPixelFunc, {val64, val67, val59});
    builder.CreateBr(BB74);
    builder.SetInsertPoint(BB74);
    Value *val75 = builder.CreateAdd(val61, builder.getInt32(1));
    Value *val76 = builder.CreateICmpEQ(val75, builder.getInt32(10));
    builder.CreateCondBr(val76, BB77, BB60);
    builder.SetInsertPoint(BB77);
    builder.CreateCall(simFlushFunc);
    builder.CreateBr(BB78);
    builder.SetInsertPoint(BB78);
    Value *val79 = builder.CreateAdd(val46, val40);
    Value *val80 = builder.CreateAdd(val49, val41);
    builder.CreateStore(val79, val13);
    builder.CreateStore(val80, val15);
    Value *val81 = builder.CreateAdd(val12, builder.getInt32(1));
    Value *val82 = builder.CreateICmpEQ(val81, builder.getInt32(10));
    builder.CreateCondBr(val82, BB9, BB11);
    // PHI NODES CONNECTIONS GO HERE
// unknown cmd: %6 = phi i32 [ 0, %0 ], [ %10, %9 ]
    val6->addIncoming(builder.getInt32(0), BB0);
    val6->addIncoming(val10, BB9);
 // unknown cmd: %12 = phi i64 [ 0, %5 ], [ %81, %78 ]
    val12->addIncoming(builder.getInt32(0), BB5);
    val12->addIncoming(val81, BB78);
 // unknown cmd: %40 = phi i32 [ %14, %11 ], [ %31, %24 ]
    val40->addIncoming(val14, BB11);
    val40->addIncoming(val31, BB24);
 // unknown cmd: %41 = phi i32 [ %16, %11 ], [ %38, %24 ]
    val41->addIncoming(val16, BB11);
    val41->addIncoming(val38, BB24);
 // unknown cmd: %61 = phi i32 [ 0, %50 ], [ %75, %74 ]
    val61->addIncoming(builder.getInt32(0), BB50);
    val61->addIncoming(val75, BB74);

  }
  std::cout << "lastfunc\n";

  // ------------------------------------------------
  // My code ends here
  // ------------------------------------------------


  // Dump LLVM IR
  module->print(outs(), nullptr);
  std::cout << "dump\n";

  // Interpreter of LLVM IR
  outs() << "Running code...\n";
  InitializeNativeTarget();
  InitializeNativeTargetAsmPrinter();

  ExecutionEngine *ee = EngineBuilder(std::unique_ptr<Module>(module)).create();
  ee->InstallLazyFunctionCreator([&](const std::string &fnName) -> void * {
    if (fnName == "simPutPixel") {
      return reinterpret_cast<void *>(simPutPixel);
    }
    if (fnName == "simFlush") {
      return reinterpret_cast<void *>(simFlush);
    }
    return nullptr;
  });
  ee->finalizeObject();

  simInit();
  std::cout << "init2\n";

  ArrayRef<GenericValue> noargs;
  GenericValue v = ee->runFunction(appFunc, noargs);
  outs() << "Code was run.\n";

  simExit();
  return EXIT_SUCCESS;
}
