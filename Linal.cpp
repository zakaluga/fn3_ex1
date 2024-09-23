#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include<cmath>
using VECTOR = std::vector<double>;
using MASSIVE = std::vector<VECTOR>;

class MATRIX {
    // Матрица организована как вектор строк(row),
    // т.е. сначала идет строка, потом обращение к колонке

protected:
    //Данные о матрице
    MASSIVE data;
    int num_rows, num_cols;
public:
    //1.1 инициализация матрицы пустой, но по известным размерам
    MATRIX(int rows, int columns) :num_rows(rows), num_cols(columns), data(rows, VECTOR(columns, 0)) {};
    //1.2 инициализация матрицы двумерным массивом
    MATRIX(std::initializer_list<std::initializer_list<double>> matr)
    {
        num_rows = matr.size();
        num_cols = matr.begin()->size();
        data.resize(num_rows);
        int row = 0;
        for (const auto& r : matr)
        {
            data[row++] = VECTOR(r);
        }
    }
    //1.3 инициализация матрицы другой матрицей
    MATRIX(const MATRIX& MATRIX) :num_rows(MATRIX.num_rows), num_cols(MATRIX.num_cols), data(MATRIX.data) {};

    ~MATRIX() {};

    int    rowLen() const
    {
        return num_rows;
    }                                      //Получение размеров матрицы
    int    colLen() const
    {
        return num_cols;
    }
    int    dim() const                     //Получение размерности
    {
        return num_cols * num_rows;
    }

    void   resize(int newRow, int newCol, bool isSafeResize = true) //Изменение размеров
    {
        if (isSafeResize)
        {
            MASSIVE newMatrix(newRow, VECTOR(newCol, 0));
            for (int i = 0; i < newRow; i++)
            {
                for (int j = 0; j < newCol; j++)
                {
                    if (i < num_rows && j < num_cols)
                    {
                        newMatrix[i][j] = data[i][j];
                    }
                    else
                    {
                        newMatrix[i][j] = 0.0;
                    }
                }
            }
            data = newMatrix;
        }
        else
        {
            data.resize(newRow, VECTOR(newCol, 0));
        }
        num_rows = newRow;
        num_cols = newCol;
    }


    std::string toString() const            //Получение текстового представления
    {
        std::ostringstream oss;
        for (const auto& row : data)
        {
            for (const auto& elem : row)
            {
                oss << std::setw(10) << elem << " ";
            }
            oss << "\n";
        }
        return oss.str();
    };
    void   print()                          //Печать
    {
        std::cout << toString();
    };

    void   setItem(int row, int columns, double value)//Запись значения элемента по индексу
    {
        if (row >= num_rows || row < 0 || columns >= num_cols || columns < 0)
        {
            throw std::out_of_range("Index out of range");
        }
        try
        {
            data[row][columns] = value;
        }
        catch (const std::out_of_range err)
        {
            std::cerr << "ERROR: " << err.what() << "\n";
        }
    }
    void   setRow(int rNum, VECTOR row)    //Запись значений элементов строк в виде вектора
    {
        if (rNum >= num_rows || rNum < 0 || row.size() != num_cols)
        {
            throw std::out_of_range("Row index out of range or dimension mismatch");
        }
        try
        {
            data[rNum] = row;
        }
        catch (const std::out_of_range& err)
        {
            std::cerr << err.what() << '\n';
        }

    }
    void   setCol(int cNum, VECTOR col)    //Запись значений элементов колонок в виде вектора
    {
        if (cNum >= num_cols || cNum < 0 || col.size() != num_rows)
        {
            throw std::out_of_range("Columns index out of range or dimension mismatch");
        }
        try
        {
            for (int i = 0; i < num_rows; ++i)
            {
                data[i][cNum] = col[i];
            }
        }
        catch (const std::out_of_range& err)
        {
            std::cerr << err.what() << '\n';
        }

    }
    double it(int row, int columns) const   //Получение значения элемента по индексу
    {
        if (row >= num_rows || row < 0 || columns >= num_cols || columns < 0)
        {
            throw std::out_of_range("Index out of range");
        }
        try
        {
            return data[row][columns];
        }
        catch (const std::out_of_range err)
        {
            std::cerr << "ERROR: " << err.what() << "\n";
            return 0.0;
        }
    }

