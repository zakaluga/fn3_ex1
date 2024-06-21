#include <iostream>
#include <vector>
#include <initializer_list>
#include <string>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <iomanip> 

using namespace std;

using MASSIVE = vector<vector<double>>;
using VECTOR = vector<double>;

class MATRIX {
protected:
    MASSIVE data;
    int rows, cols;

public:
    MATRIX(int rows, int columns);
    MATRIX(initializer_list<initializer_list<double>> matr);
    MATRIX(const MATRIX& MATRIX);
    MATRIX(const MASSIVE& matr);
    ~MATRIX() = default;

    int rowLen() const;
    int colLen() const;
    int dim() const;

    void resize(int newRow, int newCol, bool isSafeResize = true);

    string toString() const;
    void print() const;

    void setItem(int row, int columns, double value);
    void setRow(int rNum, VECTOR row);
    void setCol(int cNum, VECTOR col);
    double it(int row, int columns) const;

    VECTOR row(int indx) const;
    VECTOR col(int indx) const;

    const MASSIVE& matr() const;

    double det() const;

    MATRIX T() const;
    MATRIX M(int row, int col) const;
    double Minor(int row, int col) const;
    MATRIX MMatr() const;
    double ad(int row, int col) const;
    MATRIX adMatr() const;
    MATRIX inv() const;

    bool isE() const;
    bool isSqr() const;

    static MATRIX solve(const MATRIX& A, const MATRIX& B);

    double& operator()(int row, int col);
    const double& operator()(int row, int col) const;

    MATRIX& operator=(const MATRIX& MATRIX);

    MATRIX operator+(const MATRIX& other) const;
    MATRIX operator-(const MATRIX& other) const;
    MATRIX operator*(const double& scalar) const;
    MATRIX operator/(const double& scalar) const;

    friend MATRIX operator*(const MATRIX& Matr1, const MATRIX& Matr2);
    friend MATRIX operator*(const double num, const MATRIX& Matr);
    friend bool operator==(const MATRIX& m1, const MATRIX& m2);
    friend bool operator!=(const MATRIX& m1, const MATRIX& m2);

    friend istream& operator>>(istream& in, MATRIX& matrix);
    friend ostream& operator<<(ostream& out, const MATRIX& matrix);

private:
    double determinant(const MASSIVE& matr) const;
    MATRIX minorMatrix(int row, int col) const;

    template <typename Operation>
    MATRIX elementWiseOperation(const MATRIX& other, Operation op) const;
};

class Vector : public MATRIX {
public:
    Vector(int size);
    Vector(initializer_list<double> list);

    double& operator[](int index);
    const double& operator[](int index) const;

    int size() const;
    void resize(int newSize, bool isSafeResize = true);

    string toString() const;
    void print() const;
};

MATRIX::MATRIX(int rows, int columns) : rows(rows), cols(columns), data(rows, VECTOR(columns, 0)) {}

MATRIX::MATRIX(initializer_list<initializer_list<double>> matr) {
    rows = static_cast<int>(matr.size());
    cols = static_cast<int>(matr.begin()->size());
    data.resize(rows);
    int i = 0;
    for (const auto& row : matr) {
        data[i] = VECTOR(row);
        ++i;
    }
}

MATRIX::MATRIX(const MATRIX& MATRIX) : rows(MATRIX.rows), cols(MATRIX.cols), data(MATRIX.data) {}

MATRIX::MATRIX(const MASSIVE& matr) : rows(static_cast<int>(matr.size())), cols(static_cast<int>(matr[0].size())), data(matr) {}

int MATRIX::rowLen() const { return rows; }
int MATRIX::colLen() const { return cols; }
int MATRIX::dim() const { return rows * cols; }

void MATRIX::resize(int newRow, int newCol, bool isSafeResize) {
    if (isSafeResize) {
        MASSIVE newData(newRow, VECTOR(newCol, 0));
        for (int i = 0; i < std::min(rows, newRow); ++i) {
            for (int j = 0; j < std::min(cols, newCol); ++j) {
                newData[i][j] = data[i][j];
            }
        }
        data = newData;
    }
    else {
        data.resize(newRow);
        for (auto& row : data) {
            row.resize(newCol);
        }
    }
    rows = newRow;
    cols = newCol;
}

string MATRIX::toString() const {
    ostringstream oss;
    for (const auto& row : data) {
        for (const auto& elem : row) {
            oss << setw(10) << elem << " "; 
        }
        oss << "\n";
    }
    return oss.str();
}

void MATRIX::print() const { cout << toString(); }

void MATRIX::setItem(int row, int columns, double value) {
    data[row][columns] = value;
}

void MATRIX::setRow(int rNum, VECTOR row) {
    data[rNum] = row;
}

void MATRIX::setCol(int cNum, VECTOR col) {
    for (int i = 0; i < rows; ++i) {
        data[i][cNum] = col[i];
    }
}

