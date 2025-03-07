#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "view.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    qmlRegisterType<View>("Backend",1,0,"View");
    engine.loadFromModule("MatrixMoo", "Main");

    View *view = engine.rootObjects().at(0)->findChild<View*>("view");
    view->initialize(&engine);

    return app.exec();
}
