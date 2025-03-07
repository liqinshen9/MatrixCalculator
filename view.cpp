#include "view.h"

View::View(QQuickItem *parent):
    QQuickItem(parent)
{

}

void View::initialize(QQmlApplicationEngine* enginePtr)
{
    engine=enginePtr;
}
