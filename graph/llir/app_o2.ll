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
  tail call void @simPutPixel(i32 noundef %13, i32 noundef %16, i32 noundef %7) #7
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

9:                                                ; preds = %78
  %10 = add nuw nsw i32 %6, 1
  br label %5

11:                                               ; preds = %5, %78
  %12 = phi i64 [ 0, %5 ], [ %81, %78 ]
  %13 = getelementptr inbounds [10 x i32], [10 x i32]* %1, i64 0, i64 %12
  %14 = load i32, i32* %13, align 4, !tbaa !7
  %15 = getelementptr inbounds [10 x i32], [10 x i32]* %2, i64 0, i64 %12
  %16 = load i32, i32* %15, align 4, !tbaa !7
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
  br i1 %8, label %50, label %78

50:                                               ; preds = %39
  %51 = sdiv i32 %40, 100
  %52 = sdiv i32 %41, 100
  %53 = sdiv i32 %45, 200000
  %54 = sdiv i32 %48, 200000
  %55 = tail call i32 @llvm.abs.i32(i32 %46, i1 true) #7
  %56 = tail call i32 @llvm.abs.i32(i32 %49, i1 true) #7
  %57 = add nuw nsw i32 %56, %55
  %58 = shl i32 %57, 16
  %59 = or i32 %58, -16776961
  br label %60

60:                                               ; preds = %74, %50
  %61 = phi i32 [ 0, %50 ], [ %75, %74 ]
  %62 = mul nsw i32 %61, %53
  %63 = sdiv i32 %62, 10
  %64 = add nsw i32 %63, %51
  %65 = mul nsw i32 %61, %54
  %66 = sdiv i32 %65, 10
  %67 = add nsw i32 %66, %52
  %68 = add nsw i32 %64, -700
  %69 = icmp ult i32 %68, -699
  %70 = add nsw i32 %67, -500
  %71 = icmp ult i32 %70, -499
  %72 = or i1 %69, %71
  br i1 %72, label %74, label %73

73:                                               ; preds = %60
  tail call void @simPutPixel(i32 noundef %64, i32 noundef %67, i32 noundef %59) #7
  br label %74

74:                                               ; preds = %73, %60
  %75 = add nuw nsw i32 %61, 1
  %76 = icmp eq i32 %75, 10
  br i1 %76, label %77, label %60, !llvm.loop !5

77:                                               ; preds = %74
  tail call void (...) @simFlush() #7
  br label %78

78:                                               ; preds = %77, %39
  %79 = add nsw i32 %46, %40
  %80 = add nsw i32 %49, %41
  store i32 %79, i32* %13, align 4, !tbaa !7
  store i32 %80, i32* %15, align 4, !tbaa !7
  %81 = add nuw nsw i64 %12, 1
  %82 = icmp eq i64 %81, 10
  br i1 %82, label %9, label %11, !llvm.loop !11
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
!5 = distinct !{!5, !6}
!6 = !{!"llvm.loop.mustprogress"}
!7 = !{!8, !8, i64 0}
!8 = !{!"int", !9, i64 0}
!9 = !{!"omnipotent char", !10, i64 0}
!10 = !{!"Simple C/C++ TBAA"}
!11 = distinct !{!11, !6}
