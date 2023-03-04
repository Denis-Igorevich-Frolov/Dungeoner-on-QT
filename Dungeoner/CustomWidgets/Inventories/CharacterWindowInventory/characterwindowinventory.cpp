#include "characterwindowinventory.h"
#include "qeasingcurve.h"
#include "qevent.h"
#include "qmimedata.h"
#include "qscroller.h"
#include "ui_characterwindowinventory.h"
#include "Global/GlobalStyleMaster.h"

CharacterWindowInventory::CharacterWindowInventory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CharacterWindowInventory)
{
    ui->setupUi(this);

    installEventFilter(this);

    ui->InventoryScrollArea->verticalScrollBar()->setSingleStep(10);
    ui->InventoryScrollBar->setStyleSheet(GlobalStyleMaster::VerticalScrollBarStyle());

    inventoryScroller = QScroller::scroller(ui->InventoryScrollArea);
    inventoryScroller->grabGesture(ui->InventoryScrollArea, QScroller::ScrollerGestureType::MiddleMouseButtonGesture);
    startScrollTimer->installEventFilter(this);
    connect(startScrollTimer, &QTimer::timeout, this, &CharacterWindowInventory::inventoryScrollingStarted);

    /*Связывание слота InventoryScrollAreaScrolled с сигналом valueChanged
     *у вертикального скроллбара в области прокрутки ScrollAreaSecondarySkills.*/
    connect(ui->InventoryScrollArea->verticalScrollBar(), &QScrollBar::valueChanged,
            this, &CharacterWindowInventory::InventoryScrollAreaScrolled);
    /*По умолчанию скроллбар инвентаря имеет максимум в 0. Любое изменение количества
     *ячеек инвентаря переопределит это значение, когда то будет нужно.*/
    ui->InventoryScrollBar->setMaximum(0);

    for(int i = 0; i<4; i++)
        CharacterWindowInventory::addRowOfCellsToInventory();
}

CharacterWindowInventory::~CharacterWindowInventory()
{
    delete ui;
}

InventoryCell* CharacterWindowInventory::getCell(int row, int column)
{
    if(ui->Inventory->rowCount()<row)
        return nullptr;
    if(ui->Inventory->columnCount()<column)
        return nullptr;

    if(dynamic_cast<InventoryCell*>(ui->Inventory->itemAtPosition(row, column)->widget()))
        return static_cast<InventoryCell*>(ui->Inventory->itemAtPosition(row, column)->widget());
    else
        return nullptr;
}

void CharacterWindowInventory::addRowOfCellsToInventory()
{
    /*В строке всегда 10 ячеек, так что вычислить количество строк легко. Преимущество такого способа перед
     *rowCount в том, что rowCount возвращет 1, даже если строк вообще нет, а тут результат однозначный.*/
    int row = ui->Inventory->count()/10;

    /*row показывает текущее количество строк. Учитывая, что одна сейчас прибавися, row 3 означает, что
     *в таблице будет 4 строки, а 4 строки - это тот размер таблицы, который прокрутки не требует.*/
    if(row>3){
        //Размер области прокрутки задаётся жёстко, чтобы избежать дёргания лейаута при добавлении новых строк
        ui->scrollAreaWidgetContents->setFixedHeight(308 + 70*(row-3) + 4*(row-4));
        //Установка максимума скроллбаров равного суммарной высоте с учётом отствупов всех строк после четвёртой.
        int maximum = 70*(row-3) + 4*(row-4);
        ui->InventoryScrollArea->verticalScrollBar()->setMaximum(maximum);
        ui->InventoryScrollBar->setMaximum(maximum);
    }else{
        //Иначе прокрутка не требуется, и максимум скроллбаров обнуляется
        ui->InventoryScrollArea->verticalScrollBar()->setMaximum(0);
        ui->InventoryScrollBar->setMaximum(0);
    }

    //Создание новой строки ячеек
    for(int i = 0; i<10; i++){
        InventoryCell* cell = new InventoryCell();
        cell->installEventFilter(this);
        cell->setFixedSize(68, 68);
        /*Учитывая что row всегда показывает текущее количество ячеек, то есть на
         *1 меньше, чем будет, то его можно вставлять как индекс с отсчётом от 0*/
        ui->Inventory->addWidget(cell, row, i, Qt::AlignTop);

        QRect rect = cell->geometry();
        rect.setY(5 + 74*row);
        cell->setGeometry(rect);
    }
}

