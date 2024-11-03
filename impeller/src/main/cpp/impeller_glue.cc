
#include <android/log.h>
#include <impeller.h>
#include <jni.h>
#include <string.h>

template <class T>
T ReadFromFloatArray(JNIEnv* env, jfloatArray data) {
  constexpr auto floats_count = sizeof(T) / sizeof(float);
  auto result = T{};
  auto length = env->GetArrayLength(data);
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
  return (jlong)ImpellerPathBuilderTakePathNew((ImpellerPathBuilder)builder,
                                               (ImpellerFillType)fill);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderRelease(
    JNIEnv* env,
    jclass clazz,
    jlong builder) {
  ImpellerPathBuilderRelease((ImpellerPathBuilder)builder);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderQuadraticCurveTo(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray cp,
    jfloatArray end) {
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
  const auto ilocation = ToPoint(env, location);
  ImpellerPathBuilderMoveTo((ImpellerPathBuilder)builder, &ilocation);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderLineTo(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray location) {
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
  return (jlong)ImpellerPathBuilderCopyPathNew((ImpellerPathBuilder)builder,
                                               (ImpellerFillType)fill);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderClose(JNIEnv* env,
                                                               jclass clazz,
                                                               jlong builder) {
  ImpellerPathBuilderClose((ImpellerPathBuilder)builder);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderAddRoundedRect(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray rect,
    jfloatArray rounding_radii) {
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
  const auto irect = ToRect(env, rect);
  ImpellerPathBuilderAddRect((ImpellerPathBuilder)builder, &irect);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_PathBuilder_ImpellerPathBuilderAddOval(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloatArray rect) {
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
  const auto irect = ToRect(env, rect);
  ImpellerPathBuilderAddArc((ImpellerPathBuilder)builder, &irect,
                            start_angle_degrees, end_angle_degrees);
}
