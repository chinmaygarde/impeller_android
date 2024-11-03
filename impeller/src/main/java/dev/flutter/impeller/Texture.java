package dev.flutter.impeller;

public class Texture {
    Texture(long handle) {
        this.handle = handle;
    }

    public long getHandle() {
        return handle;
    }

    private long handle = 0;
}