void CharacterWindowInventory::removeRowOfCellsFromInventory()
{
    /*В строке всегда 10 ячеек, так что вычислить количество строк легко. Преимущество такого способа перед
     *rowCount в том, что rowCount возвращет 1, даже если строк вообще нет, а тут результат однозначный.*/
    int row = ui->Inventory->count()/10;

    /*row показывает текущее количество строк. Учитывая, что одна сейчас удалится, row 5 означает, что в
     *таблице останется 4 строки, а 4 строки - это тот размер таблицы, который прокрутки не требует.*/
    if(row>5){
        //Размер области прокрутки задаётся жёстко, чтобы избежать дёргания лейаута при добавлении новых строк
        ui->scrollAreaWidgetContents->setFixedHeight(308 + 70*(row-5) + 4*(row-6));
        //Установка максимума скроллбаров равного суммарной высоте с учётом отствупов всех строк после четвёртой.
        int maximum = 70*(row-5) + 4*(row-6);
        ui->InventoryScrollArea->verticalScrollBar()->setMaximum(maximum);
        ui->InventoryScrollBar->setMaximum(maximum);
    }else{
        //Размер области прокрутки задаётся жёстко, чтобы избежать дёргания лейаута при добавлении новых строк
        ui->scrollAreaWidgetContents->setFixedHeight(304);
        //Иначе прокрутка не требуется, и максимум скроллбаров обнуляется
        ui->InventoryScrollArea->verticalScrollBar()->setMaximum(0);
        ui->InventoryScrollBar->setMaximum(0);
    }

    //В инвентаре не может быть менее 4 строк
    if(row<=4)
        return;

    //Удаление строки ячеек
    for(int i = 0; i<10; i++){
        //Учитывая что row всегда показывает текущее количество ячеек, то его надо привести к индексу с отсчётом от 0
        delete ui->Inventory->itemAtPosition(row-1, i)->widget();
        ui->Inventory->removeItem(ui->Inventory->itemAtPosition(row-1, i));
    }
}

void CharacterWindowInventory::InventoryScrollAreaScrolled(int value)
{
    ui->InventoryScrollBar->setValue(value);
}

void CharacterWindowInventory::on_InventoryScrollBar_valueChanged(int value)
{
    ///!!!!!!!!
//    //При скролле скроллбара подсказка пропадает так как всё-равно окошко стата уезжает
//    RemoveTooltip();

    ui->InventoryScrollArea->verticalScrollBar()->setValue(value);
}

void CharacterWindowInventory::on_InventoryScrollBar_actionTriggered(int action)
{
    /*Звук проигрывается только при нажатии на стрелки прибавки и убавки.
     *Цифры в проверке - это id этих ивентов*/
    if(action==1||action==2)
        Global::mediaplayer.playSound(QUrl::fromLocalFile("qrc:/Sounds/Sounds/Click1.wav"), MediaPlayer::SoundsGroup::SOUNDS);
}

void CharacterWindowInventory::inventoryScrollingStarted()
{
    inventoryScrollingIsStarted = true;
    startScrollTimer->stop();
    QEvent* event = new QEvent(QEvent::DragMove);
    eventFilter(this, event);
    delete event;
}

void CharacterWindowInventory::scrollInventory(int Ypos)
{
    if(!inventoryIsScrolled){
        inventoryIsScrolled = true;
        ui->InventoryScrollArea->verticalScrollBar()->setValue(ui->InventoryScrollArea->verticalScrollBar()->value()-Ypos);
    }
}

