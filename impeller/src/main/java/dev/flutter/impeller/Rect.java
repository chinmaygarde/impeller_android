package dev.flutter.impeller;

public class Rect {
    public Rect(Point origin, Size size) {
        this.origin = origin;
        this.size = size;
    }

    public Rect(float x, float y, float width, float height) {
        this.origin = new Point(x, y);
        this.size = new Size(width, height);
    }

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
