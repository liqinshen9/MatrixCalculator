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
    if (msg == "apply_dimensions") {
        applyDimension();
    }

    if(msg=="toggle_scalars") {
        if (matrix->hasScalars()){
            matrix->showScalars(false);
            applyDimension();
        }else{
            matrix->showScalars(true);
            applyDimension();
        }
    }

    if (msg == "row_reduce") {
        matrix->rowReduce();
        printMatrix();
    }

    if(msg=="solve") {
        matrix->solve();
        printMatrix();
    }
}

void View::printMatrix()
{
    int n = matrix->getN();
    int m = matrix->getM();
    QQuickItem *matrix_grid = this->findChild<QQuickItem*>("matrix_grid");

    for (int i = 0;i<matrix_grid->childItems().length();i++){
        matrix_grid->childItems().at(i)->deleteLater();
    }

    matrix_grid->childItems().clear();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {  
            //Below are used when c++ write on window
            QQmlComponent component(engine, QUrl::fromLocalFile("MatrixMoo/MatrixEntry.qml"));
            QQuickItem * entry = qobject_cast<QQuickItem*>(component.create());
            entry->setParentItem(matrix_grid);
            entry->setParent(engine);
            entry->setProperty("text",matrix->getEntry(i,j));
            //otherwise, column will always be 2 as defined in main.qml
            connect(entry, SIGNAL(editingFinished()), this, SLOT(saveMatrix()));

        }
    }
}
void View::saveMatrix()
{
    int n = matrix->getN();
    int m = matrix->getM();
    QQuickItem * matrix_grid = this->findChild<QQuickItem*>("matrix_grid");
    for (int i = 0; i <n;i++) {
        for (int j = 0; j < m; j++) {
            QQuickItem * entry = matrix_grid->childItems().at(i*m+j);
            matrix->setEntry(i,j,entry->property("text").toDouble());
        }
    }
}

void View::applyDimension()
{
    QQuickItem* n_dim = this->findChild<QQuickItem*>("n_dimension");
    QQuickItem * m_dim = this->findChild<QQuickItem*>("m_dimension");
    int n = n_dim->property("text").toInt();
    int m = m_dim->property("text").toInt();
    QQuickItem* matrix_grid = this->findChild<QQuickItem*>("matrix_grid");
    matrix_grid->setWidth(m*100);
    matrix_grid->setHeight(n*60);
    if (matrix->hasScalars()) {
        matrix_grid->setWidth((m+1)*100);
        matrix->applyDimension(n,m+1);
        matrix_grid->setProperty("columns",m+1);
    }else{
        matrix->applyDimension(n,m);
        matrix_grid->setProperty("columns",m);
    }

    printMatrix();

}

void View::initialize(QQmlApplicationEngine* enginePtr)
{
    engine=enginePtr;
}
