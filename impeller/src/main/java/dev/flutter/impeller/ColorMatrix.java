package dev.flutter.impeller;

public class ColorMatrix {
    public ColorMatrix() {
        this.elements = new float[]{
                1, 0, 0, 0, 0,
                0, 1, 0, 0, 0,
                0, 0, 1, 0, 0,
                0, 0, 0, 1, 0
        };
    }

    public ColorMatrix(float[] elements) {
        this.elements = elements;
    }

    public float[] getElements() {
        return elements;
    }

    private float[] elements;
}
