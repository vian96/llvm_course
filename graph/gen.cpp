//  define dso_local i32 @is_good_pnt(i32 noundef %0, i32 noundef %1) local_unnamed_addr #0 {
FunctionType *is_good_pntType = ...
Function *is_good_pntFunc = ...
{
// BasicBlocks:
BasicBlock *BB0 = BasicBlock::Create(context, "", {fname}Func);
// MAIN CODE
unknown cmd: define dso_local i32 @is_good_pnt(i32 noundef %0, i32 noundef %1) local_unnamed_addr #0 {
Value *val3 = builder.CreateAdd(val0, builder.getInt32(-1));
Value *val4 = builder.CreateICmp{cmd.split()[1].upper()}(val3, builder.getInt32(699));
Value *val5 = builder.CreateAdd(val1, builder.getInt32(-1));
Value *val6 = builder.CreateICmp{cmd.split()[1].upper()}(val5, builder.getInt32(499));
Value *val7 = builder.CreateAnd(val4, val6);
unknown cmd: %8 = zext i1 %7 to i32
builder.CreateRet(..)
}
//  define dso_local void @drawLine(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, i32 noundef %4) local_unnamed_addr #1 {
FunctionType *drawLineType = ...
Function *drawLineFunc = ...
{
// BasicBlocks:
BasicBlock *BB0 = BasicBlock::Create(context, "", {fname}Func);
BasicBlock *BB8 = BasicBlock::Create(context, "", drawLineFunc);
BasicBlock *BB9 = BasicBlock::Create(context, "", drawLineFunc);
BasicBlock *BB22 = BasicBlock::Create(context, "", drawLineFunc);
BasicBlock *BB23 = BasicBlock::Create(context, "", drawLineFunc);
// MAIN CODE
unknown cmd: define dso_local void @drawLine(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, i32 noundef %4) local_unnamed_addr #1 {
Value *val6 = builder.CreateShl(val4, builder.getInt32(16));
Value *val7 = builder.CreateAdd(val6, builder.getInt32(-16776961));
builder.CreateBr(BB9);
builder.SetInsertPoint(BB8);
builder.CreateRetVoid();
builder.SetInsertPoint(BB9);
unknown cmd: %10 = phi i32 [ 0, %5 ], [ %24, %23 ]
Value *val11 = builder.CreateMul(val10, val2);
Value *val12 = builder.CreateSDiv(val11, builder.getInt32(10));
Value *val13 = builder.CreateAdd(val12, val0);
Value *val14 = builder.CreateMul(val10, val3);
Value *val15 = builder.CreateSDiv(val14, builder.getInt32(10));
Value *val16 = builder.CreateAdd(val15, val1);
Value *val17 = builder.CreateAdd(val13, builder.getInt32(-700));
Value *val18 = builder.CreateICmp{cmd.split()[1].upper()}(val17, builder.getInt32(-699));
Value *val19 = builder.CreateAdd(val16, builder.getInt32(-500));
Value *val20 = builder.CreateICmp{cmd.split()[1].upper()}(val19, builder.getInt32(-499));
Value *val21 = builder.CreateOr(val18, val20);
unknown cmd: br i1 %21, label %23, label %22
builder.SetInsertPoint(BB22);
unknown cmd: tail call void @simPutPixel(i32 noundef %13, i32 noundef %16, i32 noundef %7) #7
builder.CreateBr(BB23);
builder.SetInsertPoint(BB23);
Value *val24 = builder.CreateAdd(val10, builder.getInt32(1));
Value *val25 = builder.CreateICmp{cmd.split()[1].upper()}(val24, builder.getInt32(10));
unknown cmd: br i1 %25, label %8, label %9, !llvm.loop !5
}
//  declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #2
FunctionType *llvmType = ...
Function *llvmFunc = ...
{
// BasicBlocks:
BasicBlock *BB0 = BasicBlock::Create(context, "", {fname}Func);
// MAIN CODE
unknown cmd: declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #2
unknown cmd: declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #3
}
//  define dso_local i32 @getAbsVelocity(i32 noundef %0, i32 noundef %1) local_unnamed_addr #0 {
FunctionType *getAbsVelocityType = ...
Function *getAbsVelocityFunc = ...
{
// BasicBlocks:
BasicBlock *BB0 = BasicBlock::Create(context, "", {fname}Func);
// MAIN CODE
unknown cmd: define dso_local i32 @getAbsVelocity(i32 noundef %0, i32 noundef %1) local_unnamed_addr #0 {
unknown cmd: %3 = tail call i32 @llvm.abs.i32(i32 %0, i1 true)
unknown cmd: %4 = tail call i32 @llvm.abs.i32(i32 %1, i1 true)
Value *val5 = builder.CreateAdd(val4, val3);
Value *val6 = builder.CreateAnd(val5, builder.getInt32(255));
builder.CreateRet(..)
}
//  define dso_local void @app() local_unnamed_addr #4 {
FunctionType *appType = ...
Function *appFunc = ...
{
// BasicBlocks:
BasicBlock *BB0 = BasicBlock::Create(context, "", {fname}Func);
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
unknown cmd: define dso_local void @app() local_unnamed_addr #4 {
unknown cmd: %1 = alloca [10 x i32], align 16
unknown cmd: %2 = alloca [10 x i32], align 16
unknown cmd: %3 = bitcast [10 x i32]* %1 to i8*
unknown cmd: call void @llvm.lifetime.start.p0i8(i64 40, i8* nonnull %3) #7
unknown cmd: call void @llvm.memset.p0i8.i64(i8* noundef nonnull align 16 dereferenceable(40) %3, i8 0, i64 40, i1 false)
unknown cmd: %4 = bitcast [10 x i32]* %2 to i8*
unknown cmd: call void @llvm.lifetime.start.p0i8(i64 40, i8* nonnull %4) #7
unknown cmd: call void @llvm.memset.p0i8.i64(i8* noundef nonnull align 16 dereferenceable(40) %4, i8 0, i64 40, i1 false)
builder.CreateBr(BB5);
builder.SetInsertPoint(BB5);
unknown cmd: %6 = phi i32 [ 0, %0 ], [ %10, %9 ]
Value *val7 = builder.CreateURem(val6, builder.getInt32(5));
Value *val8 = builder.CreateICmp{cmd.split()[1].upper()}(val7, builder.getInt32(0));
builder.CreateBr(BB11);
builder.SetInsertPoint(BB9);
Value *val10 = builder.CreateAdd(val6, builder.getInt32(1));
builder.CreateBr(BB5);
builder.SetInsertPoint(BB11);
unknown cmd: %12 = phi i64 [ 0, %5 ], [ %81, %78 ]
unknown cmd: %13 = getelementptr inbounds [10 x i32], [10 x i32]* %1, i64 0, i64 %12
unknown cmd: %14 = load i32, i32* %13, align 4, !tbaa !7
unknown cmd: %15 = getelementptr inbounds [10 x i32], [10 x i32]* %2, i64 0, i64 %12
unknown cmd: %16 = load i32, i32* %15, align 4, !tbaa !7
Value *val17 = builder.CreateSDiv(val14, builder.getInt32(100));
Value *val18 = builder.CreateSDiv(val16, builder.getInt32(100));
Value *val19 = builder.CreateAdd(val17, builder.getInt32(-700));
Value *val20 = builder.CreateICmp{cmd.split()[1].upper()}(val19, builder.getInt32(-699));
Value *val21 = builder.CreateAdd(val18, builder.getInt32(-500));
Value *val22 = builder.CreateICmp{cmd.split()[1].upper()}(val21, builder.getInt32(-499));
Value *val23 = builder.CreateOr(val20, val22);
unknown cmd: br i1 %23, label %24, label %39
builder.SetInsertPoint(BB24);
unknown cmd: %25 = tail call i32 (...) @simRand() #7
Value *val26 = builder.CreateSRem(val25, builder.getInt32(700));
unknown cmd: %27 = trunc i32 %26 to i16
Value *val28 = builder.CreateSDiv(val27, builder.getInt32(3));
unknown cmd: %29 = sext i16 %28 to i32
Value *val30 = builder.CreateMul(val29, builder.getInt32(100));
Value *val31 = builder.CreateAdd(val30, builder.getInt32(35000));
unknown cmd: %32 = tail call i32 (...) @simRand() #7
Value *val33 = builder.CreateSRem(val32, builder.getInt32(500));
unknown cmd: %34 = trunc i32 %33 to i16
Value *val35 = builder.CreateSDiv(val34, builder.getInt32(3));
unknown cmd: %36 = sext i16 %35 to i32
Value *val37 = builder.CreateMul(val36, builder.getInt32(100));
Value *val38 = builder.CreateAdd(val37, builder.getInt32(25000));
builder.CreateBr(BB39);
builder.SetInsertPoint(BB39);
unknown cmd: %40 = phi i32 [ %14, %11 ], [ %31, %24 ]
unknown cmd: %41 = phi i32 [ %16, %11 ], [ %38, %24 ]
Value *val42 = builder.CreateMul(val40, builder.getInt32(250));
Value *val43 = builder.CreateMul(val41, val40);
Value *val44 = builder.CreateSDiv(val43, builder.getInt32(100));
Value *val45 = builder.CreateSub(val42, val44);
Value *val46 = builder.CreateSDiv(val45, builder.getInt32(10000));
Value *val47 = builder.CreateMul(val41, builder.getInt32(-350));
Value *val48 = builder.CreateAdd(val44, val47);
Value *val49 = builder.CreateSDiv(val48, builder.getInt32(10000));
unknown cmd: br i1 %8, label %50, label %78
builder.SetInsertPoint(BB50);
Value *val51 = builder.CreateSDiv(val40, builder.getInt32(100));
Value *val52 = builder.CreateSDiv(val41, builder.getInt32(100));
Value *val53 = builder.CreateSDiv(val45, builder.getInt32(200000));
Value *val54 = builder.CreateSDiv(val48, builder.getInt32(200000));
unknown cmd: %55 = tail call i32 @llvm.abs.i32(i32 %46, i1 true) #7
unknown cmd: %56 = tail call i32 @llvm.abs.i32(i32 %49, i1 true) #7
Value *val57 = builder.CreateAdd(val56, val55);
Value *val58 = builder.CreateShl(val57, builder.getInt32(16));
Value *val59 = builder.CreateOr(val58, builder.getInt32(-16776961));
builder.CreateBr(BB60);
builder.SetInsertPoint(BB60);
unknown cmd: %61 = phi i32 [ 0, %50 ], [ %75, %74 ]
Value *val62 = builder.CreateMul(val61, val53);
Value *val63 = builder.CreateSDiv(val62, builder.getInt32(10));
Value *val64 = builder.CreateAdd(val63, val51);
Value *val65 = builder.CreateMul(val61, val54);
Value *val66 = builder.CreateSDiv(val65, builder.getInt32(10));
Value *val67 = builder.CreateAdd(val66, val52);
Value *val68 = builder.CreateAdd(val64, builder.getInt32(-700));
Value *val69 = builder.CreateICmp{cmd.split()[1].upper()}(val68, builder.getInt32(-699));
Value *val70 = builder.CreateAdd(val67, builder.getInt32(-500));
Value *val71 = builder.CreateICmp{cmd.split()[1].upper()}(val70, builder.getInt32(-499));
Value *val72 = builder.CreateOr(val69, val71);
unknown cmd: br i1 %72, label %74, label %73
builder.SetInsertPoint(BB73);
unknown cmd: tail call void @simPutPixel(i32 noundef %64, i32 noundef %67, i32 noundef %59) #7
builder.CreateBr(BB74);
builder.SetInsertPoint(BB74);
Value *val75 = builder.CreateAdd(val61, builder.getInt32(1));
Value *val76 = builder.CreateICmp{cmd.split()[1].upper()}(val75, builder.getInt32(10));
unknown cmd: br i1 %76, label %77, label %60, !llvm.loop !5
builder.SetInsertPoint(BB77);
unknown cmd: tail call void (...) @simFlush() #7
builder.CreateBr(BB78);
builder.SetInsertPoint(BB78);
Value *val79 = builder.CreateAdd(val46, val40);
Value *val80 = builder.CreateAdd(val49, val41);
unknown cmd: store i32 %79, i32* %13, align 4, !tbaa !7
unknown cmd: store i32 %80, i32* %15, align 4, !tbaa !7
Value *val81 = builder.CreateAdd(val12, builder.getInt32(1));
Value *val82 = builder.CreateICmp{cmd.split()[1].upper()}(val81, builder.getInt32(10));
unknown cmd: br i1 %82, label %9, label %11, !llvm.loop !11
}
//  declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #5
FunctionType *llvmType = ...
Function *llvmFunc = ...
{
// BasicBlocks:
BasicBlock *BB0 = BasicBlock::Create(context, "", {fname}Func);
// MAIN CODE
unknown cmd: declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #5
unknown cmd: declare i32 @simRand(...) local_unnamed_addr #3
unknown cmd: declare void @simFlush(...) local_unnamed_addr #3
}
