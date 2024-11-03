package dev.flutter.impeller;

import androidx.annotation.Nullable;

public class DisplayListBuilder {
    private long handle = 0;

    public DisplayListBuilder() {
        handle = ImpellerDisplayListBuilderNew(null);
    }

    public DisplayListBuilder(Rect cull_rect) {
        handle = ImpellerDisplayListBuilderNew(cull_rect.getElements());
    }

    private static native void ImpellerDisplayListBuilderClipOval(long builder, float[] rect, int clip_op);

    public void clipOval(Rect rect, ClipOperation op) {
        ImpellerDisplayListBuilderClipOval(handle, rect.getElements(), op.ordinal());
    }


    private static native void ImpellerDisplayListBuilderClipPath(long builder, long path, int clip_op);

    public void clipPath(Path path, ClipOperation op) {
        ImpellerDisplayListBuilderClipPath(handle, path.getHandle(), op.ordinal());
    }

    private static native void ImpellerDisplayListBuilderClipRect(long builder, float[] rect, int clip_op);

    public void clipRect(Rect rect, ClipOperation op) {
        ImpellerDisplayListBuilderClipRect(handle, rect.getElements(), op.ordinal());
    }

    private static native void ImpellerDisplayListBuilderClipRoundedRect(long builder, float[] rect, float[] rounding_radii, int clip_op);

    void clipRoundedRect(Rect rect, RoundingRadii radii, ClipOperation op) {
        ImpellerDisplayListBuilderClipRoundedRect(handle, rect.getElements(), radii.getElements(), op.ordinal());
    }

    private static native long ImpellerDisplayListBuilderCreateDisplayListNew(long builder);

    DisplayList build() {
        return new DisplayList(ImpellerDisplayListBuilderCreateDisplayListNew(handle));
    }

    private static native void ImpellerDisplayListBuilderDrawDashedLine(long builder, float[] from, float[] to, float on_length, float off_length, long paint);

    public void drawDashedLine(Point from, Point to, float on_length, float off_length, Paint paint) {
        ImpellerDisplayListBuilderDrawDashedLine(handle, from.getElements(), to.getElements(), on_length, off_length, paint.getHandle());
    }

    private static native void ImpellerDisplayListBuilderDrawDisplayList(long builder, long dl, float opacity);

    public void drawDisplayList(DisplayList display_list, float opacity) {
        ImpellerDisplayListBuilderDrawDisplayList(handle, display_list.getHandle(), opacity);
    }


    private static native void ImpellerDisplayListBuilderDrawLine(long builder, float[] from, float[] to, long paint);

    public void drawLine(Point from, Point to, Paint paint) {
        ImpellerDisplayListBuilderDrawLine(handle, from.getElements(), to.getElements(), paint.getHandle());
    }

    private static native void ImpellerDisplayListBuilderDrawOval(long builder, float[] bounds_rect, long paint);

    public void drawOval(Rect bounds, Paint paint) {
        ImpellerDisplayListBuilderDrawOval(handle, bounds.getElements(), paint.getHandle());
    }

    private static native void ImpellerDisplayListBuilderDrawPaint(long builder, long paint);

    public void drawPaint(Paint paint) {
        ImpellerDisplayListBuilderDrawPaint(handle, paint.getHandle());
    }

    private static native void ImpellerDisplayListBuilderDrawParagraph(long builder, long paragraph, float[] point);

    void drawParagraph(Paragraph paragraph, Point point) {
        ImpellerDisplayListBuilderDrawParagraph(handle, paragraph.getHandle(), point.getElements());
    }

    private static native void ImpellerDisplayListBuilderDrawPath(long builder, long path, long paint);

    public void drawPath(Path path, Paint paint) {
        ImpellerDisplayListBuilderDrawPath(handle, path.getHandle(), path.getHandle());
    }


    private static native void ImpellerDisplayListBuilderDrawRect(long builder, float[] rect, long paint);

    public void drawRect(Rect rect, Paint paint) {
        ImpellerDisplayListBuilderDrawRect(handle, rect.getElements(), paint.getHandle());
    }

    private static native void ImpellerDisplayListBuilderDrawRoundedRect(long builder, float[] rect, float[] radii, long paint);

    public void drawRoundedRect(Rect rect, RoundingRadii radii, Paint paint) {
        ImpellerDisplayListBuilderDrawRoundedRect(handle, rect.getElements(), radii.getElements(), paint.getHandle());
    }

