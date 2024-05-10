#include <iostream>


using MASSIVE = /*двумерный массив(вектор)*/};
using VECTOR = /*Одномерный массив(вектор)*/};

class MATRIX {
    // Матрица организована как вектор строк(row),
    // т.е. сначала идет строка, потом обращение к колонке

protected:
    //Данные о матрице

public:
    MATRIX(int rows, int columns);
    MATRIX(std::initializer_list<std::initializer_list<double>> matr);
    MATRIX(const MATRIX &MATRIX);
    ~MATRIX(){};

    int    rowLen() const;
    int    colLen() const;
    int    dim() const;
    void   resize(int newRow, int newCol, bool isSafeResize = true);

    string toString() const;
    void   print();

    void   setItem(int row, int columns, double value);
    void   setRow (int rNum, VECTOR row);
    void   setCol (int cNum, VECTOR col);
    double it(int row, int columns) const;

    VECTOR row(int indx);
    VECTOR col(int indx);

    const MASSIVE& matr() const{return data;} // для константных объектов

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


int main(){
    std::cout << "Hello, world!" << std::endl;
    return 0;
}