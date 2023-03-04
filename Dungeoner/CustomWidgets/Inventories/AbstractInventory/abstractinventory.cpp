#include "abstractinventory.h"


void AbstractInventory::setPos(int XPos, int YPos)
{
    this->XPos = XPos;
    this->YPos = YPos;
}

void AbstractInventory::setPos(QPoint pos)
{
    XPos = pos.x();
    YPos = pos.y();
}
