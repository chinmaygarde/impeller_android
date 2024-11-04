package dev.flutter.impeller;

import java.util.List;

public class ColorSource {
    private long handle = 0;

    public long getHandle() {
        return handle;
    }

    private static native long ImpellerColorSourceCreateConicalGradientNew(float[] start_center_point, float start_radius, float[] end_center_point, float end_radius, float[] color, float[] stops, int tile_mode, float[] transform);

    // Conical Gradient
    public ColorSource(Point start_center, float start_radius, Point end_center, float end_radius, List<Color> colors, List<Float> stops, TileMode mode, Matrix transform) {
        assert colors.size() == stops.size();
        float[] raw_colors = new float[colors.size() * 4];
        float[] raw_stops = new float[colors.size()];
        for (int i = 0; i < colors.size(); i++) {
            raw_stops[i] = stops.get(i);
            raw_colors[(i * 4) + 0] = colors.get(i).getRed();
            raw_colors[(i * 4) + 1] = colors.get(i).getGreen();
            raw_colors[(i * 4) + 2] = colors.get(i).getBlue();
            raw_colors[(i * 4) + 3] = colors.get(i).getAlpha();
        }
        this.handle = ImpellerColorSourceCreateConicalGradientNew(start_center.getElements(), start_radius, end_center.getElements(), end_radius, raw_colors, raw_stops, mode.ordinal(), transform.getElements());
    }

    private static native long ImpellerColorSourceCreateImageNew(long texture, int horizontal_tile_mode, int vertical_tile_mode, int sampling, float[] transform);

    // Image
    public ColorSource(Texture texture, TileMode horizontal_tile_mode, TileMode vertical_tile_mode, TextureSampling sampling_mode, Matrix transform) {
        this.handle = ImpellerColorSourceCreateImageNew(texture.getHandle(), horizontal_tile_mode.ordinal(), vertical_tile_mode.ordinal(), sampling_mode.ordinal(), transform.getElements());
    }

    private static native long ImpellerColorSourceCreateLinearGradientNew(float[] start_point, float[] end_point, float[] colors, float[] stops, int tile_mode, float[] transform);

    // Linear Gradient
    public ColorSource(Point start_point, Point end_point, List<Color> colors, List<Float> stops, TileMode tile_mode, Matrix transform) {
        assert colors.size() == stops.size();
        float[] raw_colors = new float[colors.size() * 4];
        float[] raw_stops = new float[colors.size()];
        for (int i = 0; i < colors.size(); i++) {
            raw_stops[i] = stops.get(i);
            raw_colors[(i * 4) + 0] = colors.get(i).getRed();
            raw_colors[(i * 4) + 1] = colors.get(i).getGreen();
            raw_colors[(i * 4) + 2] = colors.get(i).getBlue();
            raw_colors[(i * 4) + 3] = colors.get(i).getAlpha();
        }
        this.handle = ImpellerColorSourceCreateLinearGradientNew(start_point.getElements(), end_point.getElements(), raw_colors, raw_stops, tile_mode.ordinal(), transform.getElements());
    }

    private static native long ImpellerColorSourceCreateRadialGradientNew(float[] center_point, float radius, float[] colors, float[] stops, int tile_mode, float[] transform);

    // Radial Gradient
    public ColorSource(Point center, float radius, List<Color> colors, List<Float> stops, TileMode tile_mode, Matrix transform) {
        assert colors.size() == stops.size();
        float[] raw_colors = new float[colors.size() * 4];
        float[] raw_stops = new float[colors.size()];
        for (int i = 0; i < colors.size(); i++) {
            raw_stops[i] = stops.get(i);
            raw_colors[(i * 4) + 0] = colors.get(i).getRed();
            raw_colors[(i * 4) + 1] = colors.get(i).getGreen();
            raw_colors[(i * 4) + 2] = colors.get(i).getBlue();
            raw_colors[(i * 4) + 3] = colors.get(i).getAlpha();
        }
        this.handle = ImpellerColorSourceCreateRadialGradientNew(center.getElements(), radius, raw_colors, raw_stops, tile_mode.ordinal(), transform.getElements());
    }

    private static native long ImpellerColorSourceCreateSweepGradientNew(float[] center_point, float start, float end, float[] colors, float[] stops, int tile_mode, float[] transform);

    // Sweep Gradient
    public ColorSource(Point center, float start, float end, List<Color> colors, List<Float> stops, TileMode tile_mode, Matrix transform) {
        assert colors.size() == stops.size();
        float[] raw_colors = new float[colors.size() * 4];
        float[] raw_stops = new float[colors.size()];
        for (int i = 0; i < colors.size(); i++) {
            raw_stops[i] = stops.get(i);
            raw_colors[(i * 4) + 0] = colors.get(i).getRed();
            raw_colors[(i * 4) + 1] = colors.get(i).getGreen();
            raw_colors[(i * 4) + 2] = colors.get(i).getBlue();
            raw_colors[(i * 4) + 3] = colors.get(i).getAlpha();
        }
        this.handle = ImpellerColorSourceCreateSweepGradientNew(center.getElements(), start, end, raw_colors, raw_stops, tile_mode.ordinal(), transform.getElements());
    }

    private static native void ImpellerColorSourceRelease(long source);

    public void dispose() {
        ImpellerColorSourceRelease(handle);
        handle = 0;
    }

}
