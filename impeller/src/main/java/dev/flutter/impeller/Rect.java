package dev.flutter.impeller;

public class Rect {
    public Size getSize() {
        return size;
    }

    public void setSize(Size size) {
        this.size = size;
    }

    public Point getOrigin() {
        return origin;
    }

    public void setOrigin(Point origin) {
        this.origin = origin;
    }

    private Point origin;
    private Size size;

    public float[] getElements() {
        return new float[]{origin.getX(), origin.getY(), size.getWidth(), size.getHeight()};
    }
}
