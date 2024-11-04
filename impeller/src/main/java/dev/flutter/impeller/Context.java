package dev.flutter.impeller;

public class Context {
    public long getHandle() {
        return handle;
    }

    private long handle = 0;

    private static native long ImpellerContextCreateOpenGLESNew();

    // OpenGL
    public Context() {
        this.handle = ImpellerContextCreateOpenGLESNew();
    }

    private static native void ImpellerContextRelease(long context);

    public void dispose() {
        ImpellerContextRelease(handle);
        handle = 0;
    }
}
