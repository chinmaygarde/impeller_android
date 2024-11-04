package dev.flutter.impeller;

public class Path {
    public long getHandle() {
        return handle;
    }

    private long handle = 0;

    Path(long handle) {
        this.handle = handle;
    }

    public static native void ImpellerPathRelease(long path);

    public void dispose() {
        ImpellerPathRelease(handle);
        handle = 0;
    }

}