double MATRIX::it(int row, int columns) const {
    return data[row][columns];
}

VECTOR MATRIX::row(int indx) const {
    return data[indx];
}

VECTOR MATRIX::col(int indx) const {
    VECTOR column(rows);
    for (int i = 0; i < rows; ++i) {
        column[i] = data[i][indx];
    }
    return column;
}

const MASSIVE& MATRIX::matr() const { return data; }

double MATRIX::det() const {
    if (!isSqr()) {
        throw runtime_error("Determinant not defined for non-square matrices.");
    }
    return determinant(data);
}

MATRIX MATRIX::T() const {
    MATRIX transposed(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed.data[j][i] = data[i][j];
        }
    }
    return transposed;
}

MATRIX MATRIX::M(int row, int col) const {
    return minorMatrix(row, col);
}

double MATRIX::Minor(int row, int col) const {
    return minorMatrix(row, col).det();
}

MATRIX MATRIX::MMatr() const {
    MATRIX minors(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            minors.data[i][j] = Minor(i, j);
        }
    }
    return minors;
}

double MATRIX::ad(int row, int col) const {
    return pow(-1, row + col) * Minor(row, col);
}

MATRIX MATRIX::adMatr() const {
    MATRIX adjoint(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            adjoint.data[i][j] = ad(i, j);
        }
    }
    return adjoint;
}

MATRIX MATRIX::inv() const {
    if (!isSqr()) {
        throw runtime_error("Inverse not defined for non-square matrices.");
    }
    double determinant = det();
    if (determinant == 0) {
        throw runtime_error("Matrix is singular and cannot be inverted.");
    }
    return (1.0 / determinant) * adMatr().T();
}

bool MATRIX::isE() const {
    if (!isSqr()) return false;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == j && data[i][j] != 1) return false;
            if (i != j && data[i][j] != 0) return false;
        }
    }
    return true;
}

bool MATRIX::isSqr() const {
    return rows == cols;
}

MATRIX MATRIX::solve(const MATRIX& A, const MATRIX& B) {
    if (A.det() == 0) {
        throw runtime_error("Matrix A is singular and cannot be used for solving the equation.");
    }
    return A.inv() * B;
}

double& MATRIX::operator()(int row, int col) {
    return data[row][col];
}

const double& MATRIX::operator()(int row, int col) const {
    return data[row][col];
}

MATRIX& MATRIX::operator=(const MATRIX& MATRIX) {
    if (this != &MATRIX) {
        rows = MATRIX.rows;
        cols = MATRIX.cols;
        data = MATRIX.data;
    }
    return *this;
}

MATRIX MATRIX::operator+(const MATRIX& other) const {
    return elementWiseOperation(other, plus<double>());
}

MATRIX MATRIX::operator-(const MATRIX& other) const {
    return elementWiseOperation(other, minus<double>());
}

MATRIX MATRIX::operator*(const double& scalar) const {
    MATRIX result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

MATRIX MATRIX::operator/(const double& scalar) const {
    return *this * (1.0 / scalar);
}

MATRIX operator*(const MATRIX& Matr1, const MATRIX& Matr2) {
    if (Matr1.cols != Matr2.rows) {
        throw runtime_error("Matrix multiplication dimension mismatch.");
    }
    MATRIX result(Matr1.rows, Matr2.cols);
    for (int i = 0; i < result.rows; ++i) {
        for (int j = 0; j < result.cols; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < Matr1.cols; ++k) {
                result.data[i][j] += Matr1.data[i][k] * Matr2.data[k][j];
            }
        }
    }
    return result;
}

MATRIX operator*(const double num, const MATRIX& Matr) {
    return Matr * num;
}

bool operator==(const MATRIX& m1, const MATRIX& m2) {
    return m1.data == m2.data;
}

bool operator!=(const MATRIX& m1, const MATRIX& m2) {
    return !(m1 == m2);
}

istream& operator>>(istream& in, MATRIX& matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            in >> matrix.data[i][j];
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const MATRIX& matrix) {
    for (const auto& row : matrix.data) {
        for (const auto& elem : row) {
            out << setw(10) << elem << " ";
        }
        out << "\n";
    }
    return out;
}

double MATRIX::determinant(const MASSIVE& matr) const {
    if (matr.size() == 1) return matr[0][0];
    if (matr.size() == 2) return matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];

    double det = 0;
    for (int p = 0; p < matr[0].size(); ++p) {
        MASSIVE subMatr;
        for (int i = 1; i < matr.size(); ++i) {
            VECTOR row;
            for (int j = 0; j < matr[i].size(); ++j) {
                if (j != p) row.push_back(matr[i][j]);
            }
            if (!row.empty()) subMatr.push_back(row);
        }
        det += matr[0][p] * pow(-1, p) * determinant(subMatr);
    }
    return det;
}

