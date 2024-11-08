package dev.flutter.impeller;

public class ColorFilter {
    static {
        Impeller.EnsureInitialized();
    }
    public long getHandle() {
        return handle;
    }

    public ColorFilter(Color color, BlendMode mode) {
        this.handle = ImpellerColorFilterCreateBlendNew(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha(), mode.ordinal());
    }

    public ColorFilter(ColorMatrix matrix) {
        this.handle = ImpellerColorFilterCreateColorMatrixNew(matrix.getElements());
    }

    public void dispose() {
        ImpellerColorFilterRelease(handle);
        handle = 0;
    }

    private long handle = 0;

    private static native long ImpellerColorFilterCreateBlendNew(float r, float g, float b, float a, int blend_mode);

    private static native long ImpellerColorFilterCreateColorMatrixNew(float[] color_matrx);

    private static native void ImpellerColorFilterRelease(long filter);
}
