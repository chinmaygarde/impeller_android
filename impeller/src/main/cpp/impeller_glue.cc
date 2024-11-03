
#include <android/log.h>
#include <impeller.h>
#include <jni.h>
#include <string.h>

template <class T>
T ReadFromFloatArray(JNIEnv* env, jfloatArray data) {
  constexpr auto floats_count = sizeof(T) / sizeof(float);
  auto result = T{};
  const auto length = env->GetArrayLength(data);
  if (length != floats_count) {
    return result;
  }
  auto elements = env->GetFloatArrayElements(data, NULL);
  if (elements == NULL) {
    return result;
  }
  memcpy(&result, elements, floats_count * sizeof(float));
  env->ReleaseFloatArrayElements(data, elements, 0);
  return result;
}

template <class T>
bool WriteToFloatArray(JNIEnv* env, jfloatArray data, T value) {
  constexpr auto floats_count = sizeof(T) / sizeof(float);
  const auto length = env->GetArrayLength(data);
  if (length != floats_count) {
    return false;
  }
  jboolean is_copy = false;
  auto elements = env->GetFloatArrayElements(data, &is_copy);
  if (elements == NULL) {
    return false;
  }
  memcpy(elements, &value, floats_count * sizeof(float));
  env->ReleaseFloatArrayElements(data, elements, 0);
  return true;
}

static ImpellerPoint ToPoint(JNIEnv* env, jfloatArray data) {
  return ReadFromFloatArray<ImpellerPoint>(env, data);
}

static ImpellerRect ToRect(JNIEnv* env, jfloatArray data) {
  return ReadFromFloatArray<ImpellerRect>(env, data);
}

static ImpellerRoundingRadii ToRoundingRadii(JNIEnv* env, jfloatArray data) {
  return ReadFromFloatArray<ImpellerRoundingRadii>(env, data);
}

static ImpellerMatrix ToMatrix(JNIEnv* env, jfloatArray data) {
  return ReadFromFloatArray<ImpellerMatrix>(env, data);
}

static ImpellerColorMatrix ToColorMatrix(JNIEnv* env, jfloatArray data) {
  return ReadFromFloatArray<ImpellerColorMatrix>(env, data);
}

bool FromMatrix(JNIEnv* env, jfloatArray dst, const ImpellerMatrix& value) {
  return WriteToFloatArray(env, dst, value);
}

extern "C" JNIEXPORT jint JNICALL
Java_dev_flutter_impeller_Impeller_ImpellerGetVersion(JNIEnv* env,
                                                      jclass clazz) {
  return ImpellerGetVersion();
}

