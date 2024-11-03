
#include <android/log.h>
#include <impeller.h>
#include <jni.h>

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
