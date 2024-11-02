package dev.flutter.impeller;

public class NativeLib {
    static {
        System.loadLibrary("impeller");
    }
    public native String stringFromJNI();
}