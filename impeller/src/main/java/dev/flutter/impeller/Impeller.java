package dev.flutter.impeller;

public class Impeller {
    static {
        System.loadLibrary("impeller");
        System.loadLibrary("impeller_glue");
    }
    public static int version() {
        return ImpellerGetVersion();
    }
    private static native int ImpellerGetVersion();

    public static void EnsureInitialized() {}
}