    private static native void ImpellerDisplayListBuilderDrawRoundedRectDifference(long builder, float[] outer_rect, float[] outer_radii, float[] inner_rect, float[] inner_radii, long paint);

    public void drawRoundedRectDifference(Rect outer, RoundingRadii outer_radii, Rect inner, RoundingRadii inner_radii, Paint paint) {
        ImpellerDisplayListBuilderDrawRoundedRectDifference(handle, outer.getElements(), outer_radii.getElements(), inner.getElements(), inner_radii.getElements(), paint.getHandle());
    }

    private static native void ImpellerDisplayListBuilderDrawTexture(long builder, long texture, float[] point, int sampling, long paint);

    public void drawTexture(Texture texture, Point point, TextureSampling sampling, Paint paint) {
        ImpellerDisplayListBuilderDrawTexture(handle, texture.getHandle(), point.getElements(), sampling.ordinal(), paint.getHandle());
    }

    private static native void ImpellerDisplayListBuilderDrawTextureRect(long builder, long texture, float[] src_rect, float[] dst_rect, int sampling, long paint);

    public void drawTextureRect(Texture texture, Rect src, Rect dst, TextureSampling sampling, Paint paint) {
        ImpellerDisplayListBuilderDrawTextureRect(handle, texture.getHandle(), src.getElements(), dst.getElements(), sampling.ordinal(), paint.getHandle());
    }

    private static native int ImpellerDisplayListBuilderGetSaveCount(long builder);

    public int getSaveCount() {
        return ImpellerDisplayListBuilderGetSaveCount(handle);
    }

    private static native void ImpellerDisplayListBuilderGetTransform(long builder, float[] out_transform);

    public Matrix getTransform() {
        float[] elements = new float[16];
        ImpellerDisplayListBuilderGetTransform(handle, elements);
        return new Matrix(elements);
    }


    private static native long ImpellerDisplayListBuilderNew(float[] cull_rect);

    public void dispose() {
        ImpellerDisplayListBuilderRelease(handle);
        handle = 0;
    }


    private static native void ImpellerDisplayListBuilderRelease(long builder);

    private static native void ImpellerDisplayListBuilderResetTransform(long builder);

    public void resetTransform() {
        ImpellerDisplayListBuilderResetTransform(handle);
    }


    private static native void ImpellerDisplayListBuilderRestore(long builder);

    public void restore() {
        ImpellerDisplayListBuilderRestore(handle);
    }

    private static native void ImpellerDisplayListBuilderRestoreToCount(long builder, int count);

    void restoreToCount(int count) {
        ImpellerDisplayListBuilderRestoreToCount(handle, count);
    }

    private static native void ImpellerDisplayListBuilderRotate(long builder, float angle_degrees);

    public void rotate(float angle_degrees) {
        ImpellerDisplayListBuilderRotate(handle, angle_degrees);
    }

    private static native void ImpellerDisplayListBuilderSave(long builder);

    public void save() {
        ImpellerDisplayListBuilderSave(handle);
    }

    private static native void ImpellerDisplayListBuilderSaveLayer(long builder, float[] bounds, long paint, long backdrop_image_filter);

    public void saveLayer(Rect bounds, @Nullable Paint paint, @Nullable ImageFilter image_filter) {
        ImpellerDisplayListBuilderSaveLayer(handle, bounds.getElements(), paint == null ? 0 : paint.getHandle(), image_filter == null ? 0 : image_filter.getHandle());
    }

    private static native void ImpellerDisplayListBuilderScale(long builder, float x, float y);

    public void scale(Size size) {
        ImpellerDisplayListBuilderScale(handle, size.getWidth(), size.getHeight());
    }


    private static native void ImpellerDisplayListBuilderSetTransform(long builder, float[] transform);

    public void setTransform(Matrix transform) {
        ImpellerDisplayListBuilderSetTransform(handle, transform.getElements());
    }


    private static native void ImpellerDisplayListBuilderTransform(long builder, float[] transform);

    public void transform(Matrix transform) {
        ImpellerDisplayListBuilderTransform(handle, transform.getElements());
    }


    private static native void ImpellerDisplayListBuilderTranslate(long builder, float x, float y);

    public void Translate(Point value) {
        ImpellerDisplayListBuilderTranslate(handle, value.getX(), value.getY());
    }

}
