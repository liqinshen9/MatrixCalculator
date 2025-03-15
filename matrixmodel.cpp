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
    int row = 0;
    int col = 0;
    while (row<n && col <m) {
        if (data[row][col] == 0) {
            bool swapped = false;
            for (int i = row+1;i < n;i++) {//loop through each element below the current element
                if (data[i][col] != 0) {//if there exists non zero pivot below the pivot of current equal to 0 element, swap!
                    swapRows(row,i);
                    swapped = true;
                }
            }
            if (swapped == false) {//if there does not exist non zero pivot below the current pivot, skip this loop, col+= 1, row remain unchanged
                col+=1;
                continue;
            }
        }
        double factor = 1/data[row][col];
        data[row] = multiplyRow(data[row], factor);
        for (int i = row+1;i<n;i++) {
            factor = data[i][col];
            QVector<double> multiplied_row = multiplyRow(data[row], factor);
            data[i] = subtractRow(data[i], multiplied_row);
            //do the same for scalars

        }
        row+=1;
        col+=1;
    }
}

bool MatrixModel::hasContradiction()
{
    if(!has_scalars){return false;}
    for (int i = 0; i < n; i++) {
        if(data[i][data[i].length()-1] == 0) {
            continue;
        }
        bool all_zero = true;
        for (int j = 0; j < m - 1; j++) {
            if (data[i][j] != 0) {
                all_zero = false;
                break;
            }
        }
        if (all_zero) {
            return true;
        }
    }
    return false;
}


void MatrixModel::solve()
{
    if (!has_scalars) {return;}
    rowReduce();
    if(hasContradiction()) {
        return;
    }
    for (int row = n-1; row>0; row--) {
        int pivot = -1;
        for (int col = 0; col < m; col++) {
            if (data[row][col]!= 0) {
                pivot = col;
                break;
            }
        }
        for (int target = row-1; target >= 0; target--) {
            if (data[target][pivot] == 0) {
                continue;
            }
            double factor = data[target][pivot];
            QVector<double> multiplied_row = multiplyRow(data[row], factor);
            data[target] = subtractRow(data[target], multiplied_row);
        }
    }
}