    VECTOR row(int indx)                    //Получение вектора элементов строк
    {
        if (indx >= num_rows || indx < 0)
        {
            throw std::out_of_range("Index out of range");
        }
        try
        {
            return data[indx];
        }
        catch (const std::out_of_range& err)
        {
            std::cerr << err.what() << '\n';
            return VECTOR();
        }

    }
    VECTOR col(int indx)                    //Получение вектора элементов колонок
    {
        if (indx >= num_cols || indx < 0)
        {
            throw std::out_of_range("Index out of range");
        }
        try
        {
            VECTOR column(num_rows);
            for (int i = 0; i < num_rows; i++)
            {
                column[i] = data[i][indx];
            }
            return column;
        }
        catch (const std::out_of_range& err)
        {
            std::cerr << err.what() << '\n';
            return VECTOR();
        }

    }

    const MASSIVE& matr() const  // для константных объектов
    {
        return data;
    }

    double det()                // Вычисление определителя
    {
        if (!isSqr())
        {
            throw std::runtime_error("The matrix is not square");
        }

        try
        {
            if (num_rows == 1)
            {
                return data[0][0];
            }
            if (num_rows == 2)
            {
                return data[0][0] * data[1][1] - data[0][1] * data[1][0];
            }
            double determinant = 0;
            for (int j = 0; j < num_cols; ++j)
            {
                determinant += data[0][j] * ad(0, j);
            }
            return determinant;
        }
        catch (const std::exception& err)
        {
            std::cerr << err.what() << '\n';
            return 0.0;
        }

    }
    MATRIX T()                  // Транспонированная матрица
    {
        MATRIX transposed(num_cols, num_rows);
        for (int i = 0; i < num_rows; ++i)
        {
            for (int j = 0; j < num_cols; ++j)
            {
                transposed.data[j][i] = data[i][j];
            }
        }
        return transposed;
    }
    MATRIX M(int row, int col)  // Матрица минора для элемента по его индексу
    {
        MATRIX minor(num_rows - 1, num_cols - 1);
        for (int i = 0, minor_rows = 0; i < num_rows; i++)
        {
            if (i == row)continue;
            for (int j = 0, minor_cols = 0; j < num_cols; j++)
            {
                if (j == col)continue;
                minor.data[minor_rows][minor_cols] = data[i][j];
                minor_cols++;
            }
            minor_rows++;
        }
        return minor;
    }
    double Minor(int row, int col) // Возвращает определитель М. минора для элемента
    {
        return M(row, col).det();
    }
    MATRIX MMatr()              // Матрица минора для элементов
    {
        MATRIX Minor_Matrix(num_rows, num_cols);
        for (int i = 0; i < num_rows; i++)
        {
            for (int j = 0; j < num_cols; j++)
            {
                Minor_Matrix.data[i][j] = Minor(i, j);
            }
        }
        return Minor_Matrix;
    }
    double ad(int row, int col) // Алгебраическое дополнение
    {
        int sign;
        if ((row + col) % 2 == 0)
        {
            sign = 1;
        }
        else
        {
            sign = -1;
        }
        return sign * Minor(row, col);
    }
    MATRIX adMatr()             // Матрица алгебраических дополнений
    {
        MATRIX adMatix(num_rows, num_cols);
        for (int i = 0; i < num_rows; i++)
        {
            for (int j = 0; j < num_cols; j++)
            {
                adMatix.data[i][j] = ad(i, j);
            }
        }
        return adMatix.T();
    }
    MATRIX inv()                // Обратная матрица
    {
        double determinant = det();
        if (determinant == 0)
        {
            throw std::logic_error("Matrix is not invertible");
        }
        try
        {
            return adMatr() * (1.0 / determinant);
        }
        catch (const std::exception& err)
        {
            std::cerr << err.what() << '\n';
            return MATRIX(0, 0);
        }

    }

    bool isE()     // Единичная ли матрица?
    {
        if (isSqr())
        {
            for (int i = 0; i < num_rows; ++i)
            {
                for (int j = 0; j < num_cols; ++j)
                {
                    if ((i == j && data[i][j] == 1) && (i != j && data[i][j] == 0))
                    {
                        return true;
                    }
                }
            }
        }
        else
        {
            return false;
        }
    }
    bool isSqr()   // Квадратная ли матрица?
    {
        return num_cols == num_rows;
    }

    static MATRIX solve(MATRIX A, MATRIX B) // Решение матричного уравнения A*X=B
    {
        return A.inv() * B;
    }


public:
    double& operator()(int row, int col)
    {
        static double res = it(row, col);
        return res;
    }
    const double& operator()(int row, int col) const // для константных объектов
    {
        //return it(row,col);
        if (row <= num_rows && col <= num_cols)
        {
            return data[row][col];
        }
    }

