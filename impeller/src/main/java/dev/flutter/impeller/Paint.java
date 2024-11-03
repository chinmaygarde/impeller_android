package dev.flutter.impeller;

public class Paint {
    public Paint() {
        handle = ImpellerPaintNew();
    }

    void dispose() {
        ImpellerPaintRelease(handle);
    }

    public long getHandle() {
        return handle;
    }

    public void setBlendMode(BlendMode mode) {
        ImpellerPaintSetBlendMode(handle, mode.ordinal());
    }

    public void setColor(Color color) {
        ImpellerPaintSetColor(handle, color.red, color.green, color.blue, color.alpha);
    }

    public void setColorFilter(ColorFilter filter) {
        ImpellerPaintSetColorFilter(handle, filter.getHandle());
    }

    public void setColorSource(ColorSource source) {
        ImpellerPaintSetColorSource(handle, source.getHandle());
    }

    public void setDrawStyle(DrawStyle style) {
        ImpellerPaintSetDrawStyle(handle, style.ordinal());
    }

    public void setImageFilter(ImageFilter filter) {
        ImpellerPaintSetImageFilter(handle, filter.getHandle());
    }

    public void setMaskFilter(MaskFilter filter) {
        ImpellerPaintSetMaskFilter(handle, filter.getHandle());
    }

    public void setStrokeCap(StrokeCap cap) {
        ImpellerPaintSetStrokeCap(handle, cap.ordinal());
    }

    public void setStrokeJoin(StrokeJoin join) {
        ImpellerPaintSetStrokeJoin(handle, join.ordinal());
    }

    public void setStrokeMiter(float miter) {
        ImpellerPaintSetStrokeMiter(handle, miter);
    }

    public void setStrokeWidth(long width) {
        ImpellerPaintSetStrokeWidth(handle, width);
    }

    private long handle = 0;

    private static native long ImpellerPaintNew();

    private static native void ImpellerPaintRelease(long paint);

    private static native void ImpellerPaintSetBlendMode(long paint, int blend);

    private static native void ImpellerPaintSetColor(long paint, float r, float g, float b, float a);

    private static native void ImpellerPaintSetColorFilter(long paint, long color_filter);

    private static native void ImpellerPaintSetColorSource(long paint, long color_source);

    private static native void ImpellerPaintSetDrawStyle(long paint, int style);

    private static native void ImpellerPaintSetImageFilter(long paint, long image_filter);

    private static native void ImpellerPaintSetMaskFilter(long paint, long mask_filter);

    private static native void ImpellerPaintSetStrokeCap(long paint, int stroke_cap);

    private static native void ImpellerPaintSetStrokeJoin(long paint, int stroke_join);

    private static native void ImpellerPaintSetStrokeMiter(long paint, float miter);

    private static native void ImpellerPaintSetStrokeWidth(long paint, float width);
}

