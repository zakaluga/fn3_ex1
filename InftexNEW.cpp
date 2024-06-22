#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Matrix {
public:
    vector<vector<double>> matr;  // Содержит данные матрицы
    int rows;  // Количество строк
    int cols;  // Количество столбцов

    Matrix() : rows(0), cols(0) {}  // Конструктор по умолчанию                                                                                       
    Matrix(int rows, int cols) : rows(rows), cols(cols), matr(rows, vector<double>(cols)) {}  // Конструктор с параметрами                        
    Matrix(const vector<vector<double>>& matr) : matr(matr), rows(matr.size()), cols(matr[0].size()) {}  // Конструктор из вектора        
    Matrix(const Matrix& other) : matr(other.matr), rows(other.rows), cols(other.cols) {}  // Конструктор копирования                                
    ~Matrix() {}  // Деструктор

    int getRows() const { return rows; }  // Возвращает количество строк                                       
    int getCols() const { return cols; }  // Возвращает количество столбцов                                       
    int getDim() const { return getRows() * getCols(); }  // Возвращает размерность матрицы                        
    double getElement(int row, int col) const { return matr[row][col]; }  // Возвращает элемент матрицы        
    vector<double> getRow(int row) const { return matr[row]; }  // Возвращает строку матрицы             
    vector<double> getCol(int col) const {  // Возвращает столбец матрицы                                 
        vector<double> colMatr(getRows());
        for (int i = 0; i < getRows(); ++i)
            colMatr[i] = matr[i][col];
        return colMatr;
    }
    vector<vector<double>> getMatr() const { return matr; }  // Возвращает всю матрицу           
    string toString() const {  // Преобразует матрицу в строку                                             
        stringstream ss;
        for (const auto& row : matr) {
            for (const auto& elem : row)
                ss << elem << " ";
            ss << "\n";
        }
        return ss.str();
    }

    void setElement(int i, int j, double val) {  // Устанавливает элемент матрицы                                 
        if (i >= 0 && i < rows && j >= 0 && j < cols)
            matr[i][j] = val;
        else
            cout << "Неверный индекс строки или столбца." << endl;
    }
    void setRow(int r, const vector<double>& val) {  // Устанавливает строку матрицы                        
        if (r >= 0 && r < rows && val.size() == cols) {
            for (int i = 0; i < cols; ++i)
                matr[r][i] = val[i];
        }
        else
            cout << "Неверный индекс строки или размер значения." << endl;
    }
    void setCol(int c, const vector<double>& val) {  // Устанавливает столбец матрицы                        
        if (c >= 0 && c < cols && val.size() == rows) {
            for (int i = 0; i < rows; ++i)
                matr[i][c] = val[i];
        }
        else
            cout << "Неверный индекс столбца или размер значения." << endl;
    }

    void Resize(int newRows, int newCols, bool preserve = false) {  // Изменяет размер матрицы              
        if (preserve) {
            if (newRows < rows || newCols < cols)
                cout << "Невозможно уменьшить размер, сохраняя данные." << endl;
            vector<vector<double>> newMatr(newRows, vector<double>(newCols));
            for (int i = 0; i < rows; ++i)
                for (int j = 0; j < cols; ++j)
                    newMatr[i][j] = matr[i][j];
            matr = newMatr;
            rows = newRows;
            cols = newCols;
        }
        else {
            matr.resize(newRows, vector<double>(newCols));
            rows = newRows;
            cols = newCols;
        }
    }

    bool isIdentity() const {  // Проверяет, является ли матрица единичной                                                  
        if (rows != cols) return false;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (i == j && matr[i][j] != 1) return false;
                else if (i != j && matr[i][j] != 0) return false;
            }
        }
        return true;
    }
    bool isSquare() const { return rows == cols; }  // Проверяет, является ли матрица квадратной                              

    double& operator()(int i, int j) { return matr[i][j]; }  // Оператор доступа по индексу                     
    double operator()(int i, int j) const { return matr[i][j]; }  // Оператор доступа по индексу (константный)                
    Matrix operator+(const Matrix& other) const {  // Оператор сложения матриц                               
        if (rows != other.rows || cols != other.cols)
            cout << "Эти матрицы нельзя складывать." << endl;
        Matrix res(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                res(i, j) = matr[i][j] + other(i, j);
        return res;
    }
    Matrix operator-(const Matrix& other) const {  // Оператор вычитания матриц                               
        if (rows != other.rows || cols != other.cols)
            cout << "Эти матрицы нельзя вычитать." << endl;
        Matrix res(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                res(i, j) = matr[i][j] - other(i, j);
        return res;
    }
    Matrix operator*(const Matrix& other) const {  // Оператор умножения матриц                               
        Matrix res(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                double sum = 0;
                for (int k = 0; k < cols; ++k)
                    sum += matr[i][k] * other(k, j);
                res(i, j) = sum;
            }
        }
        return res;
    }
    bool operator==(const Matrix& other) const {  // Оператор сравнения на равенство                                
        if (rows != other.rows || cols != other.cols) return false;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (matr[i][j] != other(i, j)) return false;
        return true;
    }
    bool operator!=(const Matrix& other) const { return !(*this == other); }  // Оператор сравнения на неравенство    
    Matrix operator*(double scalar) const {  // Оператор умножения на скаляр                                     
        Matrix res(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                res(i, j) = matr[i][j] * scalar;
        return res;
    }
    Matrix operator/(double scalar) const {  // Оператор деления на скаляр                                     
        if (scalar == 0)
            cout << "Деление невозможно." << endl;
        Matrix res(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                res(i, j) = matr[i][j] / scalar;
        return res;
    }

    double Determinant() const {  // Вычисляет определитель матрицы                                                
        if (!isSquare()) {
            return 0;
        }
        if (rows == 1) {
            return matr[0][0];
        }
        if (rows == 2) {
            return matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
        }
        double det = 0.0;
        for (int i = 0; i < cols; ++i) {
            if (i % 2 == 0) {
                det += matr[0][i] * MinorMatrix(0, i).Determinant();
            }
            else {
                det -= matr[0][i] * MinorMatrix(0, i).Determinant();
            }
        }
        return det;
    }

    Matrix Transpose() const {  // Транспонирует матрицу                                                  
        Matrix res(cols, rows);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                res(j, i) = matr[i][j];
        return res;
    }
    Matrix Inverse() const {  // Вычисляет обратную матрицу                                                       
        if (!isSquare()) {
            cout << "Обратной матрицы не существует для неквадратной матрицы." << endl;
            // Возвращаем пустую матрицу или кидаем исключение в зависимости от вашей логики
            return Matrix(); // Предполагается, что конструктор по умолчанию создает пустую матрицу
        }

        double det = Determinant();
        if (det == 0) {
            cout << "Матрица вырождена и не имеет обратной матрицы." << endl;
            // Возвращаем пустую матрицу или кидаем исключение в зависимости от вашей логики
            return Matrix(); // Предполагается, что конструктор по умолчанию создает пустую матрицу
        }
        Matrix res(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ((i + j) % 2 == 0) {
                    res(i, j) = MinorMatrix(i, j).Determinant() / det;
                }
                else {
                    res(i, j) = -MinorMatrix(i, j).Determinant() / det;
                }
            }
        }

        return res.Transpose();
    }



    Matrix MinorMatrix(int row, int col) const {  // Вычисляет минорную матрицу                                                
        Matrix minor(rows - 1, cols - 1);
        for (int i = 0, mi = 0; i < rows; ++i) {
            if (i == row) continue;
            for (int j = 0, mj = 0; j < cols; ++j) {
                if (j == col) continue;
                minor(mi, mj) = matr[i][j];
                ++mj;
            }
            ++mi;
        }
        return minor;
    }
};

void manualInput(Matrix& matrix) {  // Функция ручного ввода матрицы                                                                                             
    for (int i = 0; i < matrix.getRows(); ++i) {
        for (int j = 0; j < matrix.getCols(); ++j) {
            double value;
            cin >> value;
            matrix.setElement(i, j, value);
        }
    }
}



void matrixMenu() {
    cout << "\nМЕНЮ МАТРИЦ\n";
    cout << "1. Сложение матриц\n";
    cout << "2. Вычитание матриц\n";
    cout << "3. Умножение матриц\n";
    cout << "4. Транспонирование матрицы\n";
    cout << "5. Найти обратную матрицу\n";
    cout << "6. Найти определитель матрицы\n";
    cout << "7. Решить матричное уравнение A * X = B\n";
    cout << "8. Получение матрицы минора и определителя по индексу\n";
    cout << "9. Вернуться в предыдущее меню\n";
    cout << "Ваш выбор: ";
}

void mainMenu() {
    cout << "Меню операций:\n";
    cout << "1. Работа с матрицами\n";
    cout << "2. Выход\n";
    cout << "Выберите опцию: ";
}

int main() {
    setlocale(LC_ALL, "rus");
    int choice;
    while (true) {
        mainMenu();
        cin >> choice;

        if (choice == 2) {
            break;
        }

        switch (choice) {
        case 1: {
            cout << "Меню операций с матрицами:\n";
            cout << "Ввод вручную\n";

            int rows, cols;
            cout << "Введите количество строк: ";
            cin >> rows;
            cout << "Введите количество столбцов: ";
            cin >> cols;

            Matrix A(rows, cols);
            Matrix B(rows, cols);

            if (choice == 1) {
                cout << "Введите матрицу A:\n";
                manualInput(A);
                cout << "Введите матрицу B:\n";
                manualInput(B);
            }
            else {
                cout << "Неверный выбор!" << endl;
                return 1;
            }

            cout << "Матрица A:\n" << A.toString();
            cout << "Матрица B:\n" << B.toString();
            while (true) {
                matrixMenu();
                int operation;
                cin >> operation;

                if (operation == 9) {
                    break;
                }

                switch (operation) {
                case 1: {
                    Matrix result = A + B;
                    cout << "Результат сложения:\n" << result.toString();
                    break;
                }
                case 2: {
                    Matrix result = A - B;
                    cout << "Результат вычитания:\n" << result.toString();
                    break;
                }
                case 3: {
                    if (A.getCols() != B.getRows()) {
                        cout << "Матрицы нельзя умножить. Количество столбцов первой матрицы должно совпадать с количеством строк второй матрицы.\n";
                    }
                    else {
                        Matrix result = A * B;
                        cout << "Результат умножения:\n" << result.toString();
                    }
                    break;
                }
                case 4: {
                    Matrix result = A.Transpose();
                    cout << "Транспонированная матрица A:\n" << result.toString();
                    break;
                }
                case 5: {
                    if (A.Determinant() == 0) {
                        cout << "Обратной матрицы не существует.\n";
                    }
                    else {
                        Matrix result = A.Inverse();
                        cout << "Обратная матрица A:\n" << result.toString();
                    }
                    break;
                }
                case 6: {
                    double det = A.Determinant();
                    cout << "Определитель матрицы A: " << det << "\n";
                    break;
                }
                case 7: {
                    if (A.getRows() != B.getRows() || A.getCols() != B.getCols()) {
                        cout << "Матрицы A и B должны быть одного размера для решения уравнения.\n";
                    }
                    else if (A.Determinant() == 0) {
                        cout << "Решение невозможно, так как матрица A не имеет обратной матрицы.\n";
                    }
                    else {
                        Matrix X = A.Inverse() * B;
                        cout << "Решение уравнения A * X = B:\n" << X.toString();
                    }
                    break;
                }
                case 8: {
                    int row, col;
                    cout << "Введите индекс строки: ";
                    cin >> row;
                    cout << "Введите индекс столбца: ";
                    cin >> col;

                    if (row < 0 || row >= A.getRows() || col < 0 || col >= A.getCols()) {
                        cout << "Неверные индексы!" << endl;
                        break;
                    }

                    Matrix minorMatrix = A.MinorMatrix(row, col);
                    double determinant = minorMatrix.Determinant();

                    cout << "Матрица минора для элемента (" << row << ", " << col << "):\n";
                    cout << minorMatrix.toString();
                    cout << "Определитель матрицы минора: " << determinant << "\n";

                    break;
                }

                default:
                    cout << "Неверный выбор!\n";
                    break;
                }
            }
            break;
        }
        default:
            cout << "Неверный выбор!\n";
            break;
        }
    }

    return 0;
}