//------------------------------------------------------------------------------
// Paint
//------------------------------------------------------------------------------

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_Paint_ImpellerPaintNew(JNIEnv* env, jclass clazz) {
  return (jlong)ImpellerPaintNew();
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_Paint_ImpellerPaintSetStrokeWidth(JNIEnv* env,
                                                            jclass clazz,
                                                            jlong paint,
                                                            jfloat width) {
  if (paint == 0) {
    return;
  }
  ImpellerPaintSetStrokeWidth((ImpellerPaint)paint, width);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_Paint_ImpellerPaintSetStrokeMiter(JNIEnv* env,
                                                            jclass clazz,
                                                            jlong paint,
                                                            jfloat miter) {
  if (paint == 0) {
    return;
  }
  ImpellerPaintSetStrokeMiter((ImpellerPaint)paint, miter);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_Paint_ImpellerPaintSetStrokeJoin(JNIEnv* env,
                                                           jclass clazz,
                                                           jlong paint,
                                                           jint stroke_join) {
  if (paint == 0) {
    return;
  }
  ImpellerPaintSetStrokeJoin((ImpellerPaint)paint,
                             (ImpellerStrokeJoin)stroke_join);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_Paint_ImpellerPaintSetStrokeCap(JNIEnv* env,
                                                          jclass clazz,
                                                          jlong paint,
                                                          jint stroke_cap) {
  if (paint == 0) {
    return;
  }
  ImpellerPaintSetStrokeCap((ImpellerPaint)paint,
                            (ImpellerStrokeCap)stroke_cap);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_Paint_ImpellerPaintSetMaskFilter(JNIEnv* env,
                                                           jclass clazz,
                                                           jlong paint,
                                                           jlong mask_filter) {
  if (paint == 0) {
    return;
  }
  ImpellerPaintSetMaskFilter((ImpellerPaint)paint,
                             (ImpellerMaskFilter)mask_filter);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_Paint_ImpellerPaintSetImageFilter(
    JNIEnv* env,
    jclass clazz,
    jlong paint,
    jlong image_filter) {
  if (paint == 0) {
    return;
  }
  ImpellerPaintSetImageFilter((ImpellerPaint)paint,
                              (ImpellerImageFilter)image_filter);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_Paint_ImpellerPaintSetDrawStyle(JNIEnv* env,
                                                          jclass clazz,
                                                          jlong paint,
                                                          jint style) {
  if (paint == 0) {
    return;
  }
  ImpellerPaintSetDrawStyle((ImpellerPaint)paint, (ImpellerDrawStyle)style);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_Paint_ImpellerPaintSetColorSource(
    JNIEnv* env,
    jclass clazz,
    jlong paint,
    jlong color_source) {
  if (paint == 0) {
    return;
  }
  ImpellerPaintSetColorSource((ImpellerPaint)paint,
                              (ImpellerColorSource)color_source);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_Paint_ImpellerPaintSetColorFilter(
    JNIEnv* env,
    jclass clazz,
    jlong paint,
    jlong color_filter) {
  if (paint == 0) {
    return;
  }
  ImpellerPaintSetColorFilter((ImpellerPaint)paint,
                              (ImpellerColorFilter)color_filter);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_Paint_ImpellerPaintSetColor(JNIEnv* env,
                                                      jclass clazz,
                                                      jlong paint,
                                                      jfloat r,
                                                      jfloat g,
                                                      jfloat b,
                                                      jfloat a) {
  if (paint == 0) {
    return;
  }
  ImpellerColor color = {r, g, b, a, kImpellerColorSpaceSRGB};
  ImpellerPaintSetColor((ImpellerPaint)paint, &color);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_Paint_ImpellerPaintSetBlendMode(JNIEnv* env,
                                                          jclass clazz,
                                                          jlong paint,
                                                          jint blend) {
  if (paint == 0) {
    return;
  }
  ImpellerPaintSetBlendMode((ImpellerPaint)paint, (ImpellerBlendMode)blend);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_Paint_ImpellerPaintRelease(JNIEnv* env,
                                                     jclass clazz,
                                                     jlong paint) {
  ImpellerPaintRelease((ImpellerPaint)paint);
}

//------------------------------------------------------------------------------
// Path Builder
//------------------------------------------------------------------------------

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderTakePathNew(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jint fill) {
  if (builder == 0) {
    return 0;
  }
  return (jlong)ImpellerPathBuilderTakePathNew((ImpellerPathBuilder)builder,
                                               (ImpellerFillType)fill);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderRelease(
    JNIEnv* env,
    jclass clazz,
    jlong builder) {
  if (builder == 0) {
    return;
  }
  ImpellerPathBuilderRelease((ImpellerPathBuilder)builder);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderQuadraticCurveTo(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray cp,
    jfloatArray end) {
  if (builder == 0) {
    return;
  }
  const auto icp = ToPoint(env, cp);
  const auto iend = ToPoint(env, end);
  ImpellerPathBuilderQuadraticCurveTo((ImpellerPathBuilder)builder, &icp,
                                      &iend);
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderNew(JNIEnv* env,
                                                             jclass clazz) {
  return (jlong)ImpellerPathBuilderNew();
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderMoveTo(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray location) {
  if (builder == 0) {
    return;
  }
  const auto ilocation = ToPoint(env, location);
  ImpellerPathBuilderMoveTo((ImpellerPathBuilder)builder, &ilocation);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderLineTo(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray location) {
  if (builder == 0) {
    return;
  }
  const auto ilocation = ToPoint(env, location);
  ImpellerPathBuilderLineTo((ImpellerPathBuilder)builder, &ilocation);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderCubicCurveTo(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray cp1,
    jfloatArray cp2,
    jfloatArray end) {
  if (builder == 0) {
    return;
  }
  const auto icp1 = ToPoint(env, cp1);
  const auto icp2 = ToPoint(env, cp2);
  const auto iend = ToPoint(env, end);
  ImpellerPathBuilderCubicCurveTo((ImpellerPathBuilder)builder, &icp1, &icp2,
                                  &iend);
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderCopyPathNew(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jint fill) {
  if (builder == 0) {
    return 0;
  }
  return (jlong)ImpellerPathBuilderCopyPathNew((ImpellerPathBuilder)builder,
                                               (ImpellerFillType)fill);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderClose(JNIEnv* env,
                                                               jclass clazz,
                                                               jlong builder) {
  if (builder == 0) {
    return;
  }
  ImpellerPathBuilderClose((ImpellerPathBuilder)builder);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderAddRoundedRect(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray rect,
    jfloatArray rounding_radii) {
  if (builder == 0) {
    return;
  }
  const auto irect = ToRect(env, rect);
  const auto irounding_radii = ToRoundingRadii(env, rounding_radii);
  ImpellerPathBuilderAddRoundedRect((ImpellerPathBuilder)builder, &irect,
                                    &irounding_radii);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderAddRect(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray rect) {
  if (builder == 0) {
    return;
  }
  const auto irect = ToRect(env, rect);
  ImpellerPathBuilderAddRect((ImpellerPathBuilder)builder, &irect);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderAddOval(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray rect) {
  if (builder == 0) {
    return;
  }
  const auto irect = ToRect(env, rect);
  ImpellerPathBuilderAddOval((ImpellerPathBuilder)builder, &irect);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderAddArc(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray rect,
    jfloat start_angle_degrees,
    jfloat end_angle_degrees) {
  if (builder == 0) {
    return;
  }
  const auto irect = ToRect(env, rect);
  ImpellerPathBuilderAddArc((ImpellerPathBuilder)builder, &irect,
                            start_angle_degrees, end_angle_degrees);
}

//------------------------------------------------------------------------------
// Display List Builder
//------------------------------------------------------------------------------

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderClipOval(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray rect,
    jint clip_op) {
  if (builder == 0) {
    return;
  }
  const auto irect = ToRect(env, rect);
  ImpellerDisplayListBuilderClipOval((ImpellerDisplayListBuilder)builder,
                                     &irect, (ImpellerClipOperation)clip_op);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderClipPath(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jlong path,
    jint clip_op) {
  if (builder == 0) {
    return;
  }
  ImpellerDisplayListBuilderClipPath((ImpellerDisplayListBuilder)builder,
                                     (ImpellerPath)path,
                                     (ImpellerClipOperation)clip_op);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderClipRect(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray rect,
    jint clip_op) {
  if (builder == 0) {
    return;
  }
  const auto irect = ToRect(env, rect);
  ImpellerDisplayListBuilderClipRect((ImpellerDisplayListBuilder)builder,
                                     &irect, (ImpellerClipOperation)clip_op);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderClipRoundedRect(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray rect,
    jfloatArray rounding_radii,
    jint clip_op) {
  if (builder == 0) {
    return;
  }

  const auto irect = ToRect(env, rect);
  const auto irounding_radii = ToRoundingRadii(env, rounding_radii);
  ImpellerDisplayListBuilderClipRoundedRect((ImpellerDisplayListBuilder)builder,
                                            &irect, &irounding_radii,
                                            (ImpellerClipOperation)clip_op);
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderCreateDisplayListNew(
    JNIEnv* env,
    jclass clazz,
    jlong builder) {
  if (builder == 0) {
    return 0;
  }
  return (jlong)ImpellerDisplayListBuilderCreateDisplayListNew(
      (ImpellerDisplayListBuilder)builder);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderDrawDashedLine(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray from,
    jfloatArray to,
    jfloat on_length,
    jfloat off_length,
    jlong paint) {
  if (builder == 0) {
    return;
  }
  const auto ifrom = ToPoint(env, from);
  const auto ito = ToPoint(env, to);
  ImpellerDisplayListBuilderDrawDashedLine((ImpellerDisplayListBuilder)builder,
                                           &ifrom, &ito, on_length, off_length,
                                           (ImpellerPaint)paint);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderDrawDisplayList(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jlong dl,
    jfloat opacity) {
  if (builder == 0) {
    return;
  }
  ImpellerDisplayListBuilderDrawDisplayList((ImpellerDisplayListBuilder)builder,
                                            (ImpellerDisplayList)dl, opacity);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderDrawLine(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray from,
    jfloatArray to,
    jlong paint) {
  if (builder == 0) {
    return;
  }
  const auto ifrom = ToPoint(env, from);
  const auto ito = ToPoint(env, to);
  ImpellerDisplayListBuilderDrawLine((ImpellerDisplayListBuilder)builder,
                                     &ifrom, &ito, (ImpellerPaint)paint);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderDrawOval(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray bounds_rect,
    jlong paint) {
  if (builder == 0) {
    return;
  }
  const auto ibounds_rect = ToRect(env, bounds_rect);
  ImpellerDisplayListBuilderDrawOval((ImpellerDisplayListBuilder)builder,
                                     &ibounds_rect, (ImpellerPaint)paint);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderDrawPaint(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jlong paint) {
  if (builder == 0) {
    return;
  }
  ImpellerDisplayListBuilderDrawPaint((ImpellerDisplayListBuilder)builder,
                                      (ImpellerPaint)paint);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderDrawParagraph(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jlong paragraph,
    jfloatArray point) {
  if (builder == 0) {
    return;
  }
  const auto ipoint = ToPoint(env, point);
  ImpellerDisplayListBuilderDrawParagraph((ImpellerDisplayListBuilder)builder,
                                          (ImpellerParagraph)paragraph,
                                          &ipoint);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderDrawPath(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jlong path,
    jlong paint) {
  if (builder == 0) {
    return;
  }
  ImpellerDisplayListBuilderDrawPath((ImpellerDisplayListBuilder)builder,
                                     (ImpellerPath)path, (ImpellerPaint)paint);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderDrawRect(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray rect,
    jlong paint) {
  if (builder == 0) {
    return;
  }
  const auto irect = ToRect(env, rect);
  ImpellerDisplayListBuilderDrawRect((ImpellerDisplayListBuilder)builder,
                                     &irect, (ImpellerPaint)paint);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderDrawRoundedRect(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray rect,
    jfloatArray radii,
    jlong paint) {
  if (builder == 0) {
    return;
  }
  const auto irect = ToRect(env, rect);
  const auto iradii = ToRoundingRadii(env, radii);
  ImpellerDisplayListBuilderDrawRoundedRect((ImpellerDisplayListBuilder)builder,
                                            &irect, &iradii,
                                            (ImpellerPaint)paint);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderDrawRoundedRectDifference(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray outer_rect,
    jfloatArray outer_radii,
    jfloatArray inner_rect,
    jfloatArray inner_radii,
    jlong paint) {
  if (builder == 0) {
    return;
  }
  const auto iouter_rect = ToRect(env, outer_rect);
  const auto iouter_radii = ToRoundingRadii(env, outer_radii);
  const auto iinner_rect = ToRect(env, inner_rect);
  const auto iinner_radii = ToRoundingRadii(env, inner_radii);
  ImpellerDisplayListBuilderDrawRoundedRectDifference(
      (ImpellerDisplayListBuilder)builder, &iouter_rect, &iouter_radii,
      &iinner_rect, &iinner_radii, (ImpellerPaint)paint);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderDrawTexture(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jlong texture,
    jfloatArray point,
    jint sampling,
    jlong paint) {
  if (builder == 0) {
    return;
  }
  const auto ipoint = ToPoint(env, point);
  ImpellerDisplayListBuilderDrawTexture(
      (ImpellerDisplayListBuilder)builder, (ImpellerTexture)texture, &ipoint,
      (ImpellerTextureSampling)sampling, (ImpellerPaint)paint);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderDrawTextureRect(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jlong texture,
    jfloatArray src_rect,
    jfloatArray dst_rect,
    jint sampling,
    jlong paint) {
  if (builder == 0) {
    return;
  }
  const auto isrc_rect = ToRect(env, src_rect);
  const auto idst_rect = ToRect(env, dst_rect);
  ImpellerDisplayListBuilderDrawTextureRect(
      (ImpellerDisplayListBuilder)builder, (ImpellerTexture)texture, &isrc_rect,
      &idst_rect, (ImpellerTextureSampling)sampling, (ImpellerPaint)paint);
}

extern "C" JNIEXPORT jint JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderGetSaveCount(
    JNIEnv* env,
    jclass clazz,
    jlong builder) {
  if (builder == 0) {
    return 0;
  }
  return ImpellerDisplayListBuilderGetSaveCount(
      (ImpellerDisplayListBuilder)builder);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderGetTransform(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray out_transform) {
  if (builder == 0) {
    return;
  }
  ImpellerMatrix matrix = {};
  ImpellerDisplayListBuilderGetTransform((ImpellerDisplayListBuilder)builder,
                                         &matrix);
  if (!FromMatrix(env, out_transform, matrix)) {
    return;
  }
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderNew(
    JNIEnv* env,
    jclass clazz,
    jfloatArray cull_rect) {
  ImpellerRect icull_rect = {};
  if (cull_rect != nullptr) {
    icull_rect = ToRect(env, cull_rect);
  }
  return (jlong)ImpellerDisplayListBuilderNew(
      cull_rect == nullptr ? nullptr : &icull_rect);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderRelease(
    JNIEnv* env,
    jclass clazz,
    jlong builder) {
  ImpellerDisplayListBuilderRelease((ImpellerDisplayListBuilder)builder);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderResetTransform(
    JNIEnv* env,
    jclass clazz,
    jlong builder) {
  if (builder == 0) {
    return;
  }
  ImpellerDisplayListBuilderResetTransform((ImpellerDisplayListBuilder)builder);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderRestore(
    JNIEnv* env,
    jclass clazz,
    jlong builder) {
  if (builder == 0) {
    return;
  }
  ImpellerDisplayListBuilderRestore((ImpellerDisplayListBuilder)builder);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderRestoreToCount(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jint count) {
  if (builder == 0) {
    return;
  }
  ImpellerDisplayListBuilderRestoreToCount((ImpellerDisplayListBuilder)builder,
                                           count);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderRotate(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloat angle_degrees) {
  if (builder == 0) {
    return;
  }
  ImpellerDisplayListBuilderRotate((ImpellerDisplayListBuilder)builder,
                                   angle_degrees);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderSave(
    JNIEnv* env,
    jclass clazz,
    jlong builder) {
  if (builder == 0) {
    return;
  }
  ImpellerDisplayListBuilderSave((ImpellerDisplayListBuilder)builder);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderSaveLayer(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray bounds,
    jlong paint,
    jlong backdrop) {
  if (builder == 0) {
    return;
  }
  const auto ibounds = ToRect(env, bounds);
  ImpellerDisplayListBuilderSaveLayer((ImpellerDisplayListBuilder)builder,
                                      &ibounds, (ImpellerPaint)paint,
                                      (ImpellerImageFilter)backdrop);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderScale(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloat x,
    jfloat y) {
  if (builder == 0) {
    return;
  }
  ImpellerDisplayListBuilderScale((ImpellerDisplayListBuilder)builder, x, y);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderSetTransform(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray transform) {
  if (builder == 0) {
    return;
  }
  const auto itransform = ToMatrix(env, transform);
  ImpellerDisplayListBuilderSetTransform((ImpellerDisplayListBuilder)builder,
                                         &itransform);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderTransform(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray transform) {
  if (builder == 0) {
    return;
  }
  const auto itransform = ToMatrix(env, transform);
  ImpellerDisplayListBuilderTransform((ImpellerDisplayListBuilder)builder,
                                      &itransform);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayListBuilder_ImpellerDisplayListBuilderTranslate(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloat x,
    jfloat y) {
  if (builder == 0) {
    return;
  }
  ImpellerDisplayListBuilderTranslate((ImpellerDisplayListBuilder)builder, x,
                                      y);
}

//------------------------------------------------------------------------------
// Color Filter
//------------------------------------------------------------------------------

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_ColorFilter_ImpellerColorFilterCreateBlendNew(
    JNIEnv* env,
    jclass clazz,
    jfloat r,
    jfloat g,
    jfloat b,
    jfloat a,
    jint blend_mode) {
  ImpellerColor color = {r, g, b, a, kImpellerColorSpaceSRGB};
  return (jlong)ImpellerColorFilterCreateBlendNew(
      &color, (ImpellerBlendMode)blend_mode);
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_ColorFilter_ImpellerColorFilterCreateColorMatrixNew(
    JNIEnv* env,
    jclass clazz,
    jfloatArray color_matrix) {
  const auto icolor_matrix = ToColorMatrix(env, color_matrix);
  return (jlong)ImpellerColorFilterCreateColorMatrixNew(&icolor_matrix);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ColorFilter_ImpellerColorFilterRelease(JNIEnv* env,
                                                                 jclass clazz,
                                                                 jlong filter) {
  ImpellerColorFilterRelease((ImpellerColorFilter)filter);
}
