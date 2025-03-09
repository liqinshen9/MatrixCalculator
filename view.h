#ifndef VIEW_H
#define VIEW_H
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include "matrixmodel.h"


class View: public QQuickItem
{
    Q_OBJECT
public:
    View(QQuickItem *parent = nullptr);
    Q_INVOKABLE void message(QString msg);
    void initialize(QQmlApplicationEngine* enginePtr);
    void printMatrix();
    void applyDimension();

private:
    QQmlApplicationEngine* engine = nullptr;
    MatrixModel* matrix = nullptr;

public slots:
    void saveMatrix();
};

#endif // VIEW_H
