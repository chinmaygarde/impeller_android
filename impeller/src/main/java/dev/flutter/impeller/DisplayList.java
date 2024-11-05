package dev.flutter.impeller;

public class DisplayList {
    static {
        Impeller.EnsureInitialized();
    }
    DisplayList(long handle) {
        this.handle = handle;
    }

    public long getHandle() {
        return handle;
    }

    private long handle = 0;

    private static native void ImpellerDisplayListRelease(long handle);

    public void dispose() {
        ImpellerDisplayListRelease(handle);
        handle = 0;
    }

}
