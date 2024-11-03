package dev.flutter.impeller;

public class RoundingRadii {
    private Point topLeft;
    private Point bottomLeft;
    private Point topRight;
    private Point botttomRight;

    public RoundingRadii(Point topLeft, Point bottomLeft, Point topRight, Point botttomRight) {
        this.topLeft = topLeft;
        this.bottomLeft = bottomLeft;
        this.topRight = topRight;
        this.botttomRight = botttomRight;
    }

    public RoundingRadii(Point uniform) {
        this.topLeft = uniform;
        this.bottomLeft = uniform;
        this.topRight = uniform;
        this.botttomRight = uniform;
    }

    public RoundingRadii() {
        this.topLeft = new Point();
        this.bottomLeft = new Point();
        this.topRight = new Point();
        this.botttomRight = new Point();
    }

    public Point getTopLeft() {
        return topLeft;
    }

    public void setTopLeft(Point topLeft) {
        this.topLeft = topLeft;
    }

    public Point getBottomLeft() {
        return bottomLeft;
    }

    public void setBottomLeft(Point bottomLeft) {
        this.bottomLeft = bottomLeft;
    }

    public Point getTopRight() {
        return topRight;
    }

    public void setTopRight(Point topRight) {
        this.topRight = topRight;
    }

    public Point getBotttomRight() {
        return botttomRight;
    }

    public void setBotttomRight(Point botttomRight) {
        this.botttomRight = botttomRight;
    }

    public float[] getElements() {
        return new float[]{
                topLeft.getX(),
                topLeft.getY(),
                bottomLeft.getX(),
                bottomLeft.getY(),
                topRight.getX(),
                topRight.getY(),
                botttomRight.getX(),
                botttomRight.getY(),
        };
    }
}
