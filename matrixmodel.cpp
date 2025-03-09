#include "matrixmodel.h"
#include <QDebug>

MatrixModel::MatrixModel()
{

}

void MatrixModel::applyDimension(int new_n, int new_m)
{
    qDebug()<<"doshidei";
    n = new_n;
    m = new_m;
    data.clear();
    for (int i = 0; i < n; i++){
        QVector<double> row = QVector<double>(m);
        data.append(row);
    }
    qDebug()<<"doshidei2";

}

double MatrixModel::getEntry(int row, int col)
{
    qDebug()<<"data dimensions:"<<data.length();
    return data[row][col];
}

void MatrixModel::setEntry(int row, int col, double value)
{
    data[row][col] = value;
}
