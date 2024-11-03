package dev.flutter.impeller;

public class PathBuilder {
    public PathBuilder() {
        handle = ImpellerPathBuilderNew();
    }

    public void dispose() {
        ImpellerPathBuilderRelease(handle);
        handle = 0;
    }

    public long getHandle() {
        return handle;
    }

    private long handle = 0;

    public void addArc(Rect rect, float start_angle_degrees, float end_angle_degrees) {
        ImpellerPathBuilderAddArc(handle, rect.getElements(), start_angle_degrees, end_angle_degrees);
    }


    public static native void ImpellerPathBuilderAddArc(long builder, float[] rect, float start_angle_degrees, float end_angle_degrees);

    public static native void ImpellerPathBuilderAddOval(long builder, float[] rect);

    public void addOval(Rect rect) {
        ImpellerPathBuilderAddOval(handle, rect.getElements());
    }

    public static native void ImpellerPathBuilderAddRect(long builder, float[] rect);

    public void addRect(Rect rect) {
        ImpellerPathBuilderAddRect(handle, rect.getElements());
    }


    public static native void ImpellerPathBuilderAddRoundedRect(long builder, float[] rect, float[] rounding_radii);

    public void addRoundedRect(Rect rect, RoundingRadii radii) {
        ImpellerPathBuilderAddRoundedRect(handle, rect.getElements(), radii.getElements());
    }


    public static native void ImpellerPathBuilderClose(long builder);

    public void close() {
        ImpellerPathBuilderClose(handle);
    }


    public static native long ImpellerPathBuilderCopyPathNew(long builder, int fill);

    public Path copyPath(FillType fill) {
        return new Path(ImpellerPathBuilderCopyPathNew(handle, fill.ordinal()));
    }

    public static native void ImpellerPathBuilderCubicCurveTo(long builder, float[] cp1, float[] cp2, float[] end);

    public void cubicCurveTo(Point controlPoint1, Point controlPoint2, Point endPoint) {
        ImpellerPathBuilderCubicCurveTo(handle, controlPoint1.getElements(), controlPoint2.getElements(), endPoint.getElements());
    }

    public static native void ImpellerPathBuilderLineTo(long builder, float[] location);

    public void lineTo(Point point) {
        ImpellerPathBuilderLineTo(handle, point.getElements());
    }

    public static native void ImpellerPathBuilderMoveTo(long builder, float[] location);

    public void moveTo(Point point) {
        ImpellerPathBuilderMoveTo(handle, point.getElements());
    }


    public static native long ImpellerPathBuilderNew();

    public static native void ImpellerPathBuilderQuadraticCurveTo(long builder, float[] cp, float[] end);

    public void quadraticCurveTo(Point controlPoint, Point endPoint) {
        ImpellerPathBuilderQuadraticCurveTo(handle, controlPoint.getElements(), endPoint.getElements());
    }

    public static native void ImpellerPathBuilderRelease(long builder);

    public static native long ImpellerPathBuilderTakePathNew(long builder, int fill);

    public Path takePath(FillType fill) {
        return new Path(ImpellerPathBuilderTakePathNew(handle, fill.ordinal()));
    }
}

