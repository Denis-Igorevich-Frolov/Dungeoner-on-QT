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

    numberOfVisibleRows = 4;
    numberOfVisibleColumns = 10;
    maxColumns = 10;

    installEventFilter(this);

    ui->InventoryScrollArea->verticalScrollBar()->setSingleStep(10);
    ui->InventoryScrollBar->setStyleSheet(GlobalStyleMaster::VerticalScrollBarStyle());

    inventoryScroller = QScroller::scroller(ui->InventoryScrollArea);
    //Прокрутка инвентаря возможна зажатой СКМ
    inventoryScroller->grabGesture(ui->InventoryScrollArea, QScroller::ScrollerGestureType::MiddleMouseButtonGesture);

    connect(startScrollTimer, &QTimer::timeout, this, &CharacterWindowInventory::inventoryScrollingStarted);

    /*Связывание слота InventoryScrollAreaScrolled с сигналом valueChanged у вертикального скроллбара в области
     *прокрутки для взаимосвязи этой области прокрутки и отдельного от неё скроллбара InventoryScrollBar.*/
    connect(ui->InventoryScrollArea->verticalScrollBar(), &QScrollBar::valueChanged,
            this, &CharacterWindowInventory::InventoryScrollAreaScrolled);
    /*По умолчанию скроллбар инвентаря имеет максимум в 0. Любое изменение количества
     *ячеек инвентаря переопределит это значение, когда то будет нужно.*/
    ui->InventoryScrollBar->setMaximum(0);

    for(int i = 0; i<numberOfVisibleRows; i++)
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

//Метод возвращающий адрес последней непустой ячейки. Последней считается самая правая нижняя ячейка
AbstractInventory::ItemIndex CharacterWindowInventory::getIndexOfLastNonEmptyCell()
{
    return AbstractInventory::getIndexOfLastNonEmptyCell(ui->Inventory);
}

AbstractInventory::ItemIndex CharacterWindowInventory::getIndexOfLastEmptyCell()
{
    return AbstractInventory::getIndexOfLastEmptyCell(ui->Inventory);
}

InventoryCell *CharacterWindowInventory::getLastEmptyCell()
{
    ItemIndex index = getIndexOfLastEmptyCell();
    auto Cell = ui->Inventory->itemAtPosition(index.row, index.col);
    if(dynamic_cast<InventoryCell*>(Cell->widget()))
        return static_cast<InventoryCell*>(Cell->widget());

    return nullptr;
}

void CharacterWindowInventory::addRowOfCellsToInventory()
{
    AbstractInventory::addRowOfCellsToInventory(this, ui->Inventory, ui->scrollAreaWidgetContents, ui->InventoryScrollArea->verticalScrollBar(), ui->InventoryScrollBar);

    for(int i = 0; i<maxColumns; i++){
        connect(static_cast<InventoryCell*>(ui->Inventory->itemAtPosition(row, i)->widget()),
                &InventoryCell::itemIsDropped, this, &CharacterWindowInventory::checkingInventorySizeChange);
        connect(static_cast<InventoryCell*>(ui->Inventory->itemAtPosition(row, i)->widget()),
                &InventoryCell::moveCellToEquipment, this, &CharacterWindowInventory::moveCellToEquipment);
        connect(static_cast<InventoryCell*>(ui->Inventory->itemAtPosition(row, i)->widget()),
                &InventoryCell::lockOccupiedCells, this, &CharacterWindowInventory::lockOccupiedCells);
        connect(static_cast<InventoryCell*>(ui->Inventory->itemAtPosition(row, i)->widget()),
                &InventoryCell::unlockOccupiedCells, this, &CharacterWindowInventory::unlockOccupiedCells);
        connect(static_cast<InventoryCell*>(ui->Inventory->itemAtPosition(row, i)->widget()),
                &InventoryCell::checkLockedCells, this, &CharacterWindowInventory::checkLockedCells);
        connect(static_cast<InventoryCell*>(ui->Inventory->itemAtPosition(row, i)->widget()),
                &InventoryCell::dragStarted, this, &CharacterWindowInventory::dragStarted);
        connect(static_cast<InventoryCell*>(ui->Inventory->itemAtPosition(row, i)->widget()),
                &InventoryCell::dragEnded, this, &CharacterWindowInventory::dragEnded);
    }
    row++;
}

void CharacterWindowInventory::removeRowOfCellsFromInventory()
{
    AbstractInventory::removeRowOfCellsFromInventory(this, ui->Inventory, ui->scrollAreaWidgetContents, ui->InventoryScrollArea->verticalScrollBar(), ui->InventoryScrollBar);
    row--;
}

void CharacterWindowInventory::InventoryScrollAreaScrolled(int value)
{
    ui->InventoryScrollBar->setValue(value);
}

void CharacterWindowInventory::on_InventoryScrollBar_valueChanged(int value)
{
    //При скролле скроллбара подсказка пропадает так как всё-равно ячейка инвентаря уедет
    emit RemoveTooltip();

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
    scrolling();
}

/*Проверка того стоит ли изменять размер инвентаря. Если в последнюю ячейку положат итем,
 *то прибавится ещё одна пустая строка. Если из предпоследней ячейки уберут итем, то все
 *строки нижние кроме одной удалятся. Таким образом под итемами всегда будет одна пустая
 *строка. Количество строк в инвентаре окна персонажа не может быть меньше 4.*/
