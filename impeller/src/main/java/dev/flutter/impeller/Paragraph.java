package dev.flutter.impeller;

public class Paragraph {
    public long getHandle() {
        return handle;
    }

    private long handle = 0;

    Paragraph(long handle) {
        this.handle = handle;
    }
}
