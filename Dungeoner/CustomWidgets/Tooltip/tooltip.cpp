#include "tooltip.h"
#include "System/OutlineEffect/outlineeffect.h"
#include "ui_tooltip.h"
#include "T_stylemaster.h"

Tooltip::Tooltip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tooltip)
{
    ui->setupUi(this);

    //Установка стилей
    ui->Background->setStyleSheet(T_StyleMaster::BackgroundStyle());

    //Контент подсказки будет позиционироваться при помощи лейаута
    ui->Content->setLayout(layout);
}

Tooltip::~Tooltip()
{
    qDeleteAll(layout->findChildren<QWidget*>("", Qt::FindDirectChildrenOnly));
    delete layout;
    delete ui;
}

//Установка содержимого подсказки
void Tooltip::setContent(QVector<QLabel *> content)
{
    /*При установке нового контента сначала удаляется весь старый. Если лейаут не пуст,
     *то из него берётся первый итем, и память, выделенная на него, высвобождается. Так
     *происходит до тех, пока лейаут не опустеет, затем память высвобождается уже для
     *самого лейаута и выделяется вновь для нового пока ещё пустого.*/
    if (layout != NULL){
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != NULL)
        {
            delete item->widget();
            delete item;
        }
        delete layout;
    }
    layout = new QVBoxLayout(ui->Content);

    //Установка отступов лейаута
    layout->setContentsMargins(17, 12, 17, 12);
    layout->setSpacing(8);

    /*Здесь создаются дубликаты лейблов с контентом для разрыва связей с оригиналом и
     *избегания его удаления при высвобождении памяти содержимого лейаута в этом классе.*/
    int i = 0;
    for(QLabel* label : content){
        QLabel* newLabel = new QLabel;
        newLabel->setWordWrap(true);
        newLabel->setText(label->text());
        newLabel->setAlignment(Qt::AlignCenter);
        newLabel->setStyleSheet(label->styleSheet());
        newLabel->setMinimumSize(label->minimumSize());
        newLabel->setMaximumSize(label->maximumSize());
        newLabel->setFont(label->font());
        layout->addWidget(newLabel);

        //Если текст лейбла пуст - это всегда разделитель, и эффекта обводки не требуется
        if(!newLabel->text().isEmpty()){
            OutlineEffect* border = new OutlineEffect;
            border->setOutlineThickness(2);
            newLabel->setGraphicsEffect(border);
            newLabel->setMargin(2);
        }

        i++;
    }

    //Установка невидимых рамок. Подробнее в описании переменной invisibleFrame в заголовочном файле.
    setFixedSize(ui->Content->sizeHint()+invisibleFrame);
}

/*Переопределённая виртуальная функция класса QWidget. Во время этого эвента происходит
 *подгонка всех графических элементов под размер виджета с учётом невидимой рамки.*/
void Tooltip::resizeEvent(QResizeEvent *event)
{
    /*Переданый контент раздвигает фрейм Content, но в виде рекомендуемого размера (sizeHint).
     *Чтобы он корректно отображался, размер следует задать как фиксированный (FixedSize).*/
    ui->Content->setFixedSize(ui->Content->sizeHint());

    /*Заднему фону и рамке следует задать фиксированый размер, но так как невидимая рамка
     *раздвигает границы виджета, этим элементам следует вернуть изначальный размер виджета
     *без учёта невидимой рамки, так что следует вычесть её размер из размеров всего виджета.
     *
     *Подробнее о назначении невидимой рамки в описании переменной invisibleFrame в
     *заголовочном файле.*/
    if(this->size().rwidth()>0&&this->size().rheight()>0){
        ui->Background->setFixedSize(this->size()-invisibleFrame);
        ui->Border->setFixedSize(this->size()-invisibleFrame);
    }
}
