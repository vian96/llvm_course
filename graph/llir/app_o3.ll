; ModuleID = 'app.c'
source_filename = "app.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: mustprogress nofree norecurse nosync nounwind readnone uwtable willreturn
define dso_local i32 @is_good_pnt(i32 noundef %0, i32 noundef %1) local_unnamed_addr #0 {
  %3 = add i32 %0, -1
  %4 = icmp ult i32 %3, 699
  %5 = add i32 %1, -1
  %6 = icmp ult i32 %5, 499
  %7 = and i1 %4, %6
  %8 = zext i1 %7 to i32
  ret i32 %8
}

; Function Attrs: nounwind uwtable
define dso_local void @drawLine(i32 noundef %0, i32 noundef %1, i32 noundef %2, i32 noundef %3, i32 noundef %4) local_unnamed_addr #1 {
  %6 = shl i32 %4, 16
  %7 = add i32 %6, -16776961
  %8 = add i32 %0, -700
  %9 = icmp ult i32 %8, -699
  %10 = add i32 %1, -500
  %11 = icmp ult i32 %10, -499
  %12 = or i1 %9, %11
  br i1 %12, label %14, label %13

13:                                               ; preds = %5
  tail call void @simPutPixel(i32 noundef %0, i32 noundef %1, i32 noundef %7) #7
  br label %14

14:                                               ; preds = %13, %5
  %15 = sdiv i32 %2, 10
  %16 = add nsw i32 %15, %0
  %17 = sdiv i32 %3, 10
  %18 = add nsw i32 %17, %1
  %19 = add i32 %16, -700
  %20 = icmp ult i32 %19, -699
  %21 = add i32 %18, -500
  %22 = icmp ult i32 %21, -499
  %23 = or i1 %20, %22
  br i1 %23, label %25, label %24

24:                                               ; preds = %14
  tail call void @simPutPixel(i32 noundef %16, i32 noundef %18, i32 noundef %7) #7
  br label %25

25:                                               ; preds = %24, %14
  %26 = sdiv i32 %2, 5
  %27 = add nsw i32 %26, %0
  %28 = sdiv i32 %3, 5
  %29 = add nsw i32 %28, %1
  %30 = add i32 %27, -700
  %31 = icmp ult i32 %30, -699
  %32 = add i32 %29, -500
  %33 = icmp ult i32 %32, -499
  %34 = or i1 %31, %33
  br i1 %34, label %36, label %35

35:                                               ; preds = %25
  tail call void @simPutPixel(i32 noundef %27, i32 noundef %29, i32 noundef %7) #7
  br label %36

36:                                               ; preds = %35, %25
  %37 = mul nsw i32 %2, 3
  %38 = sdiv i32 %37, 10
  %39 = add nsw i32 %38, %0
  %40 = mul nsw i32 %3, 3
  %41 = sdiv i32 %40, 10
  %42 = add nsw i32 %41, %1
  %43 = add i32 %39, -700
  %44 = icmp ult i32 %43, -699
  %45 = add i32 %42, -500
  %46 = icmp ult i32 %45, -499
  %47 = or i1 %44, %46
  br i1 %47, label %49, label %48

48:                                               ; preds = %36
  tail call void @simPutPixel(i32 noundef %39, i32 noundef %42, i32 noundef %7) #7
  br label %49

49:                                               ; preds = %48, %36
  %50 = shl nsw i32 %2, 2
  %51 = sdiv i32 %50, 10
  %52 = add nsw i32 %51, %0
  %53 = shl nsw i32 %3, 2
  %54 = sdiv i32 %53, 10
  %55 = add nsw i32 %54, %1
  %56 = add i32 %52, -700
  %57 = icmp ult i32 %56, -699
  %58 = add i32 %55, -500
  %59 = icmp ult i32 %58, -499
  %60 = or i1 %57, %59
  br i1 %60, label %62, label %61

61:                                               ; preds = %49
  tail call void @simPutPixel(i32 noundef %52, i32 noundef %55, i32 noundef %7) #7
  br label %62

62:                                               ; preds = %61, %49
  %63 = sdiv i32 %2, 2
  %64 = add nsw i32 %63, %0
  %65 = sdiv i32 %3, 2
  %66 = add nsw i32 %65, %1
  %67 = add i32 %64, -700
  %68 = icmp ult i32 %67, -699
  %69 = add i32 %66, -500
  %70 = icmp ult i32 %69, -499
  %71 = or i1 %68, %70
  br i1 %71, label %73, label %72

