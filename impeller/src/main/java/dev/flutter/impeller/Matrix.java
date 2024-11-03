package dev.flutter.impeller;

public class Matrix {
    public Matrix() {
        this.elements = new float[]{
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1
        };
    }

    public Matrix(float[] elements) {
        this.elements = elements;
    }

    private float[] elements;

    public float[] getElements() {
        return elements;
    }
}