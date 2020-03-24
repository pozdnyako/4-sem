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

class Vector {
public:
    Vector();
    Vector(int numRows);
    Vector(const Vector&);

    ~Vector();

    Vector *copy();

    // Setter
    void setValue(int r, double v) { values[r] = v;}

    //Getter
    int getNumRows() const { return this->numRows; }

    double getValue(int r) const {return this->values[r]; }

    friend Vector operator*(const Matrix &a, const Vector &b);
    friend std::ostream& operator<<(std::ostream&, const Vector&);
    friend std::istream& operator>>(std::istream&, Vector&);

private:
    void cln_mem();
    void alloc_mem();

    int numRows;

    double *values;
    bool is_alloc;
};

Vector :: Vector()
    :numRows(0)
    ,is_alloc(false)
    {}

Vector :: Vector(int numRows)
    :numRows(numRows) {

    alloc_mem();
}

Vector :: Vector(const Vector& vec) {
    numRows = vec.numRows;

    if(vec.is_alloc) {
        alloc_mem();
    }

    for(int i = 0; i < numRows; i ++) {
        values[i] = vec.values[i];
    }
}

void Vector :: cln_mem(){
    if(is_alloc)
        delete[] values;
}

void Vector :: alloc_mem() {
    if(is_alloc)
        cln_mem();

    values = new double[numRows];
    is_alloc = true;
}

Vector :: ~Vector() {
    cln_mem();
}

Vector* Vector :: copy() {
    Vector *m = new Vector(this->numRows);

    for(int r = 0; r < this->numRows; r ++) {
    for(int c = 0; c < 1; c ++) {
        m->setValue(r, this->getValue(r));
    }}

    return m;
}

Vector operator*(const Matrix &a, const Vector &b) { // c = a * b
    Vector temp(a.numRows);

    if(a.numCols != b.numRows) {
        std::cout << "[ERROR]\n";
        throw(-1);
    }

    for(int i = 0; i < a.numRows; i ++) {
        for(int k = 0; k < a.numCols; k ++) {
            temp.setValue(i, temp.getValue(i) + a.getValue(i, k) * b.getValue(k));
        }
    }

    return temp;
}

std::ostream& operator<<(std::ostream& os, const Matrix& a) {
    os << "Mat " << a.numRows << "x" << a.numCols << ":" << std::endl;

    for(int r = 0; r < a.numRows; r ++){
    for(int c = 0; c < a.numCols; c ++){
        os << a.getValue(r, c) << "\t";
    } os << std::endl; }

    return os;
}

std::istream& operator>>(std::istream& is, Matrix& a) {
    a.cln_mem();
    is >> a.numRows >> a.numCols;
    a.alloc_mem();

    for(int r = 0; r < a.numRows; r ++){
    for(int c = 0; c < a.numCols; c ++){
        double tempVal = 0.0f;
        is >> tempVal;
        a.setValue(r, c, tempVal);
    }}
    return is;
}


std::ostream& operator<<(std::ostream& os, const Vector& a) {
    os << "Vec " << a.numRows << "x1" << ":" << std::endl;

    for(int r = 0; r < a.numRows; r ++){
        os << a.getValue(r) << std::endl;
    }
    os << std::endl;

    return os;
}


std::istream& operator>>(std::istream& is, Vector& a) {
    a.cln_mem();
    is >> a.numRows;
    a.alloc_mem();

    for(int r = 0; r < a.numRows; r ++){
        double temp = 0.0f;
        is >> temp;
        a.setValue(r, temp);
    }

    return is;
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

