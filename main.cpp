#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using MASSIVE = std::vector<std::vector<double>>;
using VECTOR = std::vector<double>;

class MATRIX {
    // Матрица организована как вектор строк(row),
    // т.е. сначала идет строка, потом обращение к колонке
protected:
    MASSIVE matr;
public:
    explicit MATRIX(int rows, int columns);
    MATRIX(std::initializer_list<std::initializer_list<double>> matr_);
    MATRIX(const MATRIX &);
    ~MATRIX(){};

    std::size_t     rowLen() const;
    std::size_t    colLen() const;
    int    dim() const;
    void   resize(int newRow, int newCol, bool isSafeResize = true);

    std::string toString() const;
    void   print();

    double getItem(int row, int col) const;
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
MATRIX::MATRIX(int rows, int columns) : matr(rows, VECTOR(columns, 0)) 
{
    // INPUT : 2, 3 -> Empty matrix 2 x 3, consisting of zeros
}
MATRIX::MATRIX(std::initializer_list<std::initializer_list<double>> matr_)
{
    TODO: example: //{{0,0}, {11,5}} -> matrix 2x2
    matr = MASSIVE(matr_.size());
    std::size_t count = 0;
    for(auto & row : matr_) {
        matr[count] = row;
        ++count;
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
std::size_t  MATRIX::rowLen() const 
{
    return matr.size();
}
std::size_t MATRIX::colLen() const 
{
    return std::size(matr[0]);
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
double MATRIX::getItem(int row, int col) const 
{
    return matr[row][col];
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
    for(int row_ = 0; row_ < rowLen(); ++row_) {
        for(int col_ = 0; col_ < colLen(); ++col_) {
            matr[row_][col_] = matr[row_][col_] / num;
        }
    }
    return *this;
}
MATRIX MATRIX::M(int row, int col) 
{
    std::size_t count_row = rowLen();
    std::size_t count_col = colLen();
    MATRIX minor (count_row-1, count_col-1);
    for(int row_ = 0, m_row_ = 0; row_ < count_row; row_++) {
        if(row_ == row) continue;
        for(int col_ = 0, m_col_ = 0; col_ < count_col; col_++) {
            if (col_ == col) continue;
            minor.setItem(m_row_, m_col_, getItem(row_, col_));
            ++m_col_;
        }
        ++m_row_;
    }
    return minor;
}
double MATRIX::det() 
{
    double det_ = 1.0f;
    if(rowLen() != colLen()) throw "Невозможно вычислить";
    if(colLen() == 1) return matr[0][0];
    if(colLen() == 2) return matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];

    for(std::size_t row = 0; row < rowLen(); row++) {
        double maxElement = fabs(matr[row][row]);
        std::size_t maxRow = row;
        for(std::size_t col = row + 1; col < rowLen(); col++) {
            if (fabs(matr[col][row]) > maxElement) {
                maxElement = fabs(matr[col][row]);
                maxRow = col;
            }
        }
        if (row != maxRow) {
            std::swap(matr[row], matr[maxRow]);
            det_ *= -1;
        }
        if (matr[row][row] == 0) return 0;
        
        for(std::size_t col = row + 1; col < rowLen(); col++) {
            double res = matr[col][row] / matr[row][row];
            for (std::size_t j = row; j < rowLen(); j++) {
                matr[col][j] -= res * matr[row][j];
            }
        }
    }
    for(std::size_t row = 0; row < rowLen(); row++) {
        det_ *= matr[row][row];
    }
    
    return det_;
}
void MATRIX::print() 
{
    std::size_t row = rowLen(), col = colLen();
    for(const auto & row : matr) {
        for(const auto & col : row) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
}
MATRIX MATRIX::inv() 
{
    if (rowLen() != colLen()) throw std::invalid_argument("матрица не квадратная");
    MATRIX extended_matrix (rowLen(), colLen() * 2);
    for (int row_ = 0; row_ < rowLen(); ++row_) {
        for (int col = 0; col < rowLen(); ++col) {
            extended_matrix.setItem(row_, col, getItem(row_, col));
        }
        extended_matrix.setItem(row_, row_ + rowLen(), 1.0);
    }
    for (int i = 0; i < rowLen(); ++i) {
        double maxElement = std::fabs(extended_matrix.getItem(i, i));
        int maxRow = i;
        for (int k = i + 1; k < rowLen(); ++k) {
            if (std::fabs(extended_matrix.getItem(k, i)) > maxElement) {
                maxElement = std::fabs(extended_matrix.getItem(k, i));
                maxRow = k;
            }
        }
        for (int k = 0; k < 2 * rowLen(); ++k) {
            std::swap(extended_matrix.matr[i][k], extended_matrix.matr[maxRow][k]);
        }
        
        double diagElement = extended_matrix.getItem(i, i);
        if (diagElement == 0) throw std::runtime_error("Матрица вырожденная и не имеет обратной");
        for (int k = 0; k < 2 * rowLen(); ++k) {
            extended_matrix.matr[i][k] /= diagElement;
        }

        for (int k = 0; k < rowLen(); ++k) {
            if (k != i) {
                double coeff = extended_matrix.getItem(k, i);
                for (int j = 0; j < 2 * rowLen(); ++j) {
                    extended_matrix.matr[k][j] -= coeff * extended_matrix.matr[i][j];
                }
            }
        }    
    }
    MATRIX inverse(rowLen(), rowLen());
    for (int i = 0; i < rowLen(); ++i) {
        for (int j = 0; j < rowLen(); ++j) {
            inverse.setItem(i, j, extended_matrix.getItem(i, j + rowLen()));
        }
    }
    return inverse;
}
double MATRIX::Minor(int row, int col) 
{
    // Определитель минора
    double determenant = 0.0f; 
    MATRIX minor = M(row, col);
    auto detMinor = [&](MATRIX M) -> double {
        std::size_t rows = M.rowLen();
        if(rows != colLen()) throw std::invalid_argument("");
        if (rows == 1) return M.getItem(0,0);
        if (rows == 2) return M.getItem(0,0) * M.getItem(0,1) - M.getItem(1,0) * M.getItem(0,1);
        for (std::size_t row = 0; row < rows; row++) {
            determenant += (row % 2 == 0 ? 1 : -1) * M.M(0, row).det();
        }
        return determenant;
    };
    return detMinor(minor);
}

class Vector_ : public MATRIX {
protected:
    // VECTOR vect;
    std::size_t dim;
public:
    enum COL_ROW {ROW = 1, COL = 2};
    explicit Vector_(std::size_t, COL_ROW);
    
    double lenVector() const;
    friend double operator*(const Vector_&, const Vector_&);
    int getOrientation() const;
private:
    COL_ROW ch;
};
Vector_::Vector_(std::size_t size, COL_ROW t) : MATRIX(t == ROW ? 1 : size, t == COL ? 1 : size), dim(size), ch(t) {}
double Vector_::lenVector() const {
    double result = 0.0f;
    if (ch == COL_ROW::ROW) {
        VECTOR vect = MATRIX::row(1);
        if (vect.empty()) throw std::string("vector is empty");
        for(int i = 0; i < dim; ++i) {
            result += vect[i] * vect[i];
        }
    } else if (ch == COL_ROW::COL) {
        VECTOR vect = MATRIX::col(1);
        if (vect.empty()) throw std::string("vector is empty");
        for(int i = 0; i < dim; ++i) {
            result += vect[i] * vect[i];
        }
    }
    return sqrt(result);
}
int Vector_::getOrientation() const {
    return ch;
}

int main(){
    MATRIX M1 = MATRIX { 
        {1,2,3}, 
        {2,2,4}, 
        {9,9,9} 
    }; 

    MATRIX INVERSE = M1.inv();
    INVERSE.print();
    // тест вычисления минора
    MATRIX min = M1.M(0,0);
    MATRIX min2 = M1.M(1,1);
    M1.print();
    std::cout << std::endl;

    min.print();
    std::cout << std::endl;
    min2.print();

    std::cout << M1.det() << std::endl;

    std::cout << M1.Minor(0,0);
    return 0;
}