72:                                               ; preds = %62
  tail call void @simPutPixel(i32 noundef %64, i32 noundef %66, i32 noundef %7) #7
  br label %73

73:                                               ; preds = %72, %62
  %74 = mul nsw i32 %2, 6
  %75 = sdiv i32 %74, 10
  %76 = add nsw i32 %75, %0
  %77 = mul nsw i32 %3, 6
  %78 = sdiv i32 %77, 10
  %79 = add nsw i32 %78, %1
  %80 = add i32 %76, -700
  %81 = icmp ult i32 %80, -699
  %82 = add i32 %79, -500
  %83 = icmp ult i32 %82, -499
  %84 = or i1 %81, %83
  br i1 %84, label %86, label %85

85:                                               ; preds = %73
  tail call void @simPutPixel(i32 noundef %76, i32 noundef %79, i32 noundef %7) #7
  br label %86

86:                                               ; preds = %85, %73
  %87 = mul nsw i32 %2, 7
  %88 = sdiv i32 %87, 10
  %89 = add nsw i32 %88, %0
  %90 = mul nsw i32 %3, 7
  %91 = sdiv i32 %90, 10
  %92 = add nsw i32 %91, %1
  %93 = add i32 %89, -700
  %94 = icmp ult i32 %93, -699
  %95 = add i32 %92, -500
  %96 = icmp ult i32 %95, -499
  %97 = or i1 %94, %96
  br i1 %97, label %99, label %98

98:                                               ; preds = %86
  tail call void @simPutPixel(i32 noundef %89, i32 noundef %92, i32 noundef %7) #7
  br label %99

99:                                               ; preds = %98, %86
  %100 = shl nsw i32 %2, 3
  %101 = sdiv i32 %100, 10
  %102 = add nsw i32 %101, %0
  %103 = shl nsw i32 %3, 3
  %104 = sdiv i32 %103, 10
  %105 = add nsw i32 %104, %1
  %106 = add i32 %102, -700
  %107 = icmp ult i32 %106, -699
  %108 = add i32 %105, -500
  %109 = icmp ult i32 %108, -499
  %110 = or i1 %107, %109
  br i1 %110, label %112, label %111

111:                                              ; preds = %99
  tail call void @simPutPixel(i32 noundef %102, i32 noundef %105, i32 noundef %7) #7
  br label %112

112:                                              ; preds = %111, %99
  %113 = mul nsw i32 %2, 9
  %114 = sdiv i32 %113, 10
  %115 = add nsw i32 %114, %0
  %116 = mul nsw i32 %3, 9
  %117 = sdiv i32 %116, 10
  %118 = add nsw i32 %117, %1
  %119 = add i32 %115, -700
  %120 = icmp ult i32 %119, -699
  %121 = add i32 %118, -500
  %122 = icmp ult i32 %121, -499
  %123 = or i1 %120, %122
  br i1 %123, label %125, label %124

124:                                              ; preds = %112
  tail call void @simPutPixel(i32 noundef %115, i32 noundef %118, i32 noundef %7) #7
  br label %125

125:                                              ; preds = %124, %112
  ret void
}

; Function Attrs: argmemonly mustprogress nofree nosync nounwind willreturn
declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #2

declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #3

; Function Attrs: mustprogress nofree norecurse nosync nounwind readnone uwtable willreturn
define dso_local i32 @getAbsVelocity(i32 noundef %0, i32 noundef %1) local_unnamed_addr #0 {
  %3 = tail call i32 @llvm.abs.i32(i32 %0, i1 true)
  %4 = tail call i32 @llvm.abs.i32(i32 %1, i1 true)
  %5 = add nuw nsw i32 %4, %3
  %6 = and i32 %5, 255
  ret i32 %6
}

; Function Attrs: noreturn nounwind uwtable
define dso_local void @app() local_unnamed_addr #4 {
  %1 = alloca [10 x i32], align 16
  %2 = alloca [10 x i32], align 16
  %3 = bitcast [10 x i32]* %1 to i8*
  call void @llvm.lifetime.start.p0i8(i64 40, i8* nonnull %3) #7
  call void @llvm.memset.p0i8.i64(i8* noundef nonnull align 16 dereferenceable(40) %3, i8 0, i64 40, i1 false)
  %4 = bitcast [10 x i32]* %2 to i8*
  call void @llvm.lifetime.start.p0i8(i64 40, i8* nonnull %4) #7
  call void @llvm.memset.p0i8.i64(i8* noundef nonnull align 16 dereferenceable(40) %4, i8 0, i64 40, i1 false)
  br label %5