void CharacterWindowInventory::checkingInventorySizeChange(int col, int row)
{
    if(row == this->row-1){
        addRowOfCellsToInventory();
    }else{
        ItemIndex lastNonEmptyCell = getIndexOfLastNonEmptyCell();
        /*От this->row отнимается 1 чтобы привести абсолютное значение к индексу, начинающимся с 0. К
         *lastNonEmptyCell.row прибавляется 1 так как под итемами нужно оставить одну пустую строку*/
        if(this->row > 4 && this->row-1 > lastNonEmptyCell.row+1){
            while (this->row-1 > lastNonEmptyCell.row+1) {
                removeRowOfCellsFromInventory();
                if(this->row<=4)
                    break;
            }
        }
    }

}

//метод реализующий логику прокрутки перетаскиваемым итемом
void CharacterWindowInventory::scrolling()
{
    //Во-первых Скроллинг возможен только в пределах области скролла, иначе он сразу прекращается
    if((QCursor::pos().x() >= XPos) &&
            (QCursor::pos().x() <=XPos + ui->InventoryScrollArea->size().width()) &&
            (QCursor::pos().y() >= YPos + ui->InventoryScrollArea->pos().y()) &&
            (QCursor::pos().y() <= YPos + ui->InventoryScrollArea->pos().y() +  ui->InventoryScrollArea->height())){
        /*Если прямо сейчас начать прокрутку, то она будет рздражающе происходить при попытке вытянуть итем за пределы инвентаря. Для избежания
         *этого есть небольшая задержка, дающее время переместить итем куда надо и одновременно почти не заметная, если нужно проскроллить инвентарь*/
        if(inventoryScroller->state() != QScroller::Scrolling && !startScrollTimer->isActive() && !inventoryScrollingIsStarted){
            startScrollTimer->start(700);
        }

        //Теперь прокрутка начнётся только по истечении таймера startScrollTimer
        if(inventoryScrollingIsStarted){
            //Задание алгоритма замедления прокрутки ближе к концу
            inventoryScrollerProperties.setScrollMetric(QScrollerProperties::ScrollingCurve, QEasingCurve(QEasingCurve::OutBack));
            inventoryScroller->setScrollerProperties(inventoryScrollerProperties);

            /*У прокрутки есть 2 скорости: медленная запускается в диапазоне от 50 до 15 пикселей от края, быстрая же от 15 пикседей до 0.
             *Им соответствует скорость 0.09 и 0.3. Так как в функцию scrollTo передаётся время до перехода в конечную точку, а не скорость,
             *которая в моём случае мне нужна одинакого постоянной, это время вычисляется каждый раз заного. Зная расстояние (значение
             *скроллбара) и скорость, легко вычислить время.
             *enum inventoryScrollerState требуется для предотвращения многократного вызова scrollTo в рамках одной скорости, при этом
             *он позволяет свободно переключиться на другую.*/
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
        startScrollTimer->stop();
        inventoryScroller->stop();
        inventoryScrollingIsStarted = false;
        inventoryScrollerState = STOPPED;
    }
}

bool CharacterWindowInventory::eventFilter(QObject *object, QEvent *event)
{
    if(event->type() == QEvent::DragMove || event->type() == QEvent::DragEnter){
        if(dynamic_cast<InventoryCell*>(object) || object == this){
            scrolling();
        }
    }else if(event->type() == QEvent::Drop){
        if(dynamic_cast<InventoryCell*>(object)){
            startScrollTimer->stop();
            inventoryScroller->stop();
            inventoryScrollingIsStarted = false;
            inventoryScrollerState = STOPPED;
        }
    /*Эвент HoverMove никогда не вызозовется при зажатой кнопке мыши и обязательно вызовется при её отпускании,
     *что является отличным маркером того, что итем сброшен, и сброшен в данном случае мимо ячейки*/
    }else if(object == this && event->type() == QEvent::HoverMove){
        startScrollTimer->stop();
        inventoryScroller->stop();
        inventoryScrollingIsStarted = false;
        inventoryScrollerState = STOPPED;
    }

    return false;
}

void CharacterWindowInventory::dragEnterEvent(QDragEnterEvent *event)
{
    /*На самом деле никакой Drag&Drop инвентарь не реализует. Но так как HoverMove никогда не вызывается при зажатой кнопке мыши,
     *а перетаскивание именно так и реализованно, для скролла подведением перетаскиваемым итемом к краю мне всё равно нужен
     *какой-нибудь эвент, который вызывался бы от движения мыши, здесь таким эвентом стал DragMove. Он будет вызываться только
     *в пределах InventoryScrollArea, чтобы не смущать лишний раз никого изменившимся курсором готовности к дропу.
     *Нужно это для того, чтобы инвентарь скролился даже если курсор находится между ячейками и не вызывает их DragMove.*/
    if((QCursor::pos().y() >= YPos + ui->InventoryScrollArea->pos().y()) &&
            (QCursor::pos().y() <= YPos + ui->InventoryScrollArea->pos().y() + ui->InventoryScrollArea->height())){
        QStringList formats = event->mimeData()->formats();
        if(formats.contains("Item")) {
            event->acceptProposedAction();
        }
    }
}
