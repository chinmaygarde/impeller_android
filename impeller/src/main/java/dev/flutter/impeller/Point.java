package dev.flutter.impeller;

public class Point {
    public Point(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public Point() {
        this.x = 0;
        this.x = 0;
    }

    public float getX() {
        return x;
    }

    public void setX(float x) {
        this.x = x;
    }

    public float getY() {
        return y;
    }

    public void setY(float y) {
        this.y = y;
    }

    public float[] getElements() {
        return new float[]{x, y};
    }


    private float x;
    private float y;

}
