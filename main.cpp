#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

class Matrix {
public:
    std::vector<std::vector<double>> matr;              //значения
    int rows;                                           //кол-во строк
    int cols;                                           //кол-во столбцов

    Matrix(): rows(0), cols(0) {}                                                                                       //пустой
    Matrix(int rows, int cols): rows(rows), cols(cols), matr(rows, std::vector<double>(cols)) {}                        //пустой, но по известным размерам
    Matrix(const std::vector<std::vector<double>>& matr): matr(matr), rows(matr.size()), cols(matr[0].size()) {}        //двумерным массивом (вектором)
    Matrix(const Matrix& other): matr(other.matr), rows(other.rows), cols(other.cols) {}                                //другой матрицей
    ~Matrix() {}

    int getRows() const { return rows; }                                        //получение кол-во строк
    int getCols() const { return cols; }                                        //получение кол-во столбцов
    int getDim() const { return getRows() * getCols(); }                        //получение размерности
    double getElement(int row, int col) const { return matr[row][col]; }        //получение эл-тов по индексам
    std::vector<double> getRow(int row) const { return matr[row]; }             //получение массива (вектора) эл-тов строки по индексу
    std::vector<double> getCol(int col) const {                                 //получение массива (вектора) эл-тов столбца по индексу
        std::vector<double> colMatr(getRows());
        for(int i = 0; i < getRows(); ++i)
            colMatr[i] = matr[i][col];
        return colMatr;
    }
    std::vector<std::vector<double>> getMatr() const { return matr; }           //получение двумерного массива (вектора) эл-тов
    std::string toString() const {                                              //текстовое представление
        std::stringstream ss;
        for(const auto& row : matr) {
            for(const auto& elem : row)
                ss << elem << " ";
            ss << "\n";
        }
        return ss.str();
    }

    void setElement(int i, int j, double val) {                                 //запись значения эл-та по индексу
        if(i >= 0 && i < rows && j >= 0 && j < cols) 
            matr[i][j] = val;
        else
            std::cout << "Invaled row or column index." << std:: endl;
    }
    void setRow(int r, const std::vector<double>& val) {                        //запись значений эл-тов строки по индексу в виде массива (вектора)
        if(r >= 0 && r < rows && val.size() == cols) {
            for(int i = 0; i < cols; ++i)
                matr[r][i] = val[i];
        }
        else
            std::cout << "Invalid row index or value size." << std::endl;
    }
    void setCol(int c, const std::vector<double>& val) {                        //запись значений эл-тов столбца по индексу в виде массива (вектора)
        if(c >= 0 && c < cols && val.size() == rows) {
            for(int i = 0; i < rows; ++i)
                matr[i][c] = val[i];
        }
        else
            std::cout << "Invalid row index or value size." << std::endl;
    }

    void Resize(int newRows, int newCols, bool preserve = false) {              //изменение размерности
        if(preserve){
            if(newRows < rows || newCols < cols)
                std::cout << "Cannot reduce size while preserving data." << std::endl;
            std::vector<std::vector<double>> newMatr(newRows, std::vector<double>(newCols));
            for(int i = 0; i < rows; ++i)
                for(int j = 0; j < cols; ++ j)
                    newMatr[i][j] = matr[i][j];
            matr = newMatr;
            rows = newRows;
            cols = newCols;
        }
        else {
            matr.resize(newRows, std::vector<double>(newCols));
            rows = newRows;
            cols = newCols;
        }
    }

