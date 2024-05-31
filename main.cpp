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
    MATRIX(std::initializer_list<std::initializer_list<double>> matr_);
    MATRIX(const MATRIX &);
    ~MATRIX(){};

    int    rowLen() const;
    int    colLen() const;
    int    dim() const;
    void   resize(int newRow, int newCol, bool isSafeResize = true);

    std::string toString() const;
    void   print();

    void   __fastcall setItem(int row, int columns, double value);
    void   __fastcall setRow (int rNum, VECTOR row);
    void   __fastcall setCol (int cNum, VECTOR col);
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
MATRIX::MATRIX(int rows, int columns) : matr(MASSIVE(rows)) 
{
    TODO: // INPUT : 2, 3 -> Empty matrix 2 x 3, consisting of zeros
    for(int row = 0; row < matr.size(); ++row)
    {
        matr[row] = VECTOR(columns, 0);
    }
}
MATRIX::MATRIX(std::initializer_list<std::initializer_list<double>> matr_)
{
    TODO: example: //{{0,0}, {11,5}} -> matrix 2x2
    for(const auto& row : matr_) {
        matr.push_back(VECTOR(row));
    }
}
MATRIX::MATRIX(const MATRIX& Matr) : matr(MASSIVE(Matr.rowLen()))
{
    std::size_t rows = Matr.rowLen();
    for(std::size_t row = 0; row < rows; ++row)
    {
        matr[row] = Matr.row(row);
    }
}
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
void __fastcall MATRIX::setRow(int indx, VECTOR data_)
{
    if (data_ == VECTOR()) 
    {
        std::cout << "vector is Empty" << std::endl;
    }
    for(std::size_t row = 0; row < rowLen(); ++row) 
    {
        matr[indx][row] = data_[row];
    }
}
void __fastcall MATRIX::setCol(int indx, VECTOR data_)
{
    if (data_ == VECTOR()) 
    {
        std::cout << "vector is Empty" << std::endl;
    }
    for(std::size_t row = 0; row < rowLen(); ++row) 
    {
        matr[row][indx] = data_[row];
    }
}
void __fastcall MATRIX::setItem(int row, int col, double value)
{
    if (row < 0 || col < 0)
    {
        throw std::string("Negative index");
    }
    VECTOR::iterator iter = matr[row].begin();
    matr[row].insert(iter + col, value);
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
MATRIX operator*(const double num, MATRIX& Matr)
{
    std::size_t count_row = Matr.rowLen();
    std::size_t count_col = Matr.colLen();
    for(std::size_t row = 0; row < count_row; ++row)
    {
        VECTOR row_ = Matr.row(row);
        for(std::size_t i = 0; i < row_.size(); ++i)
        {
            row_[i] *= num;
        }
        Matr.setRow(row, row_);
    }
    return Matr;
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
MATRIX MATRIX::operator/(const double& num)
{
    MASSIVE::iterator end = matr.end();
    for(MASSIVE::iterator iter = matr.begin(); iter != end; ++iter)
    {
        
    }
}


class Vector_ : public MATRIX {
protected:
    // VECTOR vect;
    std::size_t dim;
public:
    enum COL_ROW {ROW = 1, COL = 2};
    Vector_(std::size_t, COL_ROW);
};

Vector_::Vector_(std::size_t size, COL_ROW t) : MATRIX(t == ROW ? 1 : size, t == COL ? 1 : size) 
{

}

int main(){
    MATRIX M1(10, 2), M2(2,2);
    TODO: // test
    VECTOR vec = {1,4};
    M1.setCol(1, vec);
    return 0;
}