
package dev.flutter.impeller;

public class Surface {
    static {
        Impeller.EnsureInitialized();
    }
    public long getHandle() {
        return handle;
    }

    private long handle = 0;

    Surface(long handle) {
        this.handle = handle;
    }

    private static native long ImpellerSurfaceCreateWrappedFBONew(long context, int fbo, int pixel_format, float[] surface_size);

    public static Surface wrapFBO(Context context, int fbo, PixelFormat pixelFormat, Size surface_size) {
        return new Surface(ImpellerSurfaceCreateWrappedFBONew(context.getHandle(),  fbo,  pixelFormat.ordinal(), surface_size.getElements()));
    }

    private static native boolean ImpellerSurfaceDrawDisplayList(long surface, long display_list);
    public boolean draw(DisplayList displayList) {
        return ImpellerSurfaceDrawDisplayList(handle, displayList.getHandle());
    }

    private static native void ImpellerSurfaceRelease(long surface);

    public void dispose() {
        ImpellerSurfaceRelease(handle);
    }
}

