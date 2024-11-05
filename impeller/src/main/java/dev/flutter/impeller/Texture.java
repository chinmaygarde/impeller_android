package dev.flutter.impeller;

;

public class Texture {
    static {
        Impeller.EnsureInitialized();
    }
    Texture(long handle) {
        this.handle = handle;
    }

    public long getHandle() {
        return handle;
    }

    private long handle = 0;

    private static native long ImpellerTextureCreateWithContentsNew(long context, int pixel_format, long[] size, int mip_count, byte[] data);

    public static Texture withContents(Context context, TextureDescriptor texture_descriptor, byte[] data) {
        return new Texture(ImpellerTextureCreateWithContentsNew(context.getHandle(), texture_descriptor.getPixelFormat().ordinal(), texture_descriptor.getSize().getElements(), texture_descriptor.getMipCount(), data));
    }

    private static native long ImpellerTextureCreateWithOpenGLTextureHandleNew(long context, int pixel_format, long[] size, int mip_count, int opengl_handle);

    public static Texture withOpenGLHandle(Context context, TextureDescriptor desc, int handle) {
        return new Texture(ImpellerTextureCreateWithOpenGLTextureHandleNew(context.getHandle(), desc.getPixelFormat().ordinal(), desc.getSize().getElements(), desc.getMipCount(), handle));
    }

    private static native int ImpellerTextureGetOpenGLHandle(long texture);

    public int getOpenGLHandle() {
        return ImpellerTextureGetOpenGLHandle(handle);
    }

    private static native void ImpellerTextureRelease(long texture);

    public void dispose() {
        ImpellerTextureRelease(handle);
    }
}
