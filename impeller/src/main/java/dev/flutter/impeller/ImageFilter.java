package dev.flutter.impeller;

public class ImageFilter {
    static {
        Impeller.EnsureInitialized();
    }
    private long handle = 0;

    public long getHandle() {
        return handle;
    }

    ImageFilter(long handle) {
        this.handle = handle;
    }

    private static native long ImpellerImageFilterCreateBlurNew(float x_sigma, float y_sigma, int tile_mode);

    public static ImageFilter blur(Size size, TileMode mode) {
        return new ImageFilter(ImpellerImageFilterCreateBlurNew(size.getWidth(), size.getHeight(), mode.ordinal()));
    }

    public static ImageFilter compose(ImageFilter outer, ImageFilter inner) {
        return new ImageFilter(ImpellerImageFilterCreateComposeNew(outer.getHandle(), inner.getHandle()));
    }

    private static native long ImpellerImageFilterCreateComposeNew(long outer, long inner);

    private static native long ImpellerImageFilterCreateDilateNew(float x_radius, float y_radius);

    public static ImageFilter dilate(Size radius) {
        return new ImageFilter(ImpellerImageFilterCreateDilateNew(radius.getWidth(), radius.getHeight()));
    }

    private static native long ImpellerImageFilterCreateErodeNew(float x_radius, float y_radius);

    public static ImageFilter erode(Size radius) {
        return new ImageFilter(ImpellerImageFilterCreateErodeNew(radius.getWidth(), radius.getHeight()));
    }

    private static native long ImpellerImageFilterCreateMatrixNew(float[] matrix, int sampling);

    public static ImageFilter matrix(Matrix transform, TextureSampling sampling) {
        return new ImageFilter(ImpellerImageFilterCreateMatrixNew(transform.getElements(), sampling.ordinal()));
    }

    private static native void ImpellerImageFilterRelease(long filter);

    public void dispose() {
        ImpellerImageFilterRelease(handle);
        handle = 0;
    }
}
