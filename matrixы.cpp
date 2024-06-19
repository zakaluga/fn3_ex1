#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <cmath>

using VECTOR = std::vector<double>;
using MASSIVE = std::vector<VECTOR>;
class MATRIX
{
protected:
    int rows, cols;
    MASSIVE data;
    VECTOR row, col;

public:
    MATRIX(int rows, int columns) : rows(rows), cols(columns), data(rows, VECTOR(columns)) {}
    MATRIX(std::initializer_list<std::initializer_list<double>> matr)
    {
        rows = matr.size();
        cols = matr.begin()->size();
        data.resize(rows);
        int i = 0;
        for (auto &row : matr)
        {
            data[i] = VECTOR(row);
            ++i;
        }
    }
    MATRIX(const MATRIX &matrix) : rows(matrix.rows), cols(matrix.cols), data(matrix.data) {}
    MATRIX &operator=(const MATRIX &other)
    {
        if (this != &other)
        {
            rows = other.rows;
            cols = other.cols;
            data = other.data;
        }
        return *this;
    }
    int rowLen() const
    {
        return cols;
    };
    int colLen() const
    {
        return rows;
    };
    double it(int row, int columns) const
    {
        try
        {
            if (row >= rows || columns >= cols || row < 0 || columns < 0)
            {
                throw std::out_of_range("Index not in range");
            }
            return data[row][columns];
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return 0.0;
        }
    };
    VECTOR Getrow(int indx)
    {
        VECTOR result;
        for (int i = 0; i < cols; i++)
        {
            result[indx] = data[indx][i];
        }
        return result;
    };
    VECTOR Getcol(int indx)
    {
        VECTOR result;
        for (int i = 0; i < rows; i++)
        {
            result[indx] = data[i][indx];
        }
        return result;
    };
    int dim() const
    {
        return cols * rows;
    };