    bool isIdentity() const {                                                   //проверка: единичная ли матрица
        if(rows != cols) return false;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j) {
                if(i == j && matr[i][j] != 1) return false;
                else if(i != j && matr[i][j] != 0) return false;
            }
        }
        return true;
    }
    bool isSquare() const { return rows == cols; }                              //проверка: квадратная ли матрица

    double& operator()(int i, int j) { return matr[i][j]; }                     //изменение значения эл-та через оператор ()
    double operator()(int i, int j) const { return matr[i][j]; }                //получение значения эл-та через оператор ()
    Matrix operator+(const Matrix& other) const {                               //сложение матриц
        if(rows != other.rows || cols != other.cols)
            std::cout << "These matrices cannot be folded." << std::endl; 
        Matrix res(rows, cols);
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                res(i, j) = matr[i][j] + other(i, j);
        return res;
    }
    Matrix operator-(const Matrix& other) const {                               //вычитание матриц
        if(rows != other.rows || cols != other.cols)
            std::cout << "These matrices cannot be subtracted." << std::endl; 
        Matrix res(rows, cols);
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                res(i, j) = matr[i][j] - other(i, j);
        return res;
    }
    Matrix operator*(const Matrix& other) const {                               //умножение матриц
        if(cols != other.rows)
            std::cout << "Matrix dimensions are not compatible for multiplicztion." << std::endl;
        Matrix res(rows, other.cols);
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < other.cols; ++j){
                double sum = 0;
                for(int k = 0; k < cols; ++k)
                    sum += matr[i][k] * other(k, j);
                res(i, j) = sum;
            }
        }
        return res;
    }
    bool operator==(const Matrix& other) const {                                //равенство матриц
        if(rows != other.rows || cols != other.cols) return false;
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j) 
                if(matr[i][j] != other(i, j)) return false;
        return true;
    }
    bool operator!=(const Matrix& other) const { return !(*this == other); }    //неравенство матриц
    Matrix operator*(double scalar) const {                                     //умножение матрицы на число
        Matrix res(rows, cols);
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                res(i, j) = matr[i][j]*scalar;
        return res;
    }
    Matrix operator/(double scalar) const {                                     //деление матрицы на число
        if(scalar == 0)
            std::cout << "The division cannot be performed." << std::endl;
        Matrix res(rows, cols);
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                res(i, j) = matr[i][j]/scalar;
        return res;
    }
    
    double Determinant() const {                                                //определитель матрицы
        if(!isSquare()) return 0;
        if(rows == 1) return matr[0][0];
        if(rows == 2) return matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
        double det = 0.0;
        for(int i = 0; i < cols; ++i)
            det += (i % 2 == 0 ? 1 : -1) * matr[0][i] * MinorMatrix(0, i).Determinant();
        return det;
    }
    Matrix Transpose() const {                                                  //транспонированная матрица
        Matrix res(cols, rows);
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                res(j, i) = matr[i][j];
        return res;
    }
    Matrix MinorMatrix(int row, int col) const {                                //матрица минора для эл-та по индексу
        Matrix res(rows - 1, cols - 1);
        int ri = 0, rj = 0;
        for(int i = 0; i < rows; ++i) {
            if(i != row) {
                for(int j = 0; j < cols; ++j) {
                    if(j != col)
                        res(ri, rj++) = matr[i][j];
                }
            rj = 0;
            ri++;
            }
        }
        return res;
    }
    double MinorDeterminant(int row, int col) const {                           //определитель матрицы минора для эл-та по индексу
        return MinorMatrix(row, col).Determinant();
    }
    Matrix MatrixMinors() const {                                               //матрица минора для соответствующих эл-там и их индексу
        Matrix res(cols, rows);
        for(int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                res(i, j) = pow(-1, i + j) * MinorDeterminant(i, j);
        return res;
    }
    double AlgAddition(int row, int col) const {                                //алг доп для эл-та по его индексу
        return pow(-1, row + col) * MinorDeterminant(row, col);
    }
    Matrix AlgAdditionMatrix() const {                                          //матрица алг доп
        Matrix res(rows, cols);
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                res(i, j) = AlgAddition(i, j);
            }
        }
        return res;
    }
    Matrix Inverse() const {                                                    //обратная матрица
        if(!isSquare()) return Matrix(0, 0);
        double det = Determinant();
        if(det == 0) return Matrix(0, 0);
        return AlgAdditionMatrix().Transpose() / det;
    }

    friend Matrix Solve(const Matrix& A, const Matrix& B);
    friend std::ostream& operator<<(std::ostream& out, const Matrix& m);
};

Matrix Solve(const Matrix& A, const Matrix& B) {                                //решение матричного ур-ния
    Matrix InvA = A.Inverse();
    Matrix res(InvA.rows, B.cols);
    for(int i = 0; i < InvA.rows; ++i){
        for(int j = 0; j < B.cols; ++j) {
            res(i, j) = 0;
            for(int k = 0; k < InvA.cols; ++k)
                res(i, j) += InvA(i, k) * B(k, j);
        }
    }
    return res;
}

std::ostream& operator<<(std::ostream& out, const Matrix& m) {
    for (const auto& row : m.matr) {
        for (const auto& elem : row) {
            out << elem << "\t";
        }
        out << std::endl;
    }
    return out;
}

class Vector: public Matrix {
public:
    Vector(): Matrix(1, 0) {}
    Vector(int size): Matrix(size, 1) {}
    Vector(const std::vector<double>& vect): Matrix(vect.size(), 1) {
        for(int i = 0; i < getRows(); i++){
            matr[i][0] = vect[i];
        }
    }
    Vector(const Matrix& other): Matrix(other) {
        if(other.getCols() != 1)
            std::cout << "Matrix must have one column." << std::endl;
    }
    ~Vector() {}
    
    double& operator()(int i) { return matr[i][0]; }
    double operator()(int i) const { return matr[i][0]; }
    Vector operator+(const Vector& other) const { return static_cast<Vector>(Matrix::operator+(other)); }
    Vector operator-(const Vector& other) const { return static_cast<Vector>(Matrix::operator-(other)); }
    Vector operator*(double scalar) const { return static_cast<Vector>(Matrix::operator*(scalar)); }
    Vector operator/(double scalar) const { return static_cast<Vector>(Matrix::operator/(scalar)); }
    bool operator==(const Vector& other) const { return Matrix::operator==(other); }
    bool operator!=(const Vector& other) const { return Matrix::operator!=(other); }
    
};

int main() {
    std::vector<std::vector<double>> matr1 = {{3, 7}, {2, 8}};
    Matrix A(matr1);
    std::cout << "Matrix A:\n" << A << std::endl;
    std::cout << "Determinant A:\t" << A.Determinant() << std::endl << std::endl;
    std::cout << "Transpose matrix A:\n" << A.Transpose() << std::endl;
    std::cout << "Minor matrix A:\n" << A.MinorMatrix(0, 0) << std::endl;
    std::cout << "Inverse matrix A:\n" << A.Inverse() << std::endl;

    std::vector<std::vector<double>> matr2 = {{4, 8}, {6, 2}};
    Matrix B(matr2);
    std::cout << "Matrix B: " << std::endl;
    std:: cout << B << std::endl;

    Matrix X = Solve(A, B);
    std::cout << "Solving the matrix eguation AX=B: " << std:: endl;
    std::cout << X << std::endl;

    std::vector<double> v = {1, 2, 3, 4, 5};
    Vector vect(v);
    std::cout << "Vector vect:\n" << vect << std::endl;
}
