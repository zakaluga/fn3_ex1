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

    VECTOR row(int indx);
    VECTOR col(int indx);

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

MATRIX operator*(const MATRIX& Matr1, const MATRIX& Matr2)
{
    if ((Matr1.colLen() & Matr2.rowLen()) != Matr1.rowLen()) {
        throw std::string("Кол-во столбцов первой матрицы не равно кол-ву строк второй - умножение невозможно ");
    }    
    MATRIX ResultMatrix(Matr1.rowLen(), Matr2.colLen());
    for(int i = 0; i < Matr1.colLen(); ++i)
    {
        for(int j = 0; j < Matr2.rowLen(); ++j)
        {

        }
    }

}

VECTOR MATRIX::col(int ind)
{
    VECTOR ResultVector(matr.size()); // размер столбца
    for(int col = 0; col < matr.size(); ++col)
    {
        ResultVector[col] = matr[col][ind];
    }
    return ResultVector;
}
VECTOR MATRIX::row(int ind)
{
    return VECTOR(matr[ind]);
}
void MATRIX::setItem(int row, int col, double value)
{
    matr[row][col] = value;
}

int main(){
    std::cout << "Hello, world!" << std::endl;
    return 0;
}