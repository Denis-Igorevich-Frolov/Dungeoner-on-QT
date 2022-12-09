/***********************************************************************************
 *Данный класс является всплывающей подсказкой с рамкой. Контент подсказки
 *передаётся в виде вектора лейблов. Сама подсказка имеет focusPolicy - NoFocus,
 *чтобы не перекрывать собой вызов ивентов.
 ***********************************************************************************/

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
     *избегания его удаления при высвобождении памяти содержимого лейаута в этом классе.
     *
     *Копирование производится просто передачей необходимых пораметров из старого лейбла
     *новому. Я знаю и про глубокое копирование, и про патерн прототип, но использовние
     *этого для копирования пары троек односложных лейблов не выигрывает ничего.*/
    int i = 0;
    for(QLabel* label : content){
        if(!dynamic_cast<QGridLayout*>(label->layout())){
            QLabel* newLabel = new QLabel;
            newLabel->setWordWrap(label->wordWrap());
            newLabel->setText(label->text());
            newLabel->setAlignment(Qt::AlignCenter);
            newLabel->setStyleSheet(label->styleSheet());
            newLabel->setMinimumSize(label->minimumSize());
            newLabel->setMaximumSize(label->maximumSize());
            newLabel->setFont(label->font());

            //Если текст лейбла пуст - это всегда разделитель, и эффекта обводки не требуется
            if(!newLabel->text().isEmpty()){
                OutlineEffect* border = new OutlineEffect;
                border->setOutlineThickness(2);
                newLabel->setGraphicsEffect(border);
                newLabel->setMargin(2);
            }

            layout->addWidget(newLabel);
        //Если Layout лейбля является QGridLayout, значит что этот лейбл - лейбл бонусов
        }else{
             QLabel* newLabel = new QLabel;
             QGridLayout* labelLayout = new QGridLayout;
             newLabel->setLayout(labelLayout);
            for(int i = 0; i < label->layout()->count(); i++){
                QLabel* bonusLabel;
                if(dynamic_cast<QLabel*>(label->layout()->itemAt(i)->widget()))
                    bonusLabel = static_cast<QLabel*>(label->layout()->itemAt(i)->widget());

                QGridLayout* grid = static_cast<QGridLayout*>(label->layout());
                int row = -1;
                int col = -1;
                //span обязателен в конструкторе getItemPosition, но он нам не нужен, так что эта переменная нигде не используется
                int span;
                grid->getItemPosition(i, &row, &col, &span, &span);

                QLabel* newBonusLabel = new QLabel;
                newBonusLabel->setWordWrap(bonusLabel->wordWrap());
                newBonusLabel->setText(bonusLabel->text());
                newBonusLabel->setAlignment(Qt::AlignCenter);
                newBonusLabel->setStyleSheet(bonusLabel->styleSheet());
                newBonusLabel->setMinimumSize(bonusLabel->minimumSize());
                newBonusLabel->setMaximumSize(bonusLabel->maximumSize());
                newBonusLabel->setFont(bonusLabel->font());
                labelLayout->addWidget(newBonusLabel, row, col, Qt::AlignCenter);
            }
            labelLayout->setContentsMargins(0, 0, 0, 0);
            newLabel->setMinimumSize(label->minimumSize());
            newLabel->setMaximumSize(label->maximumSize());

            layout->addWidget(newLabel);
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