5:                                                ; preds = %9, %0
  %6 = phi i32 [ 0, %0 ], [ %10, %9 ]
  %7 = urem i32 %6, 5
  %8 = icmp eq i32 %7, 0
  br label %11

9:                                                ; preds = %59
  %10 = add nuw nsw i32 %6, 1
  br label %5

11:                                               ; preds = %5, %59
  %12 = phi i64 [ 0, %5 ], [ %62, %59 ]
  %13 = getelementptr inbounds [10 x i32], [10 x i32]* %1, i64 0, i64 %12
  %14 = load i32, i32* %13, align 4, !tbaa !5
  %15 = getelementptr inbounds [10 x i32], [10 x i32]* %2, i64 0, i64 %12
  %16 = load i32, i32* %15, align 4, !tbaa !5
  %17 = sdiv i32 %14, 100
  %18 = sdiv i32 %16, 100
  %19 = add nsw i32 %17, -700
  %20 = icmp ult i32 %19, -699
  %21 = add nsw i32 %18, -500
  %22 = icmp ult i32 %21, -499
  %23 = or i1 %20, %22
  br i1 %23, label %24, label %39

24:                                               ; preds = %11
  %25 = tail call i32 (...) @simRand() #7
  %26 = srem i32 %25, 700
  %27 = trunc i32 %26 to i16
  %28 = sdiv i16 %27, 3
  %29 = sext i16 %28 to i32
  %30 = mul nsw i32 %29, 100
  %31 = add nsw i32 %30, 35000
  %32 = tail call i32 (...) @simRand() #7
  %33 = srem i32 %32, 500
  %34 = trunc i32 %33 to i16
  %35 = sdiv i16 %34, 3
  %36 = sext i16 %35 to i32
  %37 = mul nsw i32 %36, 100
  %38 = add nsw i32 %37, 25000
  br label %39

39:                                               ; preds = %24, %11
  %40 = phi i32 [ %14, %11 ], [ %31, %24 ]
  %41 = phi i32 [ %16, %11 ], [ %38, %24 ]
  %42 = mul nsw i32 %40, 250
  %43 = mul nsw i32 %41, %40
  %44 = sdiv i32 %43, 100
  %45 = sub nsw i32 %42, %44
  %46 = sdiv i32 %45, 10000
  %47 = mul nsw i32 %41, -350
  %48 = add nsw i32 %44, %47
  %49 = sdiv i32 %48, 10000
  br i1 %8, label %50, label %59

50:                                               ; preds = %39
  %51 = sdiv i32 %40, 100
  %52 = sdiv i32 %41, 100
  %53 = sdiv i32 %45, 200000
  %54 = sdiv i32 %48, 200000
  %55 = tail call i32 @llvm.abs.i32(i32 %46, i1 true) #7
  %56 = tail call i32 @llvm.abs.i32(i32 %49, i1 true) #7
  %57 = add nuw nsw i32 %56, %55
  %58 = and i32 %57, 255
  tail call void @drawLine(i32 noundef %51, i32 noundef %52, i32 noundef %53, i32 noundef %54, i32 noundef %58)
  tail call void (...) @simFlush() #7
  br label %59

59:                                               ; preds = %50, %39
  %60 = add nsw i32 %46, %40
  %61 = add nsw i32 %49, %41
  store i32 %60, i32* %13, align 4, !tbaa !5
  store i32 %61, i32* %15, align 4, !tbaa !5
  %62 = add nuw nsw i64 %12, 1
  %63 = icmp eq i64 %62, 10
  br i1 %63, label %9, label %11, !llvm.loop !9
}

; Function Attrs: argmemonly mustprogress nofree nounwind willreturn writeonly
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #5

declare i32 @simRand(...) local_unnamed_addr #3

declare void @simFlush(...) local_unnamed_addr #3

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare i32 @llvm.abs.i32(i32, i1 immarg) #6

attributes #0 = { mustprogress nofree norecurse nosync nounwind readnone uwtable willreturn "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nounwind uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { argmemonly mustprogress nofree nosync nounwind willreturn }
attributes #3 = { "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { noreturn nounwind uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #5 = { argmemonly mustprogress nofree nounwind willreturn writeonly }
attributes #6 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #7 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!5 = !{!6, !6, i64 0}
!6 = !{!"int", !7, i64 0}
!7 = !{!"omnipotent char", !8, i64 0}
!8 = !{!"Simple C/C++ TBAA"}
!9 = distinct !{!9, !10}
!10 = !{!"llvm.loop.mustprogress"}
