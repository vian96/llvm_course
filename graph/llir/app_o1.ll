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
  br label %9

8:                                                ; preds = %23
  ret void

9:                                                ; preds = %5, %23
  %10 = phi i32 [ 0, %5 ], [ %24, %23 ]
  %11 = mul nsw i32 %10, %2
  %12 = sdiv i32 %11, 10
  %13 = add nsw i32 %12, %0
  %14 = mul nsw i32 %10, %3
  %15 = sdiv i32 %14, 10
  %16 = add nsw i32 %15, %1
  %17 = add i32 %13, -700
  %18 = icmp ult i32 %17, -699
  %19 = add i32 %16, -500
  %20 = icmp ult i32 %19, -499
  %21 = or i1 %18, %20
  br i1 %21, label %23, label %22

22:                                               ; preds = %9
  call void @simPutPixel(i32 noundef %13, i32 noundef %16, i32 noundef %7) #7
  br label %23

23:                                               ; preds = %22, %9
  %24 = add nuw nsw i32 %10, 1
  %25 = icmp eq i32 %24, 10
  br i1 %25, label %8, label %9, !llvm.loop !5
}

; Function Attrs: argmemonly mustprogress nofree nosync nounwind willreturn
declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #2

declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #3

; Function Attrs: mustprogress nofree norecurse nosync nounwind readnone uwtable willreturn
define dso_local i32 @getAbsVelocity(i32 noundef %0, i32 noundef %1) local_unnamed_addr #0 {
  %3 = call i32 @llvm.abs.i32(i32 %0, i1 true)
  %4 = call i32 @llvm.abs.i32(i32 %1, i1 true)
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

9:                                                ; preds = %74
  %10 = add nuw nsw i32 %6, 1
  br label %5, !llvm.loop !8

11:                                               ; preds = %5, %74
  %12 = phi i64 [ 0, %5 ], [ %77, %74 ]
  %13 = getelementptr inbounds [10 x i32], [10 x i32]* %1, i64 0, i64 %12
  %14 = load i32, i32* %13, align 4, !tbaa !9
  %15 = getelementptr inbounds [10 x i32], [10 x i32]* %2, i64 0, i64 %12
  %16 = load i32, i32* %15, align 4, !tbaa !9
  %17 = sdiv i32 %14, 100
  %18 = sdiv i32 %16, 100
  %19 = add nsw i32 %17, -700
  %20 = icmp ult i32 %19, -699
  %21 = add nsw i32 %18, -500
  %22 = icmp ult i32 %21, -499
  %23 = or i1 %20, %22
  br i1 %23, label %24, label %35

24:                                               ; preds = %11
  %25 = call i32 (...) @simRand() #7
  %26 = srem i32 %25, 700
  %27 = sdiv i32 %26, 3
  %28 = mul nsw i32 %27, 100
  %29 = add nsw i32 %28, 35000
  %30 = call i32 (...) @simRand() #7
  %31 = srem i32 %30, 500
  %32 = sdiv i32 %31, 3
  %33 = mul nsw i32 %32, 100
  %34 = add nsw i32 %33, 25000
  br label %35

35:                                               ; preds = %24, %11
  %36 = phi i32 [ %14, %11 ], [ %29, %24 ]
  %37 = phi i32 [ %16, %11 ], [ %34, %24 ]
  %38 = mul nsw i32 %36, 250
  %39 = mul nsw i32 %37, %36
  %40 = sdiv i32 %39, 100
  %41 = sub nsw i32 %38, %40
  %42 = sdiv i32 %41, 10000
  %43 = mul nsw i32 %37, -350
  %44 = add nsw i32 %40, %43
  %45 = sdiv i32 %44, 10000
  br i1 %8, label %46, label %74

46:                                               ; preds = %35
  %47 = sdiv i32 %36, 100
  %48 = sdiv i32 %37, 100
  %49 = sdiv i32 %41, 200000
  %50 = sdiv i32 %44, 200000
  %51 = call i32 @llvm.abs.i32(i32 %42, i1 true) #7
  %52 = call i32 @llvm.abs.i32(i32 %45, i1 true) #7
  %53 = add nuw nsw i32 %52, %51
  %54 = shl i32 %53, 16
  %55 = or i32 %54, -16776961
  br label %56

56:                                               ; preds = %70, %46
  %57 = phi i32 [ 0, %46 ], [ %71, %70 ]
  %58 = mul nsw i32 %57, %49
  %59 = sdiv i32 %58, 10
  %60 = add nsw i32 %59, %47
  %61 = mul nsw i32 %57, %50
  %62 = sdiv i32 %61, 10
  %63 = add nsw i32 %62, %48
  %64 = add nsw i32 %60, -700
  %65 = icmp ult i32 %64, -699
  %66 = add nsw i32 %63, -500
  %67 = icmp ult i32 %66, -499
  %68 = or i1 %65, %67
  br i1 %68, label %70, label %69

69:                                               ; preds = %56
  call void @simPutPixel(i32 noundef %60, i32 noundef %63, i32 noundef %55) #7
  br label %70

70:                                               ; preds = %69, %56
  %71 = add nuw nsw i32 %57, 1
  %72 = icmp eq i32 %71, 10
  br i1 %72, label %73, label %56, !llvm.loop !5

73:                                               ; preds = %70
  call void (...) @simFlush() #7
  br label %74

74:                                               ; preds = %73, %35
  %75 = add nsw i32 %42, %36
  %76 = add nsw i32 %45, %37
  store i32 %75, i32* %13, align 4, !tbaa !9
  store i32 %76, i32* %15, align 4, !tbaa !9
  %77 = add nuw nsw i64 %12, 1
  %78 = icmp eq i64 %77, 10
  br i1 %78, label %9, label %11, !llvm.loop !13
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
!5 = distinct !{!5, !6, !7}
!6 = !{!"llvm.loop.mustprogress"}
!7 = !{!"llvm.loop.unroll.disable"}
!8 = distinct !{!8, !7}
!9 = !{!10, !10, i64 0}
!10 = !{!"int", !11, i64 0}
!11 = !{!"omnipotent char", !12, i64 0}
!12 = !{!"Simple C/C++ TBAA"}
!13 = distinct !{!13, !6, !7}
