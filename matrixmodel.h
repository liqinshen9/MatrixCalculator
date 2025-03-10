#ifndef MATRIXMODEL_H
#define MATRIXMODEL_H
#include<QVector>

class MatrixModel
{
public:
    MatrixModel();
    int getN() {return n;}
    int getM() {return m;}
    double getEntry(int row, int col);
    void setEntry(int row, int col, double value);
    void applyDimension(int new_n, int new_m);

    void showScalars(bool state) {has_scalars = state;}
    bool hasScalars() {return has_scalars;}


private:
    bool has_scalars = false;
    int n;
    int m;
    QVector<QVector<double>> data;

};

#endif // MATRIXMODEL_H
