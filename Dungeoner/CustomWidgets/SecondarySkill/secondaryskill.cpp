/*Данный класс представляет собой панельку вторичного навыка. Вынесен
 *в отдельный класс просто для выведения подсказки и гарантии того,
 *что все QGraphicsDropShadowEffect точно будут удалены в деструкторе.*/

#include "secondaryskill.h"
#include "qevent.h"
#include "ui_secondaryskill.h"
#include "stylemaster.h"

SecondarySkill::SecondarySkill(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecondarySkill)
{
    ui->setupUi(this);

    //Без этого атрибута эвенты наведения мыши не будут вызываться
    setAttribute(Qt::WA_Hover);

    //Связывание сигналов из TooltipDisplayEvents на такие же из этого класса
    connect(&tooltipDisplayEvents,SIGNAL(ShowTooltip()),this, SIGNAL(ShowTooltip()));
    connect(&tooltipDisplayEvents,SIGNAL(RemoveTooltip()),this, SIGNAL(RemoveTooltip()));

    //Установка теней текста
    shadow1 = new QGraphicsDropShadowEffect(this);
    shadow1->setOffset(1, 1);
    shadow1->setColor(QColor(32, 29, 16));

    ui->Inscription->setStyleSheet(StyleMaster::SecondarySkillInscriptionStyle(12));
    ui->Inscription->setGraphicsEffect(shadow1);

    shadow2 = new QGraphicsDropShadowEffect(this);
    shadow2->setOffset(1, 1);
    shadow2->setColor(QColor(32, 29, 16));

    ui->Value->setStyleSheet(StyleMaster::SecondarySkillValueStyle());
    ui->Value->setGraphicsEffect(shadow2);

    /*Установка значения по умолчанию необходима из-за изменения
     *межстрочного интервала в методе setValue. Если этого не сделать,
     *то текст будет неотцентрован.*/
    setValue(0);
}

SecondarySkill::~SecondarySkill()
{
    delete shadow1;
    delete shadow2;
    delete ui;
}

long SecondarySkill::getValue() const
{
    return value;
}

/*Сеттер на переменную Value. Также устанавливает число в
 *лейбл Value и меняет его межстрочный интервал*/
void SecondarySkill::setValue(long newValue)
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
}

void SecondarySkill::setInscription(QString inscription)
{
    ui->Inscription->setText(inscription);
}

void SecondarySkill::setFontSize(int size)
{
    ui->Inscription->setStyleSheet(StyleMaster::SecondarySkillInscriptionStyle(size));
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
    tooltipDisplayEvents.mouseMoveEvent(event, this->width(), this->height());
}
