package dev.flutter.impeller.demo;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.util.AttributeSet;

import dev.flutter.impeller.Surface;

public class ImpellerSurfaceView extends GLSurfaceView {
    private final ImpellerRenderer renderer;

    public ImpellerSurfaceView(Context context) {
        super(context);
        setEGLContextClientVersion(2);
        renderer = new ImpellerRenderer();
        setRenderer(renderer);
    }
}
