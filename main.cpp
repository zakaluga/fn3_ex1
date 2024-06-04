#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <cmath>

using VECTOR = std::vector<double>;
using MASSIVE = std::vector<VECTOR>;

class MATRIX {
protected:
// Матрица организована как вектор строк(row),  
// т.е. сначала идет строка, потом обращение к колонке
//Данные о матрице
    MASSIVE _data;
    int _rows, _columns;

public:
    MATRIX(int rows, int columns);
    MATRIX(std::initializer_list<std::initializer_list<double>> matr);
    MATRIX(const MATRIX &MATRIX);
    ~MATRIX(){};

    int    rowLen() const;
    int    colLen() const;
    int    dim() const;
    void   resize(int newRow, int newCol, bool isSafeResize = true);

    std::string toString() const;
    void   print() const;

    void   setItem(int row, int columns, double value);
    void   setRow (int rNum, VECTOR row);
    void   setCol (int cNum, VECTOR col);
    double it(int row, int columns) const;

    VECTOR row(int indx) const;
    VECTOR col(int indx) const;

    const MASSIVE& matr() const{return _data;} // для константных объектов

    double  det();               // Вычисление определителя
    MATRIX T();                  // Транспонированная матрица
    MATRIX M(int row, int col);  // Матрицу минора для элемента по его индексу
    double  Minor(int row, int col); // Возвращает определитель М. минора для элемента
    MATRIX MMatr();              // Матрица минора для элементов
    double  ad(int row, int col);// Алгебраическое дополнение
    MATRIX adMatr();             // Матрица алгебраических дополнений
    MATRIX inv();                // Обратная матрица

    bool isE();     // Единичная ли матрица?
    bool isSqr();   // Квадратная ли матрица?

    static MATRIX solve(MATRIX A, MATRIX B); // Решение матричного уравнения A*X=B


public:
    double& operator()(int row, int col);
    const double& operator()(int row, int col) const; // для константных объектов

    MATRIX& operator=(const MATRIX &MATRIX);

    MATRIX operator+(const MATRIX &);
    MATRIX operator-(const MATRIX &);
    MATRIX operator*(const double &);
    MATRIX operator/(const double &);

    friend MATRIX operator*(const MATRIX &Matr1, const MATRIX &Matr2);
    friend MATRIX operator*(const double num, const MATRIX &Matr);

    friend bool operator== (const MATRIX &m1,const MATRIX &m2);
    friend bool operator!= (const MATRIX &m1,const MATRIX &m2);
    
    friend std::istream & operator>>(std::istream &, MATRIX &);
    friend std::ostream & operator<<(std::ostream &, const MATRIX &);
};
//1.1 инициализация матрицы пустой, но по известным размерам
MATRIX::MATRIX(int rows, int columns) : _rows(rows), _columns(columns), _data(rows, VECTOR(columns, 0)) {}
//1.2 инициализация матрицы двумерным массивом
MATRIX::MATRIX(std::initializer_list<std::initializer_list<double>> matr) {
    _rows = matr.size();
    _columns = matr.begin()->size();
    _data.resize(_rows);
    int row = 0;
    for (const auto& r : matr) {
        _data[row++] = VECTOR(r);
    }
}
//1.3 инициализация матрицы другой матрицей
MATRIX::MATRIX(const MATRIX &matrix) : _rows(matrix._rows), _columns(matrix._columns), _data(matrix._data) {}
//1.3 инициализация матрицы другой матрицей
MATRIX& MATRIX::operator=(const MATRIX &matrix) {
    if (this == &matrix) return *this;
    _rows = matrix._rows;
    _columns = matrix._columns;
    _data = matrix._data;
    return *this;
}
//2.1 получение ширины
int MATRIX::rowLen() const { return _rows; }
//2.2 получение высоты
int MATRIX::colLen() const { return _columns; }
//2.3 изменение элементов по индексам
double MATRIX::it(int row, int column) const {
    try {
        if (row >= _rows || column >= _columns || row < 0 || column < 0) {
            throw std::out_of_range("Index out of range");
        }
        return _data[row][column];
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 0.0;
    }
}
//2.4 изменение вектора элементов строк
VECTOR MATRIX::row(int indx) const {
    try {
        if (indx >= _rows || indx < 0) {
            throw std::out_of_range("Index out of range");
        }
        return _data[indx];
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return VECTOR();
    }
}

//2.4 изменение вектора элементов колонок
VECTOR MATRIX::col(int indx) const {
    try {
        if (indx >= _columns || indx < 0) {
            throw std::out_of_range("Index out of range");
        }
        VECTOR column(_rows);
        for (int i = 0; i < _rows; ++i) {
            column[i] = _data[i][indx];
        }
        return column;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // Return an empty VECTOR or a default value to indicate an error occurred
        return VECTOR();
    }
}

//2.6 текстовое представление
std::string MATRIX::toString() const {
    std::ostringstream oss;
    for (const auto& row : _data) {
        for (const auto& elem : row) {
            oss << std::setw(10) << elem << " ";
        }
        oss << "\n";
    }
    return oss.str();
}
//2.6 текстовое представление. печать
void MATRIX::print() const {
    std::cout << toString();
}
//3.1 запись значения элемента по индексу
void MATRIX::setItem(int row, int column, double value) {
    if (row >= _rows || column >= _columns || row < 0 || column < 0) {
        throw std::out_of_range("Index out of range");
    }
    _data[row][column] = value;
}
//3.2 запись значений элементов строк по индексу в виде вектора
void MATRIX::setRow(int rNum, VECTOR row) {
    if (rNum >= _rows || rNum < 0 || row.size() != _columns) {
        throw std::invalid_argument("Invalid row or dimension mismatch");
    }
    _data[rNum] = row;
}
//3.2 запись значений элементов колонок по индексу в виде вектора
void MATRIX::setCol(int cNum, VECTOR col) {
    if (cNum >= _columns || cNum < 0 || col.size() != _rows) {
        throw std::invalid_argument("Invalid column or dimension mismatch");
    }
    for (int i = 0; i < _rows; ++i) {
        _data[i][cNum] = col[i];
    }
}
int main() {}