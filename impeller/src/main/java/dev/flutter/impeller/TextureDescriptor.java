package dev.flutter.impeller;

public class TextureDescriptor {
    private PixelFormat pixelFormat;
    private ISize size;
    private    int mipCount;

    public TextureDescriptor(PixelFormat pixelFormat, ISize size, int mipCount) {
        this.pixelFormat = pixelFormat;
        this.size = size;
        this.mipCount = mipCount;
    }

    public PixelFormat getPixelFormat() {
        return pixelFormat;
    }

    public void setPixelFormat(PixelFormat pixelFormat) {
        this.pixelFormat = pixelFormat;
    }

    public ISize getSize() {
        return size;
    }

    public void setSize(ISize size) {
        this.size = size;
    }

    public int getMipCount() {
        return mipCount;
    }

    public void setMipCount(int mipCount) {
        this.mipCount = mipCount;
    }
}
