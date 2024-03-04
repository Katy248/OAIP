#include <iostream>
#include "matrix.hpp"

Matrix::Matrix(int m, int n) 
{
    this->values = new int*[m];
    for (int i = 0; i < m; i++) {
        this->values[i] = new int[n];
    }
    this->n = n;
    this->m = m;
}
void Matrix::set(int m, int n, int value) 
{
    this->values[m][n] = value;
}
int Matrix::get(int m, int n) const 
{
    return this->values[m][n];
}
int Matrix::get_m() const
{
    return this->m;
}
int Matrix::get_n() const
{
    return this->n;
}
Matrix *Matrix::add(Matrix *b) const
{
    if (this->m != b->m || this->n != b->n)
    {
        return NULL;
    }
    Matrix *result = new Matrix(this->m, this->n);
    for (int i = 0; i < this->m; i++) {
        for (int j = 0; j < this->n; j++) {
            result->set(i, j, this->values[i][j] + b->values[i][j]);
        }
    }
    return result;
}