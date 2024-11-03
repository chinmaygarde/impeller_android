package dev.flutter.impeller;

public class Size {
    private float width;

    public Size(float width, float height) {
        this.width = width;
        this.height = height;
    }

    public Size() {
        this.width = 0;
        this.height = 0;
    }


    private float height;

    public float getWidth() {
        return width;
    }

    public void setWidth(float width) {
        this.width = width;
    }

    public float getHeight() {
        return height;
    }

    public void setHeight(float height) {
        this.height = height;
    }

    public float[] getElements() {
        return new float[]{width, height};
    }
}
