#include <iostream>
#include <vector>
#include <string>

using MASSIVE = std::vector<std::vector<double>>;
using VECTOR = std::vector<double>;

class MATRIX {
    // Матрица организована как вектор строк(row),
    // т.е. сначала идет строка, потом обращение к колонке

protected:
    MASSIVE matr;
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
    void   print();

    void   setItem(int row, int columns, double value);
    void   setRow (int rNum, VECTOR row);
    void   setCol (int cNum, VECTOR col);
    double it(int row, int columns) const;

    VECTOR row(int indx) const;
    VECTOR col(int indx) const;

    //const MASSIVE& matr() const{return data;} // для константных объектов

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
int MATRIX::rowLen() const 
{
    size_t count = 0;
    for(int row = 0; row < matr.size(); ++row) {
        count++;
    }
    return count;
}
int MATRIX::colLen() const 
{
    size_t count = 0;
    for(int col = 0; col < matr[0].size(); ++col) {
        count++;
    }
    return count;
}
VECTOR MATRIX::col(int ind) const
{
    VECTOR ResultVector(matr.size()); // размер столбца
    for(int col = 0; col < matr.size(); ++col)
    {
        ResultVector[col] = matr[col][ind];
    }
    return ResultVector;
}
VECTOR MATRIX::row(int ind) const
{
    return VECTOR(matr[ind]);
}
void MATRIX::setItem(int row, int col, double value)
{
    matr[row][col] = value;
}
int MATRIX::dim() const
{
    return rowLen() == 0 ? throw std::string("Матрица не сущ.") : rowLen() * colLen();  
}
MATRIX operator*(const MATRIX& Matr1, const MATRIX& Matr2)
{
    if ((Matr1.colLen() & Matr2.rowLen()) != Matr1.rowLen()) 
    {
        throw std::string("Кол-во столбцов первой матрицы не равно кол-ву строк второй - умножение невозможно ");
    }    
    MATRIX ResultMatrix(Matr1.rowLen(), Matr2.colLen());
    for(int row_ = 0; row_ < Matr1.colLen(); ++row_)
    {
        double value = 1.0f;
        VECTOR rw = Matr1.row(row_);
        for(int col_ = 0; col_ < Matr2.rowLen(); ++col_)
        {
            VECTOR cl = Matr2.col(col_);
            for(int i = 0; i < cl.size() ; ++i)
            {
                value *= rw[col_] * cl[col_];
            }
            ResultMatrix.setItem(row_, col_, value);
        }
        value = 1.0f;
    }
    return ResultMatrix;
}
MATRIX MATRIX::T() 
{
    MATRIX ResultMatrix(colLen(), rowLen());
    for(int col = 0; col < colLen(); ++col)
    {
        for(int row = 0; row < rowLen(); ++row) 
        {
            ResultMatrix.setItem(row, col, matr[row][col]);
        }
    }
    return ResultMatrix;
}
bool operator==(const MATRIX& Matr1, const MATRIX Matr2)
{
    auto check_r = [&](int i) 
    {
        VECTOR rowM1 = Matr1.row(i);
        VECTOR rowM2 = Matr2.row(i);
        for(int row = 0; row < rowM1.size(); ++row) {
            if (rowM1[row] == rowM2[row]) continue;
            return false;
        }
        return true;
    };
    if (Matr1.colLen() == Matr2.colLen() && Matr1.rowLen() == Matr2.rowLen())
    {
        for(int row = 0; row < Matr1.rowLen(); ++row) 
        {
            if (check_r(row) == true) 
            {
                continue;
            }
            else 
            {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}
std::string MATRIX::toString() const
{
    std::string matrixToString = std::string();
    for(int row  = 0; row < rowLen(); ++row)
    {
        for(int col = 0; col < colLen(); ++col)
        {
            matrixToString += matr[row][col];
            matrixToString += std::string(" ");
        }
        matrixToString += "\n";
    }
    return matrixToString;
}
std::ostream & operator<<(std::ostream & os, const MATRIX& Matr)
{
    std::string MatrixToStr = Matr.toString();
    if (MatrixToStr.empty())  throw std::string("matrix is empty");
    os << MatrixToStr;
    return os;
}

int main(){
    MATRIX M1(10, 2), M2(2,2);
    return 0;
}