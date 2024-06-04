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

    double  det() const;               // Вычисление определителя
    MATRIX T() const;                  // Транспонированная матрица
    MATRIX M(int row, int col) const;  // Матрицу минора для элемента по его индексу
    double  Minor(int row, int col) const; // Возвращает определитель М. минора для элемента
    MATRIX MMatr() const;              // Матрица минора для элементов
    double  ad(int row, int col) const;// Алгебраическое дополнение
    MATRIX adMatr() const;             // Матрица алгебраических дополнений
    MATRIX inv() const;                // Обратная матрица

    bool isE() const;     // Единичная ли матрица?
    bool isSqr()const ;   // Квадратная ли матрица?

    static MATRIX solve(const MATRIX& A, const MATRIX& B); // Решение матричного уравнения A*X=B


public:
    double& operator()(int row, int col);   //установка значения объекта по индексу
    const double& operator()(int row, int col) const; // получение значения объекта по индексу

    MATRIX& operator=(const MATRIX &MATRIX);

    MATRIX operator+(const MATRIX &) const;
    MATRIX operator-(const MATRIX &) const;
    MATRIX operator*(const double &) const;
    MATRIX operator/(const double &) const;

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
    try {
        if (row >= _rows || column >= _columns || row < 0 || column < 0) {
            throw std::out_of_range("Index out of range");
        }
        _data[row][column] = value;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return;
      }
    return;
}
//3.2 запись значений элементов строк по индексу в виде вектора
void MATRIX::setRow(int rNum, VECTOR row) {
    try {
        if (rNum >= _rows || rNum < 0 || row.size() != _columns) {
            throw std::invalid_argument("Invalid row or dimension mismatch");
        }
        _data[rNum] = row;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }
    return;
}
//3.2 запись значений элементов колонок по индексу в виде вектора
void MATRIX::setCol(int cNum, VECTOR col) {
    try {
        if (cNum >= _columns || cNum < 0 || col.size() != _rows) {
            throw std::invalid_argument("Invalid column or dimension mismatch");
        }
        for (int i = 0; i < _rows; ++i) {
            _data[i][cNum] = col[i];
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }
    return;
}
//4 изменение размера
void MATRIX::resize(int newRow, int newCol, bool isSafeResize) {
    if (isSafeResize) {
        MASSIVE newData(newRow, VECTOR(newCol, 0));
        for (int i = 0; i < std::min(newRow, _rows); ++i) {
            for (int j = 0; j < std::min(newCol, _columns); ++j) {
                newData[i][j] = _data[i][j];
            }
        }
        _data = newData;
    } else {
        _data.resize(newRow, VECTOR(newCol, 0));
    }
    _rows = newRow;
    _columns = newCol;
}
//5.1 матрица единичная?
bool MATRIX::isE() const {
    if (!isSqr()) return false;
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _columns; ++j) {
            if ((i == j && _data[i][j] != 1) || (i != j && _data[i][j] != 0)) {
                return false;
            }
        }
    }
    return true;
}
//5.2 матрица квадратная?
bool MATRIX::isSqr() const {
    return _rows == _columns;
}
//6.1 изменение значения элемента через оператор круглые скобки
double& MATRIX::operator()(int row, int col) {
    try {
        if (row >= _rows || col >= _columns || row < 0 || col < 0) {
            throw std::out_of_range("Index out of range");
        }
        return _data[row][col];
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        static double dummy = 0.0; 
        return dummy;
    }
}
//6.1 получение значения элемента через оператор круглые скобки
const double& MATRIX::operator()(int row, int col) const {
    try {
        if (row >= _rows || col >= _columns || row < 0 || col < 0) {
            throw std::out_of_range("Index out of range");
        }
        return _data[row][col];
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        static double dummy = 0.0; 
        return dummy;
    }
}
//6.2.1 сложение матриц
MATRIX MATRIX::operator+(const MATRIX &matrix) const {
    try {
        if (_rows != matrix._rows || _columns != matrix._columns) {
            throw std::invalid_argument("Matrix dimensions must agree");
        }
        MATRIX result(_rows, _columns);
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _columns; ++j) {
                result._data[i][j] = _data[i][j] + matrix._data[i][j];
            }
        }
        return result;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return MATRIX(0, 0);
    }
}
//6.2.2 вычитание матриц
MATRIX MATRIX::operator-(const MATRIX &matrix) const {
    try {
        if (_rows != matrix._rows || _columns != matrix._columns) {
            throw std::invalid_argument("Matrix dimensions must agree");
        }
        MATRIX result(_rows, _columns);
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _columns; ++j) {
                result._data[i][j] = _data[i][j] - matrix._data[i][j];
            }
        }
        return result;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return MATRIX(0, 0);
    }
}
//6.2.3 перемножение матриц
MATRIX operator*(const MATRIX &Matr1, const MATRIX &Matr2) {
    try {
        if (Matr1._columns != Matr2._rows) {
            throw std::invalid_argument("Matrix dimensions must agree for multiplication");
        }
        MATRIX result(Matr1._rows, Matr2._columns);
        for (int i = 0; i < Matr1._rows; ++i) {
            for (int j = 0; j < Matr2._columns; ++j) {
                result._data[i][j] = 0;
                for (int k = 0; k < Matr1._columns; ++k) {
                    result._data[i][j] += Matr1._data[i][k] * Matr2._data[k][j];
                }
            }
        }
        return result;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return MATRIX(0, 0);
    }
}
//6.2.4 сравнение. равенство.
bool operator==(const MATRIX &m1, const MATRIX &m2) {
    if (m1._rows != m2._rows || m1._columns != m2._columns) {
        return false;
    }
    for (int i = 0; i < m1._rows; ++i) {
        for (int j = 0; j < m1._columns; ++j) {
            if (m1._data[i][j] != m2._data[i][j]) {
                return false;
            }
        }
    }
    return true;
}
//6.2.4 сравнение. неравенство
bool operator!=(const MATRIX &m1, const MATRIX &m2) {
    return !(m1 == m2);
}
//6.3.1 умножение матрицы на lambda слева; (lambda c R)
MATRIX operator*(const double num, const MATRIX &Matr) {
    return Matr * num; //просто умножение справа
}
//6.3.1 умножение матрицы на lambda  справа; (lambda c R)
MATRIX MATRIX::operator*(const double &scalar) const {
    try {
        MATRIX result(_rows, _columns);
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _columns; ++j) {
                result._data[i][j] = _data[i][j] * scalar;
            }
        }
        return result;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return MATRIX(0, 0);
    }
}
//6.3.2 деление матрицы на lambda справа; (lambda c R)
MATRIX MATRIX::operator/(const double &scalar) const {
    try {
        if (scalar == 0) {
            throw std::invalid_argument("Division by zero");
        }
        MATRIX result(_rows, _columns);
        for (int i = 0; i < _rows; ++i) {
            for (int j = 0; j < _columns; ++j) {
                result._data[i][j] = _data[i][j] / scalar;
            }
        }
        return result;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return MATRIX(0, 0);
    }
}
//7.1 определитель матрицы
double MATRIX::det() const {
    try {
        if (!isSqr()) {
            throw std::logic_error("Determinant is defined for square matrices only");
        }
        if (_rows == 1) {
            return _data[0][0];
        }
        if (_rows == 2) {
            return _data[0][0] * _data[1][1] - _data[0][1] * _data[1][0];
        }
        double determinant = 0;
        for (int j = 0; j < _columns; ++j) {
            determinant += _data[0][j] * ad(0, j);
        }
        return determinant;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 0.0;
    }
}
//7.2 транспонированная матрица
MATRIX MATRIX::T() const {
    MATRIX transposed(_columns, _rows);
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _columns; ++j) {
            transposed._data[j][i] = _data[i][j];
        }
    }
    return transposed;
}
//7.3 матрица минора для элемента по индексу
MATRIX MATRIX::M(int row, int col) const {
    try {
        if (_rows <= 1 || _columns <= 1) {
            throw std::logic_error("Minor is undefined for matrices with dimension less than 2");
        }
        MATRIX minor(_rows - 1, _columns - 1);
        int m_row = 0, m_col = 0;
        for (int i = 0; i < _rows; ++i) {
            if (i == row) continue;
            m_col = 0;
            for (int j = 0; j < _columns; ++j) {
                if (j == col) continue;
                minor._data[m_row][m_col] = _data[i][j];
                ++m_col;
            }
            ++m_row;
        }
        return minor;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return MATRIX(0, 0);
    }
}
//7.4 определитель матрицы минора
double MATRIX::Minor(int row, int col) const {
    return M(row, col).det();
}
// 7.5 матрица миноров
MATRIX MATRIX::MMatr() const {
    MATRIX minorMatrix(_rows, _columns);
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _columns; ++j) {
            minorMatrix._data[i][j] = Minor(i, j);
        }
    }
    return minorMatrix;
}
//7.6 алгебраическое дополнение для элемента по его индексу
double MATRIX::ad(int row, int col) const {
    return ((row + col) % 2 == 0 ? 1 : -1) * Minor(row, col);
}
//7.7 матрица алгебраических дополнений
MATRIX MATRIX::adMatr() const {
    MATRIX adjugate(_rows, _columns);
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _columns; ++j) {
            adjugate._data[i][j] = ad(i, j);
        }
    }
    return adjugate.T();
}
//7.8 обратная матрица
MATRIX MATRIX::inv() const {
    try {
        double determinant = det();
        if (determinant == 0) {
            throw std::logic_error("Matrix is not invertible");
        }
        return adMatr() * (1.0 / determinant);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return MATRIX(0, 0);
    }
}
//8 решение матричного уравнения AX = B
MATRIX MATRIX::solve(const MATRIX& A, const MATRIX& B) {
    return A.inv() * B;
}
//потоковый ввод
std::istream &operator>>(std::istream &is, MATRIX &matrix) {
    for (int i = 0; i < matrix._rows; ++i) {
        for (int j = 0; j < matrix._columns; ++j) {
            is >> matrix._data[i][j];
        }
    }
    return is;
}
//потоковый вывод
std::ostream &operator<<(std::ostream &os, const MATRIX &matrix) {
    os << matrix.toString();
    return os;
}
int main() {
    // тесты
    MATRIX A{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 0, 1, 2}, {3, 4, 5, 6}};
    MATRIX B{{7, 8, 9, 1}, {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 1, 2}};
    MATRIX X(4, 1);
    //смотрим как задаются матрицы
    MATRIX C = A + B;
    MATRIX D (A - B);
    MATRIX E = A * 2.0;
    MATRIX F (A / 2.0);
    MATRIX G = A * B; 
    //потоковый вывод матриц
    std::cout << "Matrix A:\n" << A;
    std::cout << "Matrix B:\n" << B;
    std::cout << "Matrix C (A + B):\n" << C;
    std::cout << "Matrix D (A - B):\n" << D;
    std::cout << "Matrix E (A * 2.0):\n" << E;
    std::cout << "Matrix F (A / 2.0):\n" << F;
    std::cout << "Matrix G (A * B):\n" << G;
    // тесты для функций
    std::cout << "7.1Determinant of A: " << A.det() << "\n";
    std::cout << "7.1Determinant of B: " << B.det() << "\n";
    std::cout << "7.2 Transpose of A:\n" << A.T();
    std::cout << "7.2 Transpose of B:\n" << B.T();
    std::cout << "7.3 Minor of A(0,0):\n" << A.M(0,0);
    std::cout << "7.3 Minor of B(0,0):\n" << B.M(0,0);
    std::cout << "7.4 Determinant of Minor of A(0,0): " << A.Minor(0,0) << "\n";
    std::cout << "7.4 Determinant of Minor of B(0,0): " << B.Minor(0,0) << "\n";
    std::cout << "7.5 Matrix of Minors of A:\n" << A.MMatr();
    std::cout << "7.5 Matrix of Minors of B:\n" << B.MMatr();
    std::cout << "7.6 Algebraic Complement of A(0,0): " << A.ad(0,0) << "\n";
    std::cout << "7.6 Algebraic Complement of B(0,0): " << B.ad(0,0) << "\n";
    std::cout << "7.7 Matrix of Algebraic Complements of A:\n" << A.adMatr();
    std::cout << "7.7 Matrix of Algebraic Complements of B:\n" << B.adMatr();
    std::cout << "7.8Inverse of A:\n" << A.inv();
    std::cout << "7.8Inverse of B:\n" << B.inv();
    std::cout << "8 Matrix equation solution AX = B. X:" << X.solve(A, B);
    std::cout << "8 Matrix equation solution BX = A. X:" << X.solve(B, A);
    return 0;
}
