#include "matrixbackground.h"
#include <QPen>
#include<QPainter>

MatrixBackground::MatrixBackground(QQuickItem*parent):
    QQuickPaintedItem(parent)
{

}

void MatrixBackground::paint(QPainter *painter) //overloaded paint function in QQuickPaintedItem
{
    int radius = 2;
    QPen pen;
    pen.setColor("black");
    pen.setWidth(radius*2);
    painter->setPen(pen);
    painter->setBrush(Qt::NoBrush);
    int lip_size = 8;
    painter->drawLine(QPoint(radius,0), QPoint(radius, height()));
    painter->drawLine(QPoint(0, radius), QPoint(lip_size, radius));
    painter->drawLine(QPoint(0, height()-radius), QPoint(lip_size, height()-radius));

    painter->drawLine(QPoint(width()-radius,0), QPoint(width()-radius, height()));
    painter->drawLine(QPoint(width(), radius), QPoint(width()-lip_size, radius));
    painter->drawLine(QPoint(width(), height()-radius), QPoint(width()-lip_size, height()-radius));

}
