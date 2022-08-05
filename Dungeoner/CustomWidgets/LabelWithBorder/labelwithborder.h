#ifndef LABELWITHBORDER_H
#define LABELWITHBORDER_H

#include <QWidget>

namespace Ui {
class LabelWithBorder;
}

class LabelWithBorder : public QWidget
{
    Q_OBJECT

public:
    explicit LabelWithBorder(QWidget *parent = nullptr);
    ~LabelWithBorder();

    //Устанавливает текст для LableText
    void setText(QString text);

    /*От этого энума будет зависить шрифт, сама же
     *замена шрита происходит в сетере fontType*/
    enum FontType{
        TEXT,
        NUMBERS
    };

    enum HorizontalAlignment{
        LEFT,
        RIGHT,
        CENTER
    };

    FontType getFontType() const;
    void setFontStyle(QColor textColor, QColor borderColor, int borderThickness, FontType fontType);

    const QString &getText() const;

    HorizontalAlignment getHorizontalAlignment() const;
    void setHorizontalAlignment(HorizontalAlignment newHorizontalAlignment);

private:
    Ui::LabelWithBorder *ui;

    //Автоматически инициализируем экземпляр энума значением по умолчанию
    FontType fontType = FontType::TEXT;
    HorizontalAlignment horizontalAlignment = HorizontalAlignment::CENTER;

    void paintEvent(QPaintEvent *event) override;

    QString text;
    int borderThickness = 0;
    QColor textColor;
    QColor borderColor;
};

#endif // LABELWITHBORDER_H
