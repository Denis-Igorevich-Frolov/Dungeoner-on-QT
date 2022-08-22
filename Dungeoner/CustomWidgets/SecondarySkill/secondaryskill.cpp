/************************************************************************
 *Данный класс представляет собой панельку вторичного навыка. Вынесен
 *в отдельный класс просто для выведения подсказки и гарантии того,
 *что все QGraphicsDropShadowEffect точно будут удалены в деструкторе.
 ************************************************************************/

#include "secondaryskill.h"
#include "qevent.h"
#include "ui_secondaryskill.h"
#include "SS_stylemaster.h"

SecondarySkill::SecondarySkill(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecondarySkill)
{
    ui->setupUi(this);

    //Без этого атрибута эвенты наведения мыши не будут вызываться
    setAttribute(Qt::WA_Hover);

    //Связывание сигналов из TooltipDisplayEvents на такие же из этого класса
    connect(&tooltipDisplayEvents,SIGNAL(ShowTooltip(QVector<QLabel*>)),this, SIGNAL(ShowTooltip(QVector<QLabel*>)));
    connect(&tooltipDisplayEvents,SIGNAL(RemoveTooltip()),this, SIGNAL(RemoveTooltip()));


    //Установка стилей
    ui->Inscription->setStyleSheet(SS_StyleMaster::SecondarySkillInscriptionStyle(12));
    ui->Value->setStyleSheet(SS_StyleMaster::SecondarySkillValueStyle());
    ui->Value->setFont(QFont("NumbersFont"));
    ui->Inscription->setFont(QFont("TextFont"));

    //Установка обводки текста
    borderInscription = new OutlineEffect();
    borderInscription->setOutlineThickness(1);

    ui->Inscription->setGraphicsEffect(borderInscription);
    ui->Inscription->setMargin(1);

    borderValue = new OutlineEffect();
    borderValue->setOutlineThickness(1);

    ui->Value->setGraphicsEffect(borderValue);
    ui->Value->setMargin(1);

    /*Установка значения по умолчанию необходима из-за изменения
     *межстрочного интервала в методе setValue. Если этого не сделать,
     *то текст будет неотцентрован.*/
    setValue(0);
}

SecondarySkill::~SecondarySkill()
{
    delete ui;
    delete borderInscription;
    delete borderValue;
}

int SecondarySkill::getValue() const
{
    return value;
}

/*Сеттер на переменную Value. Также устанавливает число в
 *лейбл Value и меняет его межстрочный интервал*/
void SecondarySkill::setValue(int newValue)
{
    /*Просто так в Qt межстрочный интервал не задать, приходится прибегать к
     *цыганским фокусам. Тут в QString переменную передаётся не просто значение,
     *а HTML абзац с CSS стилем, где прописан межстрочный интервал. Первый arg
     *передаёт значение межстрочного интервала (в данном случае 70%), а второй уже
     *сам текст. Также стоит помнить, что Qt больше не сможет корректно центровать
     *такой текст в лейбле. К счастью погрешность легко определить. При изменении
     *интервала сам размер строки тоже становится меньше, считая даже первую строку. Из-за
     *этой уменьшенной первой строки, и получается некоторый сдвиг вниз размером в срезанные
     *30% (при интервале в 70%) размера строки. Точно посчитав на глаз недостающие
     *пиксели, лейбл надо толкнуть нижним мердженом в CSS чуть-чуть вверх, компенсировав
     *размер уменьшенной первой строки. При этом толкать придётся именно лейбл, так
     *как попытки задать хоть какие-то отступы у изначально отредактированного абзаца
     *ни к чему не приводят.*/
    SValue = "<p style=\"line-height:%1%;\">%2</p>";

    //Ограничение стата для уменьшения шанса возможных переполнений
    if(newValue>9999999)
        newValue = 9999999;
    value = newValue;

    /*Установка разделительных пробелов у значения стата для большей читабельности.
     *Цель существования sValue в том, чтобы был посчитан размер строки и по ней уже бежал
     *цикл. finalValue при прочих обстоятельствах был бы не нужен, но здесь мы не просто
     *передаём значение в переменную QString, а при помощи arg подставляем необходимый текст
     *на место %2 в HTML абзац. finalValue и есть этот текст, который бедет передан в arg.
     *Использован prepend и обратный цикл из-за того, что эти разделители ставятся через каждые
     *3 числа с конца.*/
    QString sValue;
    QString finalValue;
    sValue.setNum(value);
    if(sValue.size()!=0){
        int j = 0;
        for(int i = sValue.size(); i>0; --i){
            finalValue.prepend(sValue[i-1]);
            ++j;
            if(sValue.size()!=3 && j==3){
                j = 0;
                finalValue.prepend(' ');
            }
        }
    }
    SValue = SValue.arg(70).arg(finalValue);
    ui->Value->setText(SValue);

    valueLabel->setText(SValue);
}

