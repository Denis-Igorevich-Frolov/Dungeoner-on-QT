#ifndef PARAGRAPHWITHBORDER_H
#define PARAGRAPHWITHBORDER_H

#include "../LabelWithBorder/labelwithborder.h"

#include <QGridLayout>
#include <QWidget>

namespace Ui {
class ParagraphWithBorder;
}

class ParagraphWithBorder : public QWidget
{
    Q_OBJECT

public:
    explicit ParagraphWithBorder(QWidget *parent = nullptr);
    ~ParagraphWithBorder();

    enum VerticalAlignment{
        TOP,
        BOTTOM,
        CENTER
    };

    void setText(QString text);
    void append(QString text);
    void setFontStyle(QColor textColor, QColor borderColor, int borderThickness, LabelWithBorder::FontType fontType);

    VerticalAlignment getVerticalAlignment() const;
    void setVerticalAlignment(VerticalAlignment newVerticalAlignment);
    void setHorizontalAlignment(LabelWithBorder::HorizontalAlignment newHorizontalAlignment);
    void setAlignment(VerticalAlignment verticalAlignment, LabelWithBorder::HorizontalAlignment horizontalAlignment);

    int getLineSpacing() const;
    void setLineSpacing(int newLineSpacing);

private:
    Ui::ParagraphWithBorder *ui;

    QVector<QString> lines;

    VerticalAlignment verticalAlignment = VerticalAlignment::CENTER;

    QColor textColor;
    QColor borderColor;
    int borderThickness;
    int lineSpacing = 0;
    LabelWithBorder::FontType fontType;
    QLayout *layout = new QVBoxLayout;
};

#endif // PARAGRAPHWITHBORDER_H
