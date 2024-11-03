package dev.flutter.impeller;

public class Impeller {
    static {
        System.loadLibrary("impeller");
        System.loadLibrary("impeller_glue");
    }
    public int version() {
        return 0;
    }
    native public static void SayHello();
}