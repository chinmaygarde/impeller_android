package dev.flutter.impeller;

public class Paragraph {
    public long getHandle() {
        return handle;
    }

    private long handle = 0;

    Paragraph(long handle) {
        this.handle = handle;
    }

    private static native float ImpellerParagraphGetAlphabeticBaseline(long para);

    public float getAlphabeticBaseline() {
        return ImpellerParagraphGetAlphabeticBaseline(handle);
    }


    private static native float ImpellerParagraphGetHeight(long para);

    public float getHeight() {
        return ImpellerParagraphGetHeight(handle);
    }

    private static native float ImpellerParagraphGetIdeographicBaseline(long para);

    public float getIdeographicBaseline() {
        return ImpellerParagraphGetIdeographicBaseline(handle);
    }


    private static native int ImpellerParagraphGetLineCount(long para);

    public int getLineCount() {
        return ImpellerParagraphGetLineCount(handle);
    }


    private static native float ImpellerParagraphGetLongestLineWidth(long para);

    public float getLongestLineWidth() {
        return ImpellerParagraphGetLongestLineWidth(handle);
    }

    private static native float ImpellerParagraphGetMaxIntrinsicWidth(long para);

    public float getMaxIntrinsicWidth() {
        return ImpellerParagraphGetMaxIntrinsicWidth(handle);
    }

    private static native float ImpellerParagraphGetMaxWidth(long para);

    public float getMaxWidth() {
        return ImpellerParagraphGetMaxWidth(handle);
    }

    private static native float ImpellerParagraphGetMinIntrinsicWidth(long para);

    public float getMinIntrinsicWidth() {
        return ImpellerParagraphGetMinIntrinsicWidth(handle);
    }

    private static native void ImpellerParagraphRelease(long para);

    public void dispose() {
        ImpellerParagraphRelease(handle);
        handle = 0;
    }
}
