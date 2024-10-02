; ModuleID = 'app.c'
source_filename = "app.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @is_good_pnt(i32 noundef %0, i32 noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  store i32 %1, i32* %4, align 4
  %5 = load i32, i32* %3, align 4
  %6 = icmp sle i32 %5, 0
  br i1 %6, label %16, label %7

7:                                                ; preds = %2
  %8 = load i32, i32* %3, align 4
  %9 = icmp sge i32 %8, 700
  br i1 %9, label %16, label %10

10:                                               ; preds = %7
  %11 = load i32, i32* %4, align 4
  %12 = icmp sle i32 %11, 0
  br i1 %12, label %16, label %13

13:                                               ; preds = %10
  %14 = load i32, i32* %4, align 4
  %15 = icmp sge i32 %14, 500
  br label %16

16:                                               ; preds = %13, %10, %7, %2
  %17 = phi i1 [ true, %10 ], [ true, %7 ], [ true, %2 ], [ %15, %13 ]
  %18 = xor i1 %17, true
  %19 = zext i1 %18 to i32
  ret i32 %19
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @drawLine(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, i32 noundef %4) #0 {
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  %13 = alloca i32, align 4
  store i32 %0, i32* %6, align 4
  store i32 %1, i32* %7, align 4
  store i32 %2, i32* %8, align 4
  store i32 %3, i32* %9, align 4
  store i32 %4, i32* %10, align 4
  store i32 0, i32* %11, align 4
  br label %14

14:                                               ; preds = %41, %5
  %15 = load i32, i32* %11, align 4
  %16 = icmp slt i32 %15, 10
  br i1 %16, label %17, label %44

17:                                               ; preds = %14
  %18 = load i32, i32* %6, align 4
  %19 = load i32, i32* %8, align 4
  %20 = load i32, i32* %11, align 4
  %21 = mul nsw i32 %19, %20
  %22 = sdiv i32 %21, 10
  %23 = add nsw i32 %18, %22
  store i32 %23, i32* %12, align 4
  %24 = load i32, i32* %7, align 4
  %25 = load i32, i32* %9, align 4
  %26 = load i32, i32* %11, align 4
  %27 = mul nsw i32 %25, %26
  %28 = sdiv i32 %27, 10
  %29 = add nsw i32 %24, %28
  store i32 %29, i32* %13, align 4
  %30 = load i32, i32* %12, align 4
  %31 = load i32, i32* %13, align 4
  %32 = call i32 @is_good_pnt(i32 noundef %30, i32 noundef %31)
  %33 = icmp ne i32 %32, 0
  br i1 %33, label %34, label %40

34:                                               ; preds = %17
  %35 = load i32, i32* %12, align 4
  %36 = load i32, i32* %13, align 4
  %37 = load i32, i32* %10, align 4
  %38 = shl i32 %37, 16
  %39 = add i32 -16776961, %38
  call void @simPutPixel(i32 noundef %35, i32 noundef %36, i32 noundef %39)
  br label %40

40:                                               ; preds = %34, %17
  br label %41

41:                                               ; preds = %40
  %42 = load i32, i32* %11, align 4
  %43 = add nsw i32 %42, 1
  store i32 %43, i32* %11, align 4
  br label %14, !llvm.loop !6

44:                                               ; preds = %14
  ret void
}

declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @getAbsVelocity(i32 noundef %0, i32 noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  store i32 %1, i32* %4, align 4
  %5 = load i32, i32* %3, align 4
  %6 = icmp slt i32 %5, 0
  br i1 %6, label %7, label %10

7:                                                ; preds = %2
  %8 = load i32, i32* %3, align 4
  %9 = sub nsw i32 0, %8
  store i32 %9, i32* %3, align 4
  br label %10

10:                                               ; preds = %7, %2
  %11 = load i32, i32* %4, align 4
  %12 = icmp slt i32 %11, 0
  br i1 %12, label %13, label %16

13:                                               ; preds = %10
  %14 = load i32, i32* %4, align 4
  %15 = sub nsw i32 0, %14
  store i32 %15, i32* %4, align 4
  br label %16

16:                                               ; preds = %13, %10
  %17 = load i32, i32* %3, align 4
  %18 = load i32, i32* %4, align 4
  %19 = add nsw i32 %17, %18
  %20 = and i32 %19, 255
  ret i32 %20
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @app() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca [10 x i32], align 16
  %8 = alloca [10 x i32], align 16
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  %13 = alloca i32, align 4
  %14 = alloca i32, align 4
  store i32 100, i32* %1, align 4
  store i32 10000, i32* %2, align 4
  store i32 250, i32* %3, align 4
  store i32 1, i32* %4, align 4
  store i32 350, i32* %5, align 4
  store i32 1, i32* %6, align 4
  %15 = bitcast [10 x i32]* %7 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %15, i8 0, i64 40, i1 false)
  %16 = bitcast [10 x i32]* %8 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %16, i8 0, i64 40, i1 false)
  store i32 0, i32* %9, align 4
  br label %17

17:                                               ; preds = %105, %0
  br i1 true, label %18, label %108

18:                                               ; preds = %17
  store i32 0, i32* %10, align 4
  br label %19

19:                                               ; preds = %101, %18
  %20 = load i32, i32* %10, align 4
  %21 = icmp slt i32 %20, 10
  br i1 %21, label %22, label %104

