; ModuleID = 'app.c'
source_filename = "app.c"

declare void @simPutPixel(i32, i32, i32)

declare void @simFlush()

define i32 @app() {
  %array = alloca [10 x i32], align 4
  %array1 = alloca [10 x i32], align 4
  call void @llvm.lifetime.start.p0i8(i64 40, ptr %array)
  call void @llvm.memset.p0i8.i64(ptr %array, i8 0, i64 40, i1 false)
  call void @llvm.lifetime.start.p0i8(i64 40, ptr %array1)
  call void @llvm.memset.p0i8.i64(ptr %array1, i8 0, i64 40, i1 false)
  br label %1

1:                                                ; preds = %5, %0
  %2 = phi i32 [ 0, %0 ], [ %6, %5 ]
  %3 = urem i32 %2, 5
  %4 = icmp eq i32 %3, 0
  br label %7

5:                                                ; preds = %74
  %6 = add i32 %2, 1
  br label %1

7:                                                ; preds = %74, %1
  %8 = phi i64 [ 0, %1 ], [ %77, %74 ]
  %9 = getelementptr inbounds [10 x i32], ptr %array, i64 0, i64 %8
  %10 = load i32, ptr %9, align 4
  %11 = getelementptr inbounds [10 x i32], ptr %array1, i64 0, i64 %8
  %12 = load i32, ptr %11, align 4
  %13 = sdiv i32 %10, 100
  %14 = sdiv i32 %12, 100
  %15 = add i32 %13, -700
  %16 = icmp ult i32 %15, -699
  %17 = add i32 %14, -500
  %18 = icmp ult i32 %17, -499
  %19 = or i1 %16, %18
  br i1 %19, label %20, label %35

20:                                               ; preds = %7
  %21 = call i32 @simRand()
  %22 = srem i32 %21, 700
  %23 = trunc i32 %22 to i16
  %24 = sdiv i16 %23, 3
  %25 = sext i16 %24 to i32
  %26 = mul i32 %25, 100
  %27 = add i32 %26, 35000
  %28 = call i32 @simRand()
  %29 = srem i32 %28, 500
  %30 = trunc i32 %29 to i16
  %31 = sdiv i16 %30, 3
  %32 = sext i16 %31 to i32
  %33 = mul i32 %32, 100
  %34 = add i32 %33, 25000
  br label %35

35:                                               ; preds = %20, %7
  %36 = phi i32 [ %10, %7 ], [ %27, %20 ]
  %37 = phi i32 [ %12, %7 ], [ %34, %20 ]
  %38 = mul i32 %36, 250
  %39 = mul i32 %37, %36
  %40 = sdiv i32 %39, 100
  %41 = sub i32 %38, %40
  %42 = sdiv i32 %41, 10000
  %43 = mul i32 %37, -350
  %44 = add i32 %40, %43
  %45 = sdiv i32 %44, 10000
  br i1 %4, label %46, label %74

46:                                               ; preds = %35
  %47 = sdiv i32 %36, 100
  %48 = sdiv i32 %37, 100
  %49 = sdiv i32 %41, 200000
  %50 = sdiv i32 %44, 200000
  %51 = call i32 @llvm.abs.i32(i32 %42, i1 true)
  %52 = call i32 @llvm.abs.i32(i32 %45, i1 true)
  %53 = add i32 %52, %51
  %54 = shl i32 %53, 16
  %55 = or i32 %54, -16776961
  br label %56

56:                                               ; preds = %70, %46
  %57 = phi i32 [ 0, %46 ], [ %71, %70 ]
  %58 = mul i32 %57, %49
  %59 = sdiv i32 %58, 10
  %60 = add i32 %59, %47
  %61 = mul i32 %57, %50
  %62 = sdiv i32 %61, 10
  %63 = add i32 %62, %48
  %64 = add i32 %60, -700
  %65 = icmp ult i32 %64, -699
  %66 = add i32 %63, -500
  %67 = icmp ult i32 %66, -499
  %68 = or i1 %65, %67
  br i1 %68, label %70, label %69

69:                                               ; preds = %56
  call void @simPutPixel(i32 %60, i32 %63, i32 %55)
  br label %70

70:                                               ; preds = %69, %56
  %71 = add i32 %57, 1
  %72 = icmp eq i32 %71, 10
  br i1 %72, label %73, label %56

73:                                               ; preds = %70
  call void @simFlush()
  br label %74

74:                                               ; preds = %73, %35
  %75 = add i32 %42, %36
  %76 = add i32 %45, %37
  store i32 %75, ptr %9, align 4
  store i32 %76, ptr %11, align 4
  %77 = add i64 %8, 1
  %78 = icmp eq i64 %77, 10
  br i1 %78, label %5, label %7
}

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare i32 @llvm.abs.i32(i32, i1 immarg) #0

; Function Attrs: nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.start.p0i8(i64 immarg, ptr nocapture) #1

; Function Attrs: nocallback nofree nounwind willreturn memory(argmem: write)
declare void @llvm.memset.p0i8.i64(ptr nocapture writeonly, i8, i64, i1 immarg) #2

declare i32 @simRand()

define i32 @is_good_pnt(i32 %0, i32 %1) {
  %3 = add i32 %0, -1
  %4 = icmp ult i32 %3, 699
  %5 = add i32 %1, -1
  %6 = icmp ult i32 %5, 499
  %7 = and i1 %4, %6
  %8 = zext i1 %7 to i32
  ret i32 %8
}

define void @drawLine(i32 %0, i32 %1, i32 %2, i32 %3, i32 %4) {
  %6 = shl i32 %4, 16
  %7 = add i32 %6, -16776961
  br label %9

8:                                                ; preds = %23
  ret void

9:                                                ; preds = %23, %5
  %10 = phi i32 [ 0, %5 ], [ %24, %23 ]
  %11 = mul i32 %10, %2
  %12 = sdiv i32 %11, 10
  %13 = add i32 %12, %0
  %14 = mul i32 %10, %3
  %15 = sdiv i32 %14, 10
  %16 = add i32 %15, %1
  %17 = add i32 %13, -700
  %18 = icmp ult i32 %17, -699
  %19 = add i32 %16, -500
  %20 = icmp ult i32 %19, -499
  %21 = or i1 %18, %20
  br i1 %21, label %23, label %22

22:                                               ; preds = %9
  call void @simPutPixel(i32 %13, i32 %16, i32 %7)
  br label %23

23:                                               ; preds = %22, %9
  %24 = add i32 %10, 1
  %25 = icmp eq i32 %24, 10
  br i1 %25, label %8, label %9
}

define i32 @getAbsVelocity(i32 %0, i32 %1) {
  %3 = call i32 @llvm.abs.i32(i32 %0, i1 true)
  %4 = call i32 @llvm.abs.i32(i32 %1, i1 true)
  %5 = add i32 %4, %3
  %6 = and i32 %5, 255
  ret i32 %6
}

attributes #0 = { nocallback nofree nosync nounwind speculatable willreturn memory(none) }
attributes #1 = { nocallback nofree nosync nounwind willreturn memory(argmem: readwrite) }
attributes #2 = { nocallback nofree nounwind willreturn memory(argmem: write) }
