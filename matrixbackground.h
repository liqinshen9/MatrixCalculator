#ifndef MATRIXBACKGROUND_H
#define MATRIXBACKGROUND_H
#include <QQuickPaintedItem>


class MatrixBackground: public QQuickPaintedItem
{
    Q_OBJECT

public:
    MatrixBackground(QQuickItem * parent = nullptr);
    void paint(QPainter * painter);
};

#endif // MATRIXBACKGROUND_H
