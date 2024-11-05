package dev.flutter.impeller;

public class Color {
    static {
        Impeller.EnsureInitialized();
    }
    public Color() {
    }

    public Color(float red, float green, float blue, float alpha) {
        this.red = red;
        this.green = green;
        this.blue = blue;
        this.alpha = alpha;
    }

    public float getRed() {
        return red;
    }

    public void setRed(float red) {
        this.red = red;
    }

    public float getGreen() {
        return green;
    }

    public void setGreen(float green) {
        this.green = green;
    }

    public float getBlue() {
        return blue;
    }
    public void setBlue(float blue) {
        this.blue = blue;
    }

    public float getAlpha() {
        return alpha;
    }

    public void setAlpha(float alpha) {
        this.alpha = alpha;
    }

    private float red = 0;

    private float green = 0;

    private float blue = 0;

    private float alpha = 0;
}
