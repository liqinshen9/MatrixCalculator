#include "matrixmodel.h"
#include <QDebug>

MatrixModel::MatrixModel()
{
}

void MatrixModel::applyDimension(int new_n, int new_m)
{
    n = new_n;
    m = new_m;
    data.clear();
    for (int i = 0; i < n; i++){
        QVector<double> row = QVector<double>(m);
        data.append(row);
    }
}

double MatrixModel::getEntry(int row, int col)
{
    //qDebug()<<"data dimensions:"<<data.length();
    return data[row][col];
}

void MatrixModel::setEntry(int row, int col, double value)
{
    data[row][col] = value;
}

void MatrixModel::swapRows(int row1, int row2)
{
    QVector<double> temp = data[row1];
    data[row1] = data[row2];
    data[row2] = temp;
}

QVector<double> MatrixModel::multiplyRow(QVector<double> row, double factor)
{
    QVector<double> output(row.length());
    for (int i = 0; i < row.length(); i++) {
        output[i] = row[i] * factor;
    }
    return output;
}

QVector<double> MatrixModel::subtractRow(QVector<double> row, QVector<double> subtract)
{
    QVector<double> output(row.length());
    for (int i = 0; i < row.length(); i++) {
        output[i] = row[i] - subtract[i];
    }
    return output;
}

void MatrixModel::rowReduce()
{

}

