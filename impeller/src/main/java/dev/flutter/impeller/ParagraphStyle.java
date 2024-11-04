package dev.flutter.impeller;

public class ParagraphStyle {
    private long handle = 0;

    public long getHandle() {
        return handle;
    }

    private static native long ImpellerParagraphStyleNew();

    public ParagraphStyle() {
        this.handle = ImpellerParagraphStyleNew();
    }

    private static native void ImpellerParagraphStyleRelease(long para);

    public void dispose() {
        ImpellerParagraphStyleRelease(handle);
        handle = 0;
    }


    private static native void ImpellerParagraphStyleSetBackground(long para, long paint);

    public void setBackground(Paint paint) {
        ImpellerParagraphStyleSetBackground(handle, paint.getHandle());
    }

    private static native void ImpellerParagraphStyleSetFontFamily(long para, String family);

    public void setFamily(String family) {
        ImpellerParagraphStyleSetFontFamily(handle, family);
    }

    private static native void ImpellerParagraphStyleSetFontSize(long para, float size);

    public void setFontSize(float size) {
        ImpellerParagraphStyleSetFontSize(handle, size);
    }


    private static native void ImpellerParagraphStyleSetFontStyle(long para, int font_style);

    public void setFontStyle(FontStyle style) {
        ImpellerParagraphStyleSetFontStyle(handle, style.ordinal());
    }


    private static native void ImpellerParagraphStyleSetFontWeight(long para, int font_weight);

    public void setFontWeight(FontWeight weight) {
        ImpellerParagraphStyleSetFontWeight(handle, weight.ordinal());
    }

    private static native void ImpellerParagraphStyleSetForeground(long para, long paint);

    public void setForeground(Paint paint) {
        ImpellerParagraphStyleSetForeground(handle, paint.getHandle());
    }

    private static native void ImpellerParagraphStyleSetHeight(long para, float height);

    public void setHeight(float height) {
        ImpellerParagraphStyleSetHeight(handle, height);
    }

    private static native void ImpellerParagraphStyleSetLocale(long para, String locale);

    public void setLocale(String locale) {
        ImpellerParagraphStyleSetLocale(handle, locale);
    }

    private static native void ImpellerParagraphStyleSetMaxLines(long para, int max_lines);

    public void setMaxLines(int max_lines) {
        ImpellerParagraphStyleSetMaxLines(handle, max_lines);
    }

    private static native void ImpellerParagraphStyleSetTextAlignment(long para, int text_alignment);

    public void setTextAlignment(TextAlignment alignment) {
        ImpellerParagraphStyleSetTextAlignment(handle, alignment.ordinal());
    }

    private static native void ImpellerParagraphStyleSetTextDirection(long para, int text_direction);

    public void setTextDirection(TextDirection direction) {
        ImpellerParagraphStyleSetTextDirection(handle, direction.ordinal());
    }


}