bool CharacterWindowInventory::eventFilter(QObject *object, QEvent *event)
{
    if(event->type() == QEvent::DragMove || event->type() == QEvent::DragEnter){
        if(dynamic_cast<InventoryCell*>(object) || object == this){
            if((QCursor::pos().x() >= XPos) &&
                    (QCursor::pos().x() <=XPos + ui->InventoryScrollArea->size().width()) &&
                    (QCursor::pos().y() >= YPos + ui->InventoryScrollArea->pos().y()) &&
                    (QCursor::pos().y() <= YPos + ui->InventoryScrollArea->pos().y() +  ui->InventoryScrollArea->height())){
                if(inventoryScroller->state() != QScroller::Scrolling && !startScrollTimer->isActive() && !inventoryScrollingIsStarted){
                    startScrollTimer->start(700);
                }

                if(inventoryScrollingIsStarted){
                    inventoryScrollerProperties.setScrollMetric(QScrollerProperties::ScrollingCurve, QEasingCurve(QEasingCurve::OutBack));
                    inventoryScroller->setScrollerProperties(inventoryScrollerProperties);

                    if((QCursor::pos().y() <= YPos + ui->InventoryScrollArea->pos().y() + 15) && inventoryScrollerState != FAST_SPEED){
                        inventoryScroller->scrollTo(QPointF(0,0), (ui->InventoryScrollArea->verticalScrollBar()->value())/0.3);
                        inventoryScrollerState = FAST_SPEED;
                    }else if((QCursor::pos().y() < YPos + ui->InventoryScrollArea->pos().y() + 50) &&
                             (QCursor::pos().y() > YPos + ui->InventoryScrollArea->pos().y() + 15) &&
                             inventoryScrollerState != SLOW_SPEED){
                        inventoryScroller->scrollTo(QPointF(0,0), (ui->InventoryScrollArea->verticalScrollBar()->value())/0.09);
                        inventoryScrollerState = SLOW_SPEED;
                    }else if((QCursor::pos().y() >= YPos + ui->InventoryScrollArea->pos().y() + ui->InventoryScrollArea->height() -15)
                             && inventoryScrollerState != FAST_SPEED){
                        inventoryScroller->scrollTo(QPointF(0,ui->InventoryScrollArea->verticalScrollBar()->maximum()),
                                                    (ui->InventoryScrollArea->verticalScrollBar()->maximum()-ui->InventoryScrollArea->verticalScrollBar()->value())/0.3);
                        inventoryScrollerState = FAST_SPEED;
                    }else if((QCursor::pos().y() > YPos + ui->InventoryScrollArea->pos().y() + ui->InventoryScrollArea->height() -50) &&
                             (QCursor::pos().y() < YPos + ui->InventoryScrollArea->pos().y() + ui->InventoryScrollArea->height() -15) &&
                             inventoryScrollerState != SLOW_SPEED){
                        inventoryScroller->scrollTo(QPointF(0,ui->InventoryScrollArea->verticalScrollBar()->maximum()),
                                                    (ui->InventoryScrollArea->verticalScrollBar()->maximum()-ui->InventoryScrollArea->verticalScrollBar()->value())/0.09);
                        inventoryScrollerState = SLOW_SPEED;
                    }else if((QCursor::pos().y() >= YPos + ui->InventoryScrollArea->pos().y() + 50) &&
                             (QCursor::pos().y() <= YPos + ui->InventoryScrollArea->pos().y() + ui->InventoryScrollArea->height() - 50)){
                        inventoryScroller->stop();
                        inventoryScrollingIsStarted = false;
                        inventoryScrollerState = STOPPED;
                    }
                }
            }else{
                inventoryScroller->stop();
                inventoryScrollingIsStarted = false;
                inventoryScrollerState = STOPPED;
            }
        }
    }else if(event->type() == QEvent::Drop){
        if(dynamic_cast<InventoryCell*>(object)){
            inventoryScroller->stop();
            inventoryScrollingIsStarted = false;
            inventoryScrollerState = STOPPED;
        }
    }else if(object == this && event->type() == QEvent::HoverMove){
        inventoryScroller->stop();
        inventoryScrollingIsStarted = false;
        inventoryScrollerState = STOPPED;
    }

    return false;
}

void CharacterWindowInventory::dragEnterEvent(QDragEnterEvent *event)
{
    if((QCursor::pos().y() >= YPos + ui->InventoryScrollArea->pos().y()) &&
            (QCursor::pos().y() <= YPos + ui->InventoryScrollArea->pos().y() + ui->InventoryScrollArea->height())){
        QStringList formats = event->mimeData()->formats();
        if(formats.contains("Item")) {
            event->acceptProposedAction();
        }
    }
}