void SecondarySkill::setInscription(QString inscription)
{
    ui->Inscription->setText(inscription);
}

void SecondarySkill::setFontSize(int size)
{
    ui->Inscription->setStyleSheet(SS_StyleMaster::SecondarySkillInscriptionStyle(size));
}

/*Переопределения виртуальных функций QWidget для вызова сигнала вывода
 *или удаления подсказки. Вся логика происходит в классе TooltipDisplayEvents*/
void SecondarySkill::mousePressEvent(QMouseEvent *event)
{
    tooltipDisplayEvents.mousePressEvent(event);
}
void SecondarySkill::mouseReleaseEvent(QMouseEvent *event)
{
    tooltipDisplayEvents.mouseReleaseEvent(event);
}
void SecondarySkill::enterEvent(QEnterEvent *event)
{
    tooltipDisplayEvents.enterEvent(event);
}
void SecondarySkill::leaveEvent(QEvent *event)
{
    tooltipDisplayEvents.leaveEvent(event);
}
void SecondarySkill::mouseMoveEvent(QMouseEvent *event)
{
    tooltipDisplayEvents.mouseMoveEvent(event, this->width(), this->height(), this->geometry().y(), ScrollAreaHeight, ScrollAreaOffset);
}

int SecondarySkill::getScrollAreaOffset() const
{
    return ScrollAreaOffset;
}

void SecondarySkill::setScrollAreaOffset(int newScrollAreaOffset)
{
    ScrollAreaOffset = newScrollAreaOffset;
}

void SecondarySkill::setTooltipContent(QString fullName, QString formula, QString description)
{
    QLabel* fullNameLabel = new QLabel;
    fullNameLabel->setFont(QFont("TextFont"));
    fullNameLabel->setStyleSheet(SS_StyleMaster::TooltipTextStyle(27, "bdc440"));
    fullNameLabel->setText(fullName);
    fullNameLabel->setMaximumWidth(450);
    tooltipContent.append(fullNameLabel);

    QLabel* separator = new QLabel;
    separator->setFixedSize(450, 1);
    separator->setStyleSheet("background: #bdc440;");
    tooltipContent.append(separator);

    valueLabel = new QLabel;
    valueLabel->setFont(QFont("NumbersFont"));
    valueLabel->setStyleSheet(SS_StyleMaster::TooltipTextStyle(27, "cad160"));
    valueLabel->setText(QVariant(value).toString());
    valueLabel->setMaximumWidth(450);
    tooltipContent.append(valueLabel);

    QLabel* formulaLabel = new QLabel;
    formulaLabel->setFont(QFont("TextFont"));
    formulaLabel->setStyleSheet(SS_StyleMaster::TooltipTextStyle(23, "bdc440"));
    formulaLabel->setText(formula);
    formulaLabel->setMaximumWidth(450);
    tooltipContent.append(formulaLabel);

    QLabel* separator2 = new QLabel;
    separator2->setFixedSize(83, 13);
    separator2->setStyleSheet("background: url(:/Text-Block-1/Textures PNG/Separator-1.png);");
    tooltipContent.append(separator2);

    QLabel* descriptionLabel = new QLabel;
    descriptionLabel->setFont(QFont("TextFont"));
    descriptionLabel->setStyleSheet(SS_StyleMaster::TooltipTextStyle(18, "cad160"));
    descriptionLabel->setText(description);
    descriptionLabel->setMaximumWidth(450);
    tooltipContent.append(descriptionLabel);

    tooltipDisplayEvents.setTooltipContent(tooltipContent);
}

int SecondarySkill::getScrollAreaHeight() const
{
    return ScrollAreaHeight;
}

void SecondarySkill::setScrollAreaHeight(int newScrollAreaHeight)
{
    ScrollAreaHeight = newScrollAreaHeight;
}
