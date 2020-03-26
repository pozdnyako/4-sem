#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>

class Matrix;
class Vector;

class Matrix {
public:
    Matrix();
    Matrix(int numRows, int numCols);

    Matrix *transpose();
    Matrix *copy();

    ~Matrix();

    // Setter
    void setValue(int r, int c, double v) { values[r * numCols + c] = v;}

    //Getter
    int getNumRows() const { return numRows; }
    int getNumCols() const { return numCols; }
    double getValue(int r, int c) const { return values[r * numCols + c]; }

    const Matrix*

    friend Vector operator*(const Matrix &a, const Vector &b);
    friend std::ostream& operator<<(std::ostream&, const Matrix&);
    friend std::istream& operator>>(std::istream&, Matrix&);

private:
    void cln_mem();
    void alloc_mem();

    int numRows;
    int numCols;

    double *values;
    bool is_alloc;
};

class Vector : private Matrix {

};

Matrix :: Matrix()
    :numRows(0)
    ,numCols(0)
    ,is_alloc(false) {}

Matrix :: Matrix(int numRows, int numCols)
    :numRows(numRows)
    ,numCols(numCols) {

    alloc_mem();
}

void Matrix :: alloc_mem() {
    if(numRows <= 0 || numCols <= 0) {
        std::cout << "[ERROR]";
        throw(-1);
    }
    if(is_alloc)
        cln_mem();
    values = new double[numRows * numCols];
    is_alloc = true;
}

void Matrix :: cln_mem() {
    if(is_alloc)
        delete[] values;

    is_alloc = false;
}

Matrix :: ~Matrix() {
    cln_mem();
}

Matrix* Matrix::transpose() {
    Matrix *m = new Matrix(this->numCols, this->numRows);

    for(int r = 0; r < this->numCols; r ++) {
    for(int c = 0; c < this->numRows; c ++) {
        m->setValue(r, c, this->getValue(c, r));
    }}

    return m;
}

Matrix* Matrix :: copy() {
    Matrix *m = new Matrix(this->numRows, this->numCols);

    for(int r = 0; r < this->numRows; r ++) {
    for(int c = 0; c < this->numCols; c ++) {
        m->setValue(r, c, this->getValue(r, c));
    }}

    return m;
}

#include <fstream>

int main() {
    std::ifstream input("in.txt");

    Matrix mat;
    Vector vec;

    input >> mat >> vec;
    std::cout << mat << vec;

    Vector res = mat * vec;

    std::cout << res;
}

