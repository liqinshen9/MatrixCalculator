#ifndef MATRIXBACKGROUND_H
#define MATRIXBACKGROUND_H
#include <QQuickPaintedItem>


class MatrixBackground: public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(bool has_scalar READ hasScalar() WRITE showScalar())

public:
    MatrixBackground(QQuickItem * parent = nullptr);
    void paint(QPainter * painter);
    bool hasScalar() {return has_scalar;}
    void showScalar(bool value);
private:
    bool has_scalar = false;
};

#endif // MATRIXBACKGROUND_H
