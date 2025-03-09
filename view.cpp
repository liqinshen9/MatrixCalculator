#include "view.h"
#include <QDebug>
#include <QString>

View::View(QQuickItem *parent):
    QQuickItem(parent)
{
    matrix = new MatrixModel();
}

void View::message(QString msg)
{
    //QQuickItem *button = this->findChild<QQuickItem*>("ButtonName");
    //button->setProperty("text",msg);

    if (msg == "apply_dimensions") {
        QQuickItem* n_dim = this->findChild<QQuickItem*>("n_dimension");
        QQuickItem* m_dim = this->findChild<QQuickItem*>("m_dimension");
        int n = n_dim->property("text").toInt();
        int m = m_dim->property("text").toInt();
        qDebug()<< n;
        qDebug()<< m;
    }

    if(msg=="toggle_scalars") {
        qDebug()<<msg;
    }

    if (msg == "row_reduce") {
        qDebug()<<msg;
    }

    if(msg=="solve") {
        qDebug()<<msg;
    }




}

void View::initialize(QQmlApplicationEngine* enginePtr)
{
    engine=enginePtr;
}