    MATRIX& operator=(const MATRIX& MATRIX)
    {
        if (this == &MATRIX) return *this;
        num_rows = MATRIX.num_cols;
        num_cols = MATRIX.num_cols;
        data = MATRIX.data;
        return *this;
    };

    MATRIX operator+(const MATRIX& matrix)
    {
        if (num_rows != matrix.num_rows || num_cols != matrix.num_cols)
        {
            throw std::invalid_argument("Size mismatch");
        }
        try
        {
            MATRIX Result(num_rows, num_cols);
            for (int i = 0; i < num_rows; ++i)
            {
                for (int j = 0; j < num_cols; ++j)
                {
                    Result.data[i][j] = data[i][j] + matrix.data[i][j];
                }
            }
            return Result;
        }
        catch (const std::invalid_argument& err)
        {
            std::cerr << err.what() << '\n';
            return MATRIX(0, 0);
        }

    }
    MATRIX operator-(const MATRIX& matrix)
    {
        if (num_rows != matrix.num_rows || num_cols != matrix.num_cols)
        {
            throw std::invalid_argument("Size mismatch");
        }
        try
        {
            MATRIX Result(num_rows, num_cols);
            for (int i = 0; i < num_rows; ++i)
            {
                for (int j = 0; j < num_cols; ++j)
                {
                    Result.data[i][j] = data[i][j] - matrix.data[i][j];
                }
            }
            return Result;
        }
        catch (const std::invalid_argument& err)
        {
            std::cerr << err.what() << '\n';
            return MATRIX(0, 0);
        }

    }
    MATRIX operator*(const double& scalar)
    {

        MATRIX Result(num_rows, num_cols);
        for (int i = 0; i < num_rows; ++i)
        {
            for (int j = 0; j < num_cols; ++j)
            {
                Result.data[i][j] = data[i][j] * scalar;
            }
        }
        return Result;


    }
    MATRIX operator/(const double& scalar)
    {
        if (scalar == 0)
        {
            throw std::invalid_argument("Division by zero");
        }
        try
        {
            MATRIX Result(num_rows, num_cols);
            for (int i = 0; i < num_rows; ++i)
            {
                for (int j = 0; j < num_cols; ++j)
                {
                    Result.data[i][j] = data[i][j] / scalar;
                }
            }
            return Result;
        }
        catch (const std::invalid_argument& err)
        {
            std::cerr << err.what() << '\n';
            return MATRIX(0, 0);
        }

    }

    friend MATRIX operator*(const MATRIX& Matr1, const MATRIX& Matr2)
    {
        if (Matr1.num_cols != Matr2.num_rows)
        {
            throw std::invalid_argument("Size mismatch");
        }
        try
        {
            MATRIX Result(Matr1.num_rows, Matr2.num_cols);
            for (int i = 0; i < Matr1.num_rows; ++i) {
                for (int j = 0; j < Matr2.num_cols; ++j) {
                    Result.data[i][j] = 0;
                    for (int k = 0; k < Matr1.num_cols; ++k) {
                        Result.data[i][j] += Matr1.data[i][k] * Matr2.data[k][j];
                    }
                }
            }
            return Result;
        }
        catch (const std::invalid_argument& err)
        {
            std::cerr << err.what() << '\n';
            return MATRIX(0, 0);
        }

    }
    friend MATRIX operator*(const double num, const MATRIX& Matr)
    {
        return num * Matr;
    }

    friend bool operator== (const MATRIX& m1, const MATRIX& m2)
    {
        if (m1.num_rows == m2.num_rows && m1.num_cols == m2.num_cols)
        {
            for (int i = 0; i < m1.num_rows; ++i)
            {
                for (int j = 0; j < m1.num_cols; ++j)
                {
                    if (m1.data[i][j] == m2.data[i][j])
                    {
                        return true;
                    }
                }
            }
        }
        else
        {
            return false;
        }
    }
    friend bool operator!= (const MATRIX& m1, const MATRIX& m2)
    {
        return !(m1 == m2);
    }

    friend std::istream& operator>>(std::istream& is, MATRIX& matrix)
    {
        for (int i = 0; i < matrix.num_rows; ++i)
        {
            for (int j = 0; j < matrix.num_cols; ++j)
            {
                is >> matrix.data[i][j];
            }
        }
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const MATRIX& matrix)
    {
        os << matrix.toString();
        return os;
    }

};

