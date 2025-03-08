#ifndef MATRIXMODEL_H
#define MATRIXMODEL_H
#include<QVector>

class MatrixModel
{
public:
    MatrixModel();
    int getN() {return n;}
    int getM() {return m;}

private:
    int n;
    int m;

};

#endif // MATRIXMODEL_H
