package dev.flutter.impeller;

public class ParagraphBuilder {
    public long getHandle() {
        return handle;
    }

    private long handle = 0;

    public ParagraphBuilder(TypographyContext context) {
        this.handle = ImpellerParagraphBuilderNew(context.getHandle());
    }

    private static native void ImpellerParagraphBuilderAddText(long builder, String text);

    public void addText(String text) {
        ImpellerParagraphBuilderAddText(handle, text);
    }

    private static native long ImpellerParagraphBuilderBuildParagraphNew(long builder, float width);

    public Paragraph build(float width) {
        return new Paragraph(ImpellerParagraphBuilderBuildParagraphNew(handle, width));
    }

    private static native long ImpellerParagraphBuilderNew(long context);

    private static native void ImpellerParagraphBuilderPopStyle(long builder);

    public void popStyle() {
        ImpellerParagraphBuilderPopStyle(handle);
    }
    
    private static native void ImpellerParagraphBuilderPushStyle(long builder, long style);

    public void pushStyle(ParagraphStyle style) {
        ImpellerParagraphBuilderPushStyle(handle, style.getHandle());
    }

    private static native void ImpellerParagraphBuilderRelease(long builder);

    public void dispose() {
        ImpellerParagraphBuilderRelease(handle);
        handle = 0;
    }

}
