#ifndef VIEW_H
#define VIEW_H
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include "matrixmodel.h"


class View: public QQuickItem
{
    Q_OBJECT
public:
    View(QQuickItem *parent = nullptr);
    Q_INVOKABLE void message(QString msg);

    void initialize(QQmlApplicationEngine* enginePtr);

private:
    QQmlApplicationEngine* engine = nullptr;
    MatrixModel* matrix = nullptr;
};

#endif // VIEW_H