22:                                               ; preds = %19
  %23 = load i32, i32* %10, align 4
  %24 = sext i32 %23 to i64
  %25 = getelementptr inbounds [10 x i32], [10 x i32]* %7, i64 0, i64 %24
  %26 = load i32, i32* %25, align 4
  store i32 %26, i32* %11, align 4
  %27 = load i32, i32* %10, align 4
  %28 = sext i32 %27 to i64
  %29 = getelementptr inbounds [10 x i32], [10 x i32]* %8, i64 0, i64 %28
  %30 = load i32, i32* %29, align 4
  store i32 %30, i32* %12, align 4
  %31 = load i32, i32* %11, align 4
  %32 = sdiv i32 %31, 100
  %33 = load i32, i32* %12, align 4
  %34 = sdiv i32 %33, 100
  %35 = call i32 @is_good_pnt(i32 noundef %32, i32 noundef %34)
  %36 = icmp ne i32 %35, 0
  br i1 %36, label %48, label %37

37:                                               ; preds = %22
  %38 = call i32 (...) @simRand()
  %39 = srem i32 %38, 700
  %40 = sdiv i32 %39, 3
  %41 = add nsw i32 %40, 350
  %42 = mul nsw i32 %41, 100
  store i32 %42, i32* %11, align 4
  %43 = call i32 (...) @simRand()
  %44 = srem i32 %43, 500
  %45 = sdiv i32 %44, 3
  %46 = add nsw i32 %45, 250
  %47 = mul nsw i32 %46, 100
  store i32 %47, i32* %12, align 4
  br label %48

48:                                               ; preds = %37, %22
  %49 = load i32, i32* %11, align 4
  %50 = mul nsw i32 250, %49
  %51 = load i32, i32* %11, align 4
  %52 = mul nsw i32 1, %51
  %53 = load i32, i32* %12, align 4
  %54 = mul nsw i32 %52, %53
  %55 = sdiv i32 %54, 100
  %56 = sub nsw i32 %50, %55
  store i32 %56, i32* %13, align 4
  %57 = load i32, i32* %13, align 4
  %58 = sdiv i32 %57, 10000
  store i32 %58, i32* %13, align 4
  %59 = load i32, i32* %12, align 4
  %60 = mul nsw i32 -350, %59
  %61 = load i32, i32* %11, align 4
  %62 = mul nsw i32 1, %61
  %63 = load i32, i32* %12, align 4
  %64 = mul nsw i32 %62, %63
  %65 = sdiv i32 %64, 100
  %66 = add nsw i32 %60, %65
  store i32 %66, i32* %14, align 4
  %67 = load i32, i32* %14, align 4
  %68 = sdiv i32 %67, 10000
  store i32 %68, i32* %14, align 4
  %69 = load i32, i32* %9, align 4
  %70 = srem i32 %69, 5
  %71 = icmp eq i32 %70, 0
  br i1 %71, label %72, label %86

72:                                               ; preds = %48
  %73 = load i32, i32* %11, align 4
  %74 = sdiv i32 %73, 100
  %75 = load i32, i32* %12, align 4
  %76 = sdiv i32 %75, 100
  %77 = load i32, i32* %13, align 4
  %78 = mul nsw i32 5, %77
  %79 = sdiv i32 %78, 100
  %80 = load i32, i32* %14, align 4
  %81 = mul nsw i32 5, %80
  %82 = sdiv i32 %81, 100
  %83 = load i32, i32* %13, align 4
  %84 = load i32, i32* %14, align 4
  %85 = call i32 @getAbsVelocity(i32 noundef %83, i32 noundef %84)
  call void @drawLine(i32 noundef %74, i32 noundef %76, i32 noundef %79, i32 noundef %82, i32 noundef %85)
  call void (...) @simFlush()
  br label %86

86:                                               ; preds = %72, %48
  %87 = load i32, i32* %13, align 4
  %88 = load i32, i32* %11, align 4
  %89 = add nsw i32 %88, %87
  store i32 %89, i32* %11, align 4
  %90 = load i32, i32* %14, align 4
  %91 = load i32, i32* %12, align 4
  %92 = add nsw i32 %91, %90
  store i32 %92, i32* %12, align 4
  %93 = load i32, i32* %11, align 4
  %94 = load i32, i32* %10, align 4
  %95 = sext i32 %94 to i64
  %96 = getelementptr inbounds [10 x i32], [10 x i32]* %7, i64 0, i64 %95
  store i32 %93, i32* %96, align 4
  %97 = load i32, i32* %12, align 4
  %98 = load i32, i32* %10, align 4
  %99 = sext i32 %98 to i64
  %100 = getelementptr inbounds [10 x i32], [10 x i32]* %8, i64 0, i64 %99
  store i32 %97, i32* %100, align 4
  br label %101

101:                                              ; preds = %86
  %102 = load i32, i32* %10, align 4
  %103 = add nsw i32 %102, 1
  store i32 %103, i32* %10, align 4
  br label %19, !llvm.loop !8

104:                                              ; preds = %19
  br label %105

105:                                              ; preds = %104
  %106 = load i32, i32* %9, align 4
  %107 = add nsw i32 %106, 1
  store i32 %107, i32* %9, align 4
  br label %17

108:                                              ; preds = %17
  ret void
}

; Function Attrs: argmemonly nofree nounwind willreturn writeonly
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #2

declare i32 @simRand(...) #1

declare void @simFlush(...) #1

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { argmemonly nofree nounwind willreturn writeonly }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
!8 = distinct !{!8, !7}
