#ifndef VIEW_H
#define VIEW_H
#include <QQuickItem>
#include <QQmlApplicationEngine>

class View: public QQuickItem
{
    Q_OBJECT
public:
    View(QQuickItem *parent = nullptr);

    void initialize(QQmlApplicationEngine* enginePtr);
private:
    QQmlApplicationEngine* engine = nullptr;
};

#endif // VIEW_H
