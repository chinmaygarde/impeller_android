package dev.flutter.impeller;

public class Color {
    public float red = 0;
    public float green = 0;
    public float blue = 0;
    public float alpha = 0;

    public float[] getColorElements() {
        return new float[]{red, green, blue, alpha};
    }
}
