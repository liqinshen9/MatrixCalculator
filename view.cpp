#include "view.h"
#include <QDebug>
#include <QString>

View::View(QQuickItem *parent):
    QQuickItem(parent)
{

}

void View::message(QString msg)
{
    //QQuickItem *button = this->findChild<QQuickItem*>("Button");
    qDebug()<<msg;


}

void View::initialize(QQmlApplicationEngine* enginePtr)
{
    engine=enginePtr;
}
