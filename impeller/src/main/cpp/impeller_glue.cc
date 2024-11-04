
#include <EGL/egl.h>
#include <android/log.h>
#include <impeller.h>
#include <jni.h>
#include <string.h>
#include <string>
#include <vector>

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

static std::string ReadString(JNIEnv* env, jstring string) {
  if (string == nullptr) {
    return {};
  }
  auto text_chars = env->GetStringUTFChars(string, NULL);
  if (text_chars == nullptr) {
    return {};
  }
  std::string result(text_chars, env->GetStringUTFLength(string));
  env->ReleaseStringUTFChars(string, text_chars);
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

//------------------------------------------------------------------------------
// Color Filter
//------------------------------------------------------------------------------

struct ColorStops {
  std::vector<ImpellerColor> colors;
  std::vector<float> stops;

  ColorStops(JNIEnv* env, jfloatArray jcolors, jfloatArray jstops) {
    const auto stop_count = env->GetArrayLength(jstops);
    const auto color_components_count = env->GetArrayLength(jcolors);
    if (stop_count * 4 != color_components_count) {
      return;
    }
    stops.reserve(stop_count);
    colors.reserve(stop_count);
    const auto c_color_components = env->GetFloatArrayElements(jcolors, NULL);
    const auto c_stops = env->GetFloatArrayElements(jstops, NULL);
    if (!c_color_components || !c_stops) {
      return;
    }
    for (size_t i = 0; i < stop_count; i++) {
      stops.push_back(c_stops[i]);
      ImpellerColor color = {};
      color.color_space = kImpellerColorSpaceSRGB;
      color.red = c_color_components[(i * 4u) + 0u];
      color.green = c_color_components[(i * 4u) + 1u];
      color.blue = c_color_components[(i * 4u) + 2u];
      color.alpha = c_color_components[(i * 4u) + 3u];
      colors.push_back(color);
    }
    env->ReleaseFloatArrayElements(jcolors, c_color_components, 0);
    env->ReleaseFloatArrayElements(jstops, c_stops, 0);
  }
};

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_ColorSource_ImpellerColorSourceCreateConicalGradientNew(
    JNIEnv* env,
    jclass clazz,
    jfloatArray start_center_point,
    jfloat start_radius,
    jfloatArray end_center_point,
    jfloat end_radius,
    jfloatArray color,
    jfloatArray stops,
    jint tile_mode,
    jfloatArray transform) {
  const auto istart_center_point = ToPoint(env, start_center_point);
  const auto iend_center_point = ToPoint(env, end_center_point);
  ColorStops color_stops(env, color, stops);
  const auto itransform = ToMatrix(env, transform);
  return (jlong)ImpellerColorSourceCreateConicalGradientNew(
      &istart_center_point, start_radius, &iend_center_point, end_radius,
      color_stops.stops.size(), color_stops.colors.data(),
      color_stops.stops.data(), (ImpellerTileMode)tile_mode, &itransform);
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_ColorSource_ImpellerColorSourceCreateImageNew(
    JNIEnv* env,
    jclass clazz,
    jlong texture,
    jint horizontal_tile_mode,
    jint vertical_tile_mode,
    jint sampling,
    jfloatArray transform) {
  const auto itransform = ToMatrix(env, transform);
  return (jlong)ImpellerColorSourceCreateImageNew(
      (ImpellerTexture)texture, (ImpellerTileMode)horizontal_tile_mode,
      (ImpellerTileMode)vertical_tile_mode, (ImpellerTextureSampling)sampling,
      &itransform);
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_ColorSource_ImpellerColorSourceCreateLinearGradientNew(
    JNIEnv* env,
    jclass clazz,
    jfloatArray start_point,
    jfloatArray end_point,
    jfloatArray colors,
    jfloatArray stops,
    jint tile_mode,
    jfloatArray transform) {
  const auto istart_point = ToPoint(env, start_point);
  const auto iend_point = ToPoint(env, end_point);
  ColorStops color_stops(env, colors, stops);
  const auto itransform = ToMatrix(env, transform);
  return (jlong)ImpellerColorSourceCreateLinearGradientNew(
      &istart_point, &iend_point, color_stops.stops.size(),
      color_stops.colors.data(), color_stops.stops.data(),
      (ImpellerTileMode)tile_mode, &itransform);
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_ColorSource_ImpellerColorSourceCreateRadialGradientNew(
    JNIEnv* env,
    jclass clazz,
    jfloatArray center_point,
    jfloat radius,
    jfloatArray colors,
    jfloatArray stops,
    jint tile_mode,
    jfloatArray transform) {
  const auto icenter_point = ToPoint(env, center_point);
  ColorStops color_stops(env, colors, stops);
  const auto itransform = ToMatrix(env, transform);
  return (jlong)ImpellerColorSourceCreateRadialGradientNew(
      &icenter_point, radius, color_stops.stops.size(),
      color_stops.colors.data(), color_stops.stops.data(),
      (ImpellerTileMode)tile_mode, &itransform);
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_ColorSource_ImpellerColorSourceCreateSweepGradientNew(
    JNIEnv* env,
    jclass clazz,
    jfloatArray center_point,
    jfloat start,
    jfloat end,
    jfloatArray colors,
    jfloatArray stops,
    jint tile_mode,
    jfloatArray transform) {
  const auto icenter_point = ToPoint(env, center_point);
  ColorStops color_stops(env, colors, stops);
  const auto itransform = ToMatrix(env, transform);
  return (jlong)ImpellerColorSourceCreateSweepGradientNew(
      &icenter_point, start, end, color_stops.stops.size(),
      color_stops.colors.data(), color_stops.stops.data(),
      (ImpellerTileMode)tile_mode, &itransform);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ColorSource_ImpellerColorSourceRelease(JNIEnv* env,
                                                                 jclass clazz,
                                                                 jlong source) {
  ImpellerColorSourceRelease((ImpellerColorSource)source);
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_Context_ImpellerContextCreateOpenGLESNew(
    JNIEnv* env,
    jclass clazz) {
  return (jlong)ImpellerContextCreateOpenGLESNew(
      IMPELLER_VERSION,
      [](const char* proc_name, void*) -> void* {
        return (void*)eglGetProcAddress(proc_name);
      },
      nullptr);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_Context_ImpellerContextRelease(JNIEnv* env,
                                                         jclass clazz,
                                                         jlong context) {
  ImpellerContextRelease((ImpellerContext)context);
}

//------------------------------------------------------------------------------
// Display List
//------------------------------------------------------------------------------

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_DisplayList_ImpellerDisplayListRelease(JNIEnv* env,
                                                                 jclass clazz,
                                                                 jlong handle) {
  ImpellerDisplayListRelease((ImpellerDisplayList)handle);
}

//------------------------------------------------------------------------------
// Image Filter
//------------------------------------------------------------------------------

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ImageFilter_ImpellerImageFilterRelease(JNIEnv* env,
                                                                 jclass clazz,
                                                                 jlong filter) {
  ImpellerImageFilterRelease((ImpellerImageFilter)filter);
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_ImageFilter_ImpellerImageFilterCreateMatrixNew(
    JNIEnv* env,
    jclass clazz,
    jfloatArray matrix,
    jint sampling) {
  const auto imatrix = ToMatrix(env, matrix);
  return (jlong)ImpellerImageFilterCreateMatrixNew(
      &imatrix, (ImpellerTextureSampling)sampling);
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_ImageFilter_ImpellerImageFilterCreateErodeNew(
    JNIEnv* env,
    jclass clazz,
    jfloat x_radius,
    jfloat y_radius) {
  return (jlong)ImpellerImageFilterCreateErodeNew(x_radius, y_radius);
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_ImageFilter_ImpellerImageFilterCreateDilateNew(
    JNIEnv* env,
    jclass clazz,
    jfloat x_radius,
    jfloat y_radius) {
  return (jlong)ImpellerImageFilterCreateDilateNew(x_radius, y_radius);
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_ImageFilter_ImpellerImageFilterCreateComposeNew(
    JNIEnv* env,
    jclass clazz,
    jlong outer,
    jlong inner) {
  return (jlong)ImpellerImageFilterCreateComposeNew((ImpellerImageFilter)outer,
                                                    (ImpellerImageFilter)inner);
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_ImageFilter_ImpellerImageFilterCreateBlurNew(
    JNIEnv* env,
    jclass clazz,
    jfloat x_sigma,
    jfloat y_sigma,
    jint tile_mode) {
  return (jlong)ImpellerImageFilterCreateBlurNew(x_sigma, y_sigma,
                                                 (ImpellerTileMode)tile_mode);
}

//------------------------------------------------------------------------------
// Image Filter
//------------------------------------------------------------------------------

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_MaskFilter_ImpellerMaskFilterCreateBlurNew(
    JNIEnv* env,
    jclass clazz,
    jint blur_style,
    jfloat sigma) {
  return (jlong)ImpellerMaskFilterCreateBlurNew((ImpellerBlurStyle)blur_style,
                                                sigma);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_MaskFilter_ImpellerMaskFilterRelease(JNIEnv* env,
                                                               jclass clazz,
                                                               jlong filter) {
  ImpellerMaskFilterRelease((ImpellerMaskFilter)filter);
}

//------------------------------------------------------------------------------
// Paragraph Builder
//------------------------------------------------------------------------------

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ParagraphBuilder_ImpellerParagraphBuilderRelease(
    JNIEnv* env,
    jclass clazz,
    jlong builder) {
  ImpellerParagraphBuilderRelease((ImpellerParagraphBuilder)builder);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ParagraphBuilder_ImpellerParagraphBuilderPushStyle(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jlong style) {
  if (builder == 0) {
    return;
  }
  ImpellerParagraphBuilderPushStyle((ImpellerParagraphBuilder)builder,
                                    (ImpellerParagraphStyle)style);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ParagraphBuilder_ImpellerParagraphBuilderPopStyle(
    JNIEnv* env,
    jclass clazz,
    jlong builder) {
  if (builder == 0) {
    return;
  }
  ImpellerParagraphBuilderPopStyle((ImpellerParagraphBuilder)builder);
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_ParagraphBuilder_ImpellerParagraphBuilderNew(
    JNIEnv* env,
    jclass clazz,
    jlong context) {
  return (jlong)ImpellerParagraphBuilderNew((ImpellerTypographyContext)context);
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_ParagraphBuilder_ImpellerParagraphBuilderBuildParagraphNew(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jfloat width) {
  if (builder == 0) {
    return 0;
  }
  return (jlong)ImpellerParagraphBuilderBuildParagraphNew(
      (ImpellerParagraphBuilder)builder, width);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ParagraphBuilder_ImpellerParagraphBuilderAddText(
    JNIEnv* env,
    jclass clazz,
    jlong builder,
    jstring text) {
  if (builder == 0 || text == nullptr) {
    return;
  }
  auto text_chars = env->GetStringUTFChars(text, NULL);
  if (text_chars == nullptr) {
    return;
  }
  ImpellerParagraphBuilderAddText((ImpellerParagraphBuilder)builder,
                                  (const uint8_t*)text_chars,
                                  env->GetStringUTFLength(text));
  env->ReleaseStringUTFChars(text, text_chars);
}

//------------------------------------------------------------------------------
// Paragraph
//------------------------------------------------------------------------------

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_Paragraph_ImpellerParagraphRelease(JNIEnv* env,
                                                             jclass clazz,
                                                             jlong para) {
  ImpellerParagraphRelease((ImpellerParagraph)para);
}

extern "C" JNIEXPORT jfloat JNICALL
Java_dev_flutter_impeller_Paragraph_ImpellerParagraphGetMinIntrinsicWidth(
    JNIEnv* env,
    jclass clazz,
    jlong para) {
  if (para == 0) {
    return 0;
  }
  return ImpellerParagraphGetMinIntrinsicWidth((ImpellerParagraph)para);
}

extern "C" JNIEXPORT jfloat JNICALL
Java_dev_flutter_impeller_Paragraph_ImpellerParagraphGetMaxWidth(JNIEnv* env,
                                                                 jclass clazz,
                                                                 jlong para) {
  if (para == 0) {
    return 0;
  }
  return ImpellerParagraphGetMaxWidth((ImpellerParagraph)para);
}

extern "C" JNIEXPORT jfloat JNICALL
Java_dev_flutter_impeller_Paragraph_ImpellerParagraphGetMaxIntrinsicWidth(
    JNIEnv* env,
    jclass clazz,
    jlong para) {
  if (para == 0) {
    return 0;
  }
  return ImpellerParagraphGetMaxIntrinsicWidth((ImpellerParagraph)para);
}

extern "C" JNIEXPORT jfloat JNICALL
Java_dev_flutter_impeller_Paragraph_ImpellerParagraphGetLongestLineWidth(
    JNIEnv* env,
    jclass clazz,
    jlong para) {
  if (para == 0) {
    return 0;
  }
  return ImpellerParagraphGetLongestLineWidth((ImpellerParagraph)para);
}

extern "C" JNIEXPORT jint JNICALL
Java_dev_flutter_impeller_Paragraph_ImpellerParagraphGetLineCount(JNIEnv* env,
                                                                  jclass clazz,
                                                                  jlong para) {
  if (para == 0) {
    return 0;
  }
  return ImpellerParagraphGetLineCount((ImpellerParagraph)para);
}

extern "C" JNIEXPORT jfloat JNICALL
Java_dev_flutter_impeller_Paragraph_ImpellerParagraphGetIdeographicBaseline(
    JNIEnv* env,
    jclass clazz,
    jlong para) {
  if (para == 0) {
    return 0;
  }
  return ImpellerParagraphGetIdeographicBaseline((ImpellerParagraph)para);
}

extern "C" JNIEXPORT jfloat JNICALL
Java_dev_flutter_impeller_Paragraph_ImpellerParagraphGetHeight(JNIEnv* env,
                                                               jclass clazz,
                                                               jlong para) {
  if (para == 0) {
    return 0;
  }
  return ImpellerParagraphGetHeight((ImpellerParagraph)para);
}

extern "C" JNIEXPORT jfloat JNICALL
Java_dev_flutter_impeller_Paragraph_ImpellerParagraphGetAlphabeticBaseline(
    JNIEnv* env,
    jclass clazz,
    jlong para) {
  if (para == 0) {
    return 0;
  }
  return ImpellerParagraphGetAlphabeticBaseline((ImpellerParagraph)para);
}

//------------------------------------------------------------------------------
// Paragraph Style
//------------------------------------------------------------------------------

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ParagraphStyle_ImpellerParagraphStyleSetTextDirection(
    JNIEnv* env,
    jclass clazz,
    jlong para,
    jint text_direction) {
  if (para == 0) {
    return;
  }
  ImpellerParagraphStyleSetTextDirection((ImpellerParagraphStyle)para,
                                         (ImpellerTextDirection)text_direction);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ParagraphStyle_ImpellerParagraphStyleSetTextAlignment(
    JNIEnv* env,
    jclass clazz,
    jlong para,
    jint text_alignment) {
  if (para == 0) {
    return;
  }
  ImpellerParagraphStyleSetTextAlignment((ImpellerParagraphStyle)para,
                                         (ImpellerTextAlignment)text_alignment);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ParagraphStyle_ImpellerParagraphStyleSetMaxLines(
    JNIEnv* env,
    jclass clazz,
    jlong para,
    jint max_lines) {
  if (para == 0) {
    return;
  }
  ImpellerParagraphStyleSetMaxLines((ImpellerParagraphStyle)para, max_lines);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ParagraphStyle_ImpellerParagraphStyleSetLocale(
    JNIEnv* env,
    jclass clazz,
    jlong para,
    jstring locale) {
  if (para == 0) {
    return;
  }
  ImpellerParagraphStyleSetLocale((ImpellerParagraphStyle)para,
                                  ReadString(env, locale).c_str());
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ParagraphStyle_ImpellerParagraphStyleSetHeight(
    JNIEnv* env,
    jclass clazz,
    jlong para,
    jfloat height) {
  if (para == 0) {
    return;
  }
  ImpellerParagraphStyleSetHeight((ImpellerParagraphStyle)para, height);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ParagraphStyle_ImpellerParagraphStyleSetForeground(
    JNIEnv* env,
    jclass clazz,
    jlong para,
    jlong paint) {
  if (para == 0) {
    return;
  }
  ImpellerParagraphStyleSetForeground((ImpellerParagraphStyle)para,
                                      (ImpellerPaint)paint);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ParagraphStyle_ImpellerParagraphStyleSetFontWeight(
    JNIEnv* env,
    jclass clazz,
    jlong para,
    jint font_weight) {
  if (para == 0) {
    return;
  }
  ImpellerParagraphStyleSetFontWeight((ImpellerParagraphStyle)para,
                                      (ImpellerFontWeight)font_weight);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ParagraphStyle_ImpellerParagraphStyleSetFontStyle(
    JNIEnv* env,
    jclass clazz,
    jlong para,
    jint font_style) {
  if (para == 0) {
    return;
  }
  ImpellerParagraphStyleSetFontStyle((ImpellerParagraphStyle)para,
                                     (ImpellerFontStyle)font_style);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ParagraphStyle_ImpellerParagraphStyleSetFontSize(
    JNIEnv* env,
    jclass clazz,
    jlong para,
    jfloat size) {
  if (para == 0) {
    return;
  }
  ImpellerParagraphStyleSetFontSize((ImpellerParagraphStyle)para, size);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ParagraphStyle_ImpellerParagraphStyleSetFontFamily(
    JNIEnv* env,
    jclass clazz,
    jlong para,
    jstring family) {
  if (para == 0) {
    return;
  }
  ImpellerParagraphStyleSetFontFamily((ImpellerParagraphStyle)para,
                                      ReadString(env, family).c_str());
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ParagraphStyle_ImpellerParagraphStyleSetBackground(
    JNIEnv* env,
    jclass clazz,
    jlong para,
    jlong paint) {
  if (para == 0) {
    return;
  }
  ImpellerParagraphStyleSetBackground((ImpellerParagraphStyle)para,
                                      (ImpellerPaint)paint);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_flutter_impeller_ParagraphStyle_ImpellerParagraphStyleRelease(
    JNIEnv* env,
    jclass clazz,
    jlong para) {
  ImpellerParagraphStyleRelease((ImpellerParagraphStyle)para);
}

extern "C" JNIEXPORT jlong JNICALL
Java_dev_flutter_impeller_ParagraphStyle_ImpellerParagraphStyleNew(
    JNIEnv* env,
    jclass clazz) {
  return (jlong)ImpellerParagraphStyleNew();
}
