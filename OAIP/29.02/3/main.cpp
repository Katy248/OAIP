#include <iostream>
#include "matrix.hpp"

using namespace std;

void write(const Matrix *m)
{
    for (int i = 0; i < m->get_m(); i++) {
        for (int j = 0; j < m->get_n(); j++) {
            cout << m->get(i, j) << "\t";
        }
        cout << endl;
    }
}

int main()
{
    Matrix *m = new Matrix(10, 4);
    for (int i = 0; i < m->get_m(); i++) {
        for (int j = 0; j < m->get_n(); j++) {
            m->set(i, j, i + j);
        }
    }
    Matrix *m2 = new Matrix(10, 4);
    for (int i = 0; i < m2->get_m(); i++) {
        for (int j = 0; j < m2->get_n(); j++) {
            m2->set(i, j, i + j);
        }
    }

    write(m);
    cout << endl;
    write(m2);
    Matrix *sum = m->add(m2);
    cout << endl;
    write(sum);

    return 0;
}