    std::string toString() const
    {
        std::string result;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result += std::to_string(data[i][j]) + " ";
            }
        }
        return result;
    };
    void print()
    {
        for (int i = 0; i < rows; i++)
        {
            std::cout << "[";
            for (int j = 0; j < cols; j++)
            {
                std::cout << data[i][j] << " ";
            }
            std::cout << "]" << "\n";
        }
    };

    void setItem(int row, int columns, double value) { data[row][columns] = value; };
    void setRow(int rNum, VECTOR r)
    {
        for (int i = 0; i < cols; i++)
        {
            data[rNum][i] = r[i];
        }
    };
    void setCol(int cNum, VECTOR column)
    {
        for (int i = 0; i < rows; i++)
        {
            data[cNum][i] = column[i];
        }
    };

    const MASSIVE &matr() const { return data; }
    void resize(int newRow, int newCol, bool isSafeResize = true)
    {
        MATRIX(newRow, newCol);
    };
    bool isE()
    {
        if (!isSqr())
        {
            return false;
        }
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (i == j)
                {
                    if (data[i][j] != 1)
                        return false;
                }
                else
                {
                    if (data[i][j] != 0)
                        return false;
                }
            }
        }

        return true;

    };
    bool isSqr()
    {
        if (rows == cols)
        {
            return true;
        }
        else
        {
            return false;
        }

    };
    double &operator()(int r, int c)
    {
        if (r <= rows && c <= cols)
        {
            return data[r][c];
        }
    };
    const double &operator()(int r, int c) const
    {
        if (r <= rows && c <= cols)
        {
            return data[r][c];
        }
    };

    MATRIX operator+(const MATRIX &matrix)
    {
        MATRIX result(rows, cols);
        if (rows == matrix.rows || cols == matrix.cols)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    result.data[i][j] = data[i][j] + matrix.data[i][j];
                }
            }
        }
        return result;
    };
    MATRIX operator-(const MATRIX &matrix)
    {
        MATRIX result(rows, cols);
        if (rows == matrix.rows || cols == matrix.cols)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    result.data[i][j] = data[i][j] + matrix.data[i][j];
                }
            }
        }
        return result;
    };
    MATRIX operator*(double num) const
    {
        MATRIX result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[i][j] = data[i][j] * num;
            }
        }
        return result;
    };
    MATRIX operator/(const double &number)
    {
        MATRIX result(rows, cols);
        if (number != 0)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    result.data[i][j] = data[i][j] / number;
                }
            }
        }
        return result;
    };

    friend MATRIX operator*(const MATRIX &Matr1, const MATRIX &Matr2)
    {
        try
        {
            if (Matr1.cols != Matr2.rows)
            {
                throw std::invalid_argument("The sizes don't match");
            }
            MATRIX result(Matr1.rows, Matr2.cols);
            for (int i = 0; i < Matr1.rows; ++i)
            {
                for (int j = 0; j < Matr2.cols; ++j)
                {
                    result.data[i][j] = 0;
                    for (int k = 0; k < Matr1.cols; ++k)
                    {
                        result.data[i][j] += Matr1.data[i][k] * Matr2.data[k][j];
                    }
                }
            }
            return result;
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return MATRIX(0, 0);
        }
    };
    friend MATRIX operator*(const double num, const MATRIX &Matr)
    {
        MATRIX result(Matr);
        for (int i = 0; i < Matr.rows; ++i)
        {
            for (int j = 0; j < Matr.cols; ++j)
            {
                result.data[i][j] = result.data[i][j] * num;
            }
        }
        return result;
    };

    friend bool operator==(const MATRIX &m1, const MATRIX &m2)
    {
        if (m1.cols != m2.cols || m1.rows != m2.rows)
        {
            return false;
        }
        for (int i = 0; i < m1.rows; ++i)
        {
            for (int j = 0; j < m1.cols; ++j)
            {
                if (m1.data[i][j] != m2.data[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    };
    friend bool operator!=(const MATRIX &m1, const MATRIX &m2)
    {
        if (m1.cols == m2.cols || m1.rows == m2.rows)
        {
            return false;
        }
        for (int i = 0; i < m1.rows; ++i)
        {
            for (int j = 0; j < m1.cols; ++j)
            {
                if (m1.data[i][j] == m2.data[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    };
double ad(int row, int col) { return ((row + col) % 2 == 0 ? Minor(row, col) : -Minor(row, col)); }; 
    double det()
    {
        if (!isSqr())
            throw std::runtime_error("The matrix is not square");

        if (rows == 1)
            return data[0][0];
        if (rows == 2)
            return data[0][0] * data[1][1] - data[0][1] * data[1][0];

        double determinant = 0;
        for (int j = 0; j < cols; ++j)
        {
            determinant += data[0][j] * ad(0, j);
        }
        return determinant;

    }; 
    MATRIX T()
    {
        MATRIX transposed(cols, rows); 
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                transposed.data[j][i] = data[i][j];
            }
        }
        return transposed;
    }; 
    MATRIX M(int row, int col)
    {
        MATRIX minor(rows - 1, cols - 1);
        for (int i = 0, mi = 0; i < rows; ++i)
        {
            if (i == row)
                continue;
            for (int j = 0, mj = 0; j < cols; ++j)
            {
                if (j == col)
                    continue;
                minor.data[mi][mj] = data[i][j];
                ++mj;
            }
            ++mi;
        }
        return minor;
    }; 
    double Minor(int row, int col) { return M(row, col).det(); }; 
    MATRIX MMatr()
    {
        MATRIX MinMatrix(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                MinMatrix.data[i][j] = Minor(i, j);
            }
        }
        return MinMatrix;
    };
    
    MATRIX adMatr()
    {
        MATRIX adjMatrix(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                adjMatrix.data[i][j] = ad(i, j);
            }
        }
        return adjMatrix.T();
    }; 
    MATRIX inv()
    {
        try
        {
            double determinant = det();
            if (determinant == 0)
            {
                throw std::logic_error("Can not invert matrix");
            }
            return adMatr() * (1.0 / determinant);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return MATRIX(0, 0);
        }
    }; 
    static MATRIX solve(MATRIX &A, MATRIX &B) { return A.inv() * B; };

    friend std::istream &operator>>(std::istream &is, MATRIX &matrix)
    {
        for (int i = 0; i < matrix.rows; ++i)
        {
            for (int j = 0; j < matrix.cols; ++j)
            {
                is >> matrix.data[i][j];
            }
        }
        return is;
    };
    friend std::ostream &operator<<(std::ostream &os, const MATRIX &matrix)
    {
        for (int i = 0; i < matrix.rows; ++i)
        {
            os << "[ ";
            for (int j = 0; j < matrix.cols; ++j)
            {
                os << matrix.data[i][j] << " ";
            }
            os << " ]";
            os << std::endl;
        }
        return os;
    };
};

int main()
{
    // тесты
    MATRIX A{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 0, 1, 2}, {3, 4, 5, 6}};
    MATRIX B{{7, 8, 9, 1}, {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 1, 2}};
    MATRIX X(4, 1);
    // смотрим как задаются матрицы
    MATRIX C = A + B;
    MATRIX D(A - B);
    MATRIX E = A * 2.0;
    MATRIX F(A / 2.0);
    MATRIX G = A * B;
    // потоковый вывод матриц
    std::cout << "Matrix A:\n"
              << A;
    std::cout << "Matrix B:\n"
              << B;
    std::cout << "Matrix C (A + B):\n"
              << C;
    std::cout << "Matrix D (A - B):\n"
              << D;
    std::cout << "Matrix E (A * 2.0):\n"
              << E;
    std::cout << "Matrix F (A / 2.0):\n"
              << F;
    std::cout << "Matrix G (A * B):\n"
              << G;
    // тесты для функций
    std::cout << "7.1Determinant of A: " << A.det() << "\n";
    std::cout << "7.1Determinant of B: " << B.det() << "\n";
    std::cout << "7.2 Transpose of A:\n"
              << A.T();
    std::cout << "7.2 Transpose of B:\n"
              << B.T();
    std::cout << "7.3 Minor of A(0,0):\n"
              << A.M(0, 0);
    std::cout << "7.3 Minor of B(0,0):\n"
              << B.M(0, 0);
    std::cout << "7.4 Determinant of Minor of A(0,0): " << A.Minor(0, 0) << "\n";
    std::cout << "7.4 Determinant of Minor of B(0,0): " << B.Minor(0, 0) << "\n";
    std::cout << "7.5 Matrix of Minors of A:\n"
              << A.MMatr();
    std::cout << "7.5 Matrix of Minors of B:\n"
              << B.MMatr();
    std::cout << "7.6 Algebraic Complement of A(0,0): " << A.ad(0, 0) << "\n";
    std::cout << "7.6 Algebraic Complement of B(0,0): " << B.ad(0, 0) << "\n";
    std::cout << "7.7 Matrix of Algebraic Complements of A:\n"
              << A.adMatr();
    std::cout << "7.7 Matrix of Algebraic Complements of B:\n"
              << B.adMatr();
    std::cout << "7.8Inverse of A:\n"
              << A.inv();
    std::cout << "7.8Inverse of B:\n"
              << B.inv();
    std::cout << "8 Matrix equation solution AX = B. X:\n" << X.solve(A, B);
    std::cout << "8 Matrix equation solution BX = A. X:\n" << X.solve(B, A);
    return 0;
}
