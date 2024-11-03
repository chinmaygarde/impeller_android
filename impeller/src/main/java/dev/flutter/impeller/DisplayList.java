package dev.flutter.impeller;

public class DisplayList {
    DisplayList(long handle) {
        this.handle = handle;
    }
    
    public long getHandle() {
        return handle;
    }

    private long handle = 0;
}
