
class Matrix {
private:
    int n, m;
    int **values;
public:
    Matrix(int, int);
    Matrix *add(Matrix *) const;
    Matrix *mul(Matrix *) const;
    bool equal(Matrix *) const;
    int get(int, int) const;
    void set(int, int, int);
    int get_n() const;
    int get_m() const;
};