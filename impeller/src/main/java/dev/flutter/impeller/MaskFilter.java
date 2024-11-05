package dev.flutter.impeller;

public class MaskFilter {
    static {
        Impeller.EnsureInitialized();
    }
    private long handle = 0;

    public long getHandle() {
        return handle;
    }

    MaskFilter(long handle) {
        this.handle = handle;
    }

    private static native long ImpellerMaskFilterCreateBlurNew(int blur_style, float sigma);

    public static MaskFilter blur(BlurStyle style, float sigma) {
        return new MaskFilter(ImpellerMaskFilterCreateBlurNew(style.ordinal(), sigma));
    }

    private static native void ImpellerMaskFilterRelease(long filter);

    public void dispose() {
        ImpellerMaskFilterRelease(handle);
        handle = 0;
    }
}
