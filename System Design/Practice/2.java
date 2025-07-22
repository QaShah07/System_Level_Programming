// ❌ Violation: ReportGenerator must change to support new formats
public class ReportGenerator {
    public void generatePdf(Report r) { /*…*/ }
    public void generateHtml(Report r) { /*…*/ }
}

// ✅ Refactored: closed for modification, open for extension
public interface ReportFormatter {
    String format(Report r);
}

public class PdfFormatter implements ReportFormatter {
    public String format(Report r) { /*…*/ }
}

public class HtmlFormatter implements ReportFormatter {
    public String format(Report r) { /*…*/ }
}

public class ReportGenerator {
    private ReportFormatter formatter;
    public ReportGenerator(ReportFormatter fmt) { this.formatter = fmt; }
    public void generate(Report r) {
        String out = formatter.format(r);
        // … write out …
    }
}
