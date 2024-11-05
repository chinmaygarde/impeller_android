package dev.flutter.impeller.demo;

import android.opengl.GLES20;
import android.opengl.GLSurfaceView;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import dev.flutter.impeller.Color;
import dev.flutter.impeller.Context;
import dev.flutter.impeller.DisplayList;
import dev.flutter.impeller.DisplayListBuilder;
import dev.flutter.impeller.Paint;
import dev.flutter.impeller.PixelFormat;
import dev.flutter.impeller.Rect;
import dev.flutter.impeller.Size;
import dev.flutter.impeller.Surface;

public class ImpellerRenderer implements GLSurfaceView.Renderer {
    private Context context;
    private dev.flutter.impeller.Surface surface;
    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        context = new Context();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        surface = Surface.wrapFBO(context, 0, PixelFormat.rgba8888, new Size(width, height));
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        DisplayListBuilder builder = new DisplayListBuilder();
        Paint paint = new Paint();
        paint.setColor(new Color(1.0f, 0.0f, 1.0f, 1.0f));
        builder.drawRect(new Rect(10, 10, 100, 100), paint);
        DisplayList dl = builder.build();
        surface.draw(dl);
    }
}
