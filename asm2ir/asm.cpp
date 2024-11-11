#include "../graph/sim.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <sstream>
#include <cctype>

#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
using std::string_view;

using namespace llvm;

const int REG_FILE_SIZE = 128;
uint32_t REG_FILE[REG_FILE_SIZE];

bool ichar_equals(char a, char b) {
    return std::tolower(static_cast<unsigned char>(a)) ==
           std::tolower(static_cast<unsigned char>(b));
}

bool iequals(const std::string& a, const std::string& b) {
    return std::equal(a.begin(), a.end(), b.begin(), b.end(), ichar_equals);
}

std::vector<std::string> extract_words(const std::string& input) {
    std::istringstream stream(input);
    std::vector<std::string> words;
    std::string word;
    while (stream >> word)
        words.push_back(word);
    return words;
}

void print(int x) {
    printf("out: %d\n", x);
}

int main (int argc, char *argv[]) {
    if (argc != 2) {
        printf (
            "ERROR: wrong number of arguments\n"
            "You shold call \"asm *name*.casm\"!\n"
        );
        return 0;
    }

    const char *in_name = argv[1];

    std::ifstream f_in(in_name);
    std::string line;

    if (!f_in.is_open()) {
        std::cerr << "error openning file\n";
        return 1;
    }
    outs() << "start\n";

    // init llvm
    LLVMContext context;
    // ; ModuleID = 'top'
    // source_filename = "top"
    Module *module = new Module("top", context);
    IRBuilder<> builder(context);
    Type *voidType = Type::getVoidTy(context);
    Type *int32Type = Type::getInt32Ty(context);

    //[32 x i32] regFile = {0, 0, 0, 0}
    ArrayType *regFileType = ArrayType::get(int32Type, REG_FILE_SIZE);
    GlobalVariable *regFile = new GlobalVariable(
        *module, regFileType, false, GlobalValue::PrivateLinkage, 0, "regFile");
    regFile->setInitializer(ConstantAggregateZero::get(regFileType));

    // declare void @main()
    FunctionType *funcType = FunctionType::get(builder.getVoidTy(), false);
    Function *mainFunc =
    Function::Create(funcType, Function::ExternalLinkage, "main", module);

    // declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef)
    ArrayRef<Type *> simPutPixelParamTypes = {int32Type, int32Type, int32Type};
    FunctionType *simPutPixelType =
      FunctionType::get(voidType, simPutPixelParamTypes, false);
    FunctionCallee simPutPixelFunc =
      module->getOrInsertFunction("simPutPixel", simPutPixelType);

    // declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef)
    ArrayRef<Type *> printParams = {int32Type};
    FunctionType *printType =
      FunctionType::get(voidType, printParams, false);
    FunctionCallee printFunc =
      module->getOrInsertFunction("print", printType);

    // declare void @simFlush(...)
    FunctionType *simFlushType = FunctionType::get(voidType, false);
    FunctionCallee simFlushFunc =
      module->getOrInsertFunction("simFlush", simFlushType);

    FunctionType *randFuncType = FunctionType::get(builder.getInt32Ty(), false);
    Function *randFunc =
        Function::Create(randFuncType, Function::ExternalLinkage, "rand", module);


    outs() << "bbs\n";

    // init basic blocks
    std::unordered_map<std::string, BasicBlock *> BBMap;
    while (std::getline(f_in, line)) {
        outs() << "before ext\n";
        const auto &words = extract_words(line);
        if (words.size() == 0)
            continue;
        outs() << "after ext " << words[0] << '\n';
        if (words[0][0] == ':') {
            outs() << words[0] << '\n';
            BBMap[words[0]] = BasicBlock::Create(context, words[0], mainFunc);
        }
        outs() << "after insrt\n";
    }

    outs() << "after bbs\n";
    // Reset cursor position to the beginning
    f_in.clear(); // Clear EOF flag
    f_in.seekg(0, std::ios::beg);

    bool last_was_br = false;
    // main parse
    while (std::getline(f_in, line)) {
        outs() << "line\n";
        if (line[0] == '#')
            continue;
        const auto &words = extract_words(line);
        if (words.size() == 0)
            continue;
        if (words[0][0] == ':') {
            if (builder.GetInsertBlock() and !last_was_br) {
                builder.CreateBr(BBMap[words[0]]);
                outs() << "\tbranch to " << words[0] << "\n";
            }
            outs() << "BB " << words[0] << "\n";
            builder.SetInsertPoint(BBMap[words[0]]);
            continue;
        }
        outs() << "not a word!\n";
        last_was_br = false;

        // pair of <ptr, value> when possible
        std::vector<std::pair<Value*, Value*>> args;
        for (int iarg=1; iarg<words.size(); iarg++) {
            std::pair<Value*, Value*> arg;
            const auto &word = words[iarg];
            if (word[0] == 'r') {
                outs() << "reg " << std::stoi(std::string(word.begin()+1, word.end())) << '\n';
                arg.first = builder.CreateConstGEP2_32(regFileType, regFile, 0,
                                                 std::stoi(std::string(word.begin()+1, word.end())));
                arg.second = builder.CreateLoad(int32Type, arg.first);
            } else if (word[0] == ':') {
                arg.first = BBMap[word];
            } else { // supposed to be int
                outs() << "number " << std::stoll(word) << '\n';
                arg.second = builder.getInt32(std::stoll(word));
            }
            args.push_back(arg);
        }
        outs() << args.size() << '\n';

        #define BINOP(NAME, CMD) } else if (iequals(#NAME, words[0])) { \
            outs() << #NAME "\n";\
            builder.CreateStore(builder.Create##CMD(\
                                args[1].second, args[2].second), args[0].first);

        if (iequals("MOV", words[0])) {
            outs() << "mov\n";
            builder.CreateStore(args[1].second, args[0].first);
        BINOP(ADD, Add)
        BINOP(SUB, Sub)
        BINOP(MUL, Mul)
        BINOP(DIV, SDiv)
        BINOP(SHL, Shl)
        BINOP(OR, Or)
        BINOP(AND, And)
        BINOP(LE, ICmpULE)
        BINOP(LT, ICmpULT)
        BINOP(GE, ICmpUGE)
        BINOP(GT, ICmpUGT)
        BINOP(EQ, ICmpEQ)
        BINOP(NE, ICmpNE)
        BINOP(SLE, ICmpSLE)
        BINOP(SLT, ICmpSLT)
        BINOP(SGE, ICmpSGE)
        BINOP(SGT, ICmpSGT)
        BINOP(MOD, URem)
        } else if (iequals("JMP", words[0])) {
            builder.CreateBr(BBMap[words[1]]);
            last_was_br = true;
            // builder.SetInsertPoint(BBMap[words[3]]);
        } else if (iequals("BRC", words[0])) {
            builder.CreateCondBr(builder.CreateTrunc(
                args[0].second, builder.getInt1Ty()), BBMap[words[2]], BBMap[words[3]]
            );
            last_was_br = true;
//            builder.SetInsertPoint(BBMap[words[3]]);
        } else if (iequals("RET", words[0])) {
            builder.CreateRetVoid();
        } else if (iequals("PRINT", words[0])) {
            outs() << "print\n";
            Value *callargs[] = {args[0].second};
            builder.CreateCall(printFunc, callargs);
        } else if (iequals("RAND", words[0])) {
            outs() << "rand\n";
            Value *randRes = builder.CreateCall(randFunc);
            builder.CreateStore(randRes, args[0].first);
        } else if (iequals("FLUSH", words[0])) {
            builder.CreateCall(simFlushFunc);
        } else if (iequals("PUTPIX", words[0])) {
            Value *callargs[] = {args[0].second, args[1].second, args[2].second};
            builder.CreateCall(simPutPixelFunc, callargs);
        } else if (iequals("MULDIV", words[0])) {
            builder.CreateStore(builder.CreateSDiv(
                builder.CreateMul(args[1].second, args[2].second), args[3].second), 
                args[0].first
            );
        } else {
            outs() << "unknown instr " << words[0] << '\n';
        }
    }

    outs() << "\n#[LLVM IR]:n";
    module->print(outs(), nullptr);
    outs() << "\n";
    bool verif = verifyFunction(*mainFunc, &outs());
    outs() << "[VERIFICATION] " << (!verif ? "OK\n\n" : "FAIL\n\n");
  
    outs() << "\n#[Running code]\n";
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();
  
    ExecutionEngine *ee = EngineBuilder(std::unique_ptr<Module>(module)).create();
    ee->InstallLazyFunctionCreator([=](const std::string &fnName) -> void * {
        if (fnName == "print") {
            return reinterpret_cast<void *>(print);
        } else if (fnName == "simFlush") {
          return reinterpret_cast<void *>(simFlush);
        } else if (fnName == "simPutPixel") {
          return reinterpret_cast<void *>(simPutPixel);
        } else if (fnName == "rand") {
          return reinterpret_cast<void *>(simRand);
        }
        return nullptr;
    });

    ee->finalizeObject();
    simInit();

    ArrayRef<GenericValue> noargs;
    ee->runFunction(mainFunc, noargs);
    outs() << "#[Code was run]\n";

    simExit();
    return 0;
}