MATRIX MATRIX::minorMatrix(int row, int col) const {
    MASSIVE minorData(rows - 1, VECTOR(cols - 1));
    int r = 0;
    for (int i = 0; i < rows; ++i) {
        if (i == row) continue;
        int c = 0;
        for (int j = 0; j < cols; ++j) {
            if (j == col) continue;
            minorData[r][c] = data[i][j];
            ++c;
        }
        ++r;
    }
    return MATRIX(minorData);
}

template <typename Operation>
MATRIX MATRIX::elementWiseOperation(const MATRIX& other, Operation op) const {
    if (rows != other.rows || cols != other.cols) {
        throw runtime_error("Dimension mismatch for element-wise operation.");
    }
    MATRIX result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = op(data[i][j], other.data[i][j]);
        }
    }
    return result;
}

Vector::Vector(int size) : MATRIX(size, 1) {}

Vector::Vector(initializer_list<double> list) : MATRIX(static_cast<int>(list.size()), 1) {
    int i = 0;
    for (auto elem : list) {
        data[i++][0] = elem;
    }
}

double& Vector::operator[](int index) {
    return data[index][0];
}

const double& Vector::operator[](int index) const {
    return data[index][0];
}

int Vector::size() const {
    return rowLen();
}

void Vector::resize(int newSize, bool isSafeResize) {
    if (isSafeResize) {
        MASSIVE newData(newSize, VECTOR(1, 0));
        for (int i = 0; i < std::min(rows, newSize); ++i) {
            newData[i][0] = data[i][0];
        }
        data = newData;
    }
    else {
        data.resize(newSize);
        for (auto& row : data) {
            row.resize(1);
        }
    }
    rows = newSize;
}

string Vector::toString() const {
    ostringstream oss;
    for (const auto& elem : data) {
        oss << setw(10) << elem[0] << " "; 
    }
    return oss.str();
}

void Vector::print() const { cout << toString(); }


int main() {
    MATRIX A{ {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 0, 1, 2}, {3, 4, 5, 6} };
    MATRIX B{ {7, 8, 9, 1}, {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 1, 2} };

    cout << "Matrix A:\n" << A << endl;
    cout << "Matrix B:\n" << B << endl;

    MATRIX C = A + B;
    cout << "Matrix C (A + B):\n" << C << endl;

    MATRIX D = A - B;
    cout << "Matrix D (A - B):\n" << D << endl;

    MATRIX E = A * 2.0;
    cout << "Matrix E (A * 2.0):\n" << E << endl;

    MATRIX F = A / 2.0;
    cout << "Matrix F (A / 2.0):\n" << F << endl;

    MATRIX G = A * B;
    cout << "Matrix G (A * B):\n" << G << endl;

    cout << "Determinant of A: " << A.det() << endl;
    cout << "Determinant of B: " << B.det() << endl;

    MATRIX At = A.T();
    MATRIX Bt = B.T();
    cout << "Transpose of A:\n" << At << endl;
    cout << "Transpose of B:\n" << Bt << endl;

    MATRIX MminorA = A.M(0, 0);
    MATRIX MminorB = B.M(0, 0);
    cout << "Minor of A(0, 0):\n" << MminorA << endl;
    cout << "Minor of B(0, 0):\n" << MminorB << endl;

    cout << "Determinant of Minor of A(0, 0): " << MminorA.det() << endl;
    cout << "Determinant of Minor of B(0, 0): " << MminorB.det() << endl;

    MATRIX MinorsA = A.MMatr();
    MATRIX MinorsB = B.MMatr();
    cout << "Matrix of Minors of A:\n" << MinorsA << endl;
    cout << "Matrix of Minors of B:\n" << MinorsB << endl;

    cout << "Algebraic Complement of A(0, 0): " << A.ad(0, 0) << endl;
    cout << "Algebraic Complement of B(0, 0): " << B.ad(0, 0) << endl;

    MATRIX AdMatA = A.adMatr();
    MATRIX AdMatB = B.adMatr();
    cout << "Matrix of Algebraic Complements of A:\n" << AdMatA << endl;
    cout << "Matrix of Algebraic Complements of B:\n" << AdMatB << endl;

    try {
        MATRIX InvA = A.inv();
        cout << "Inverse of A:\n" << InvA << endl;
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        MATRIX InvB = B.inv();
        cout << "Inverse of B:\n" << InvB << endl;
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        MATRIX SolveA = MATRIX::solve(A, B);
        cout << "Matrix equation solution AX = B. X:\n" << SolveA << endl;
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        MATRIX SolveB = MATRIX::solve(B, A);
        cout << "Matrix equation solution BX = A. X:\n" << SolveB << endl;
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    Vector v{ 1, 2, 3 };
    cout << "Vector v:\n" << v << endl;

    v.resize(5);
    cout << "Resized vector v:\n" << v << endl;

    v[4] = 5;
    cout << "Modified vector v:\n" << v << endl;

    return 0;
}

