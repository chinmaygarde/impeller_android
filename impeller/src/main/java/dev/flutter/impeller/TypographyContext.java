package dev.flutter.impeller;

public class TypographyContext {
    public long getHandle() {
        return handle;
    }

    private long handle = 0;

    private static native long ImpellerTypographyContextNew();

    public TypographyContext() {
        this.handle = ImpellerTypographyContextNew();
    }

    private static native boolean ImpellerTypographyContextRegisterFont(long context, byte[] data, String family_alias);

    boolean registerFont(byte[] data, String family_alias) {
        return ImpellerTypographyContextRegisterFont(handle, data, family_alias);
    }

    private static native void ImpellerTypographyContextRelease(long context);

    public void dispose() {
        ImpellerTypographyContextRelease(handle);
        handle = 0;
    }
}
