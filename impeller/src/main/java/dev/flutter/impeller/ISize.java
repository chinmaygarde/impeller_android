package dev.flutter.impeller;

public class ISize {
    private long width;
    private long height;

    public ISize() {
        this.width = 0;
        this.height = 0;
    }

    public ISize(long width, long height) {
        this.width = width;
        this.height = height;
    }

    public long getWidth() {
        return width;
    }

    public void setWidth(long width) {
        this.width = width;
    }

    public long getHeight() {
        return height;
    }

    public void setHeight(long height) {
        this.height = height;
    }

    public long[] getElements() {
        return new long[]{this.width, this.height};
    }
}