void manualInput(MATRIX& matrix) // Функция ручного ввода матрицы
{
    for (int i = 0; i < matrix.rowLen(); ++i)
    {
        for (int j = 0; j < matrix.colLen(); ++j)
        {
            double value;
            std::cin >> value;
            matrix.setItem(i, j, value);
        }
    }
}

void matrixMenu()
{
    std::cout << "\nМЕНЮ МАТРИЦ\n";
    std::cout << "1. Сложение матриц\n";
    std::cout << "2. Вычитание матриц\n";
    std::cout << "3. Умножение матриц\n";
    std::cout << "4. Транспонирование матрицы\n";
    std::cout << "5. Найти обратную матрицу\n";
    std::cout << "6. Найти определитель матрицы\n";
    std::cout << "7. Решить матричное уравнение A * X = B\n";
    std::cout << "8. Получение матрицы минора и определителя по индексу\n";
    std::cout << "9. Вернуться в предыдущее меню\n";
    std::cout << "Ваш выбор: ";
}

void mainMenu()
{
    std::cout << "Меню операций:\n";
    std::cout << "1. Работа с матрицами\n";
    std::cout << "2. Выход\n";
    std::cout << "Выберите опцию: ";
}

int main()
{
    setlocale(LC_ALL, "rus");
    int choice;
    while (true)
    {
        mainMenu();
        std::cin >> choice;
        if (choice == 2) 
        {
            break;
        }
        switch (choice)
        {
        case 1:
        {
            std::cout << "Меню операций с матрицами:\n";
            std::cout << "Ввод вручную\n";

            int rows, cols,rows1,cols1;
            std::cout << "Введите количество строк(A): ";
            std::cin >> rows;
            std::cout << "Введите количество столбцов(A): ";
            std::cin >> cols;
            std::cout << "Введите количество строк(B): ";
            std::cin >> rows1;
            std::cout << "Введите количество столбцов(B): ";
            std::cin >> cols1;

            MATRIX A(rows, cols);
            MATRIX B(rows1, cols1);

            std::cout << "Введите матрицу A:\n";
            manualInput(A);
            std::cout << "Введите матрицу B:\n";
            manualInput(B);
            std::cout << "Матрица A:\n" << A.toString();
            std::cout << "Матрица B:\n" << B.toString();
            while (true)
            {
                matrixMenu();
                int operation;
                std::cin >> operation;
                if (operation == 9)
                {
                    break;
                }
                switch (operation)
                {
                case 1:
                {
                    MATRIX C = A + B;
                    std::cout << "А+В: \n" << C.toString();
                    break;
                }
                case 2:
                {
                    MATRIX C = A - B;
                    std::cout << "А-В: \n" << C.toString();
                    break;
                }
                case 3:
                {
                    MATRIX C = A * B;
                    std::cout << "А*В: \n" << C.toString();
                    break;
                }
                case 4:
                {
                    MATRIX C = A.T();
                    std::cout << "А(Transposed): \n" << C.toString();
                    break;
                }
                case 5:
                {
                    MATRIX C = A.inv();
                    std::cout << "А(Inverse): \n" << C.toString();
                    break;
                }
                case 6:
                {
                    double det = A.det();
                    std::cout << "|А|: \n" << det;
                    break;
                }
                case 7:
                {
                    MATRIX X = A.inv() * B;
                    std::cout << "Solve X(AX=B): \n" << X.toString();
                    break;
                }
                case 8:
                {
                    int row, col;
                    std::cout << "Введите индекс строки: ";
                    std::cin >> row;
                    std::cout << "Введите индекс столбца: ";
                    std::cin >> col;

                    if (row < 0 || row >= A.rowLen() || col < 0 || col >= A.colLen())
                    {
                        std::cout << "Неверные индексы! \n";
                        break;
                    }
                    MATRIX MMatrix = A.M(row, col);
                    double determinant = MMatrix.det();
                    std::cout << "Матрица минора для элемента (" << row << ", " << col << "):";
                    std::cout << MMatrix.toString();
                    std::cout << "Определитель матрицы минора: " << determinant << "\n";
                    break;
                }
                default:
                    std::cout << "Неверный выбор\n";
                    break;
                }
            }

            break;
        }

        default:
            std::cout << "Неверный выбор\n";
            break;
        }
    }
    return 0;
}
