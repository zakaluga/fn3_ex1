#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
#include <cassert>
#include <math.h>

using namespace std;

using VECTOR = double*;
using MASSIVE = VECTOR*;

class MATRIX {

protected:
	MASSIVE data;
	int n_rows, n_cols, size;

public:
	MATRIX(int rows = 0, int columns = 0);
	MATRIX(std::initializer_list<std::initializer_list<double>> matr);
	MATRIX(const MATRIX& MATRIX);
	~MATRIX();

	int    rowLen() const;
	int    colLen() const;
	int    dim() const;
	void   resize(int newRow, int newCol, bool isSafeResize = true);

	string toString() const;
	void   print();

	void   setItem(int row, int columns, double value);
	void   setRow(int rNum, VECTOR row);
	void   setCol(int cNum, VECTOR col);
	double it(int row, int columns) const;

	VECTOR row(int indx);
	VECTOR col(int indx);

	const MASSIVE& matr() const; // для константных объектов

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

	void generate();

public:
	double& operator()(int row, int col);
	const double& operator()(int row, int col) const; // для константных объектов

	MATRIX& operator=(const MATRIX& MATRIX);

	MATRIX operator+(const MATRIX&);
	MATRIX operator-(const MATRIX&);
	MATRIX operator*(const double&);
	MATRIX operator/(const double&);

	friend MATRIX operator*(const MATRIX& Matr1, const MATRIX& Matr2);
	friend MATRIX operator*(const double num, const MATRIX& Matr);

	friend bool operator== (const MATRIX& m1, const MATRIX& m2);
	friend bool operator!= (const MATRIX& m1, const MATRIX& m2);

	friend std::istream& operator>>(std::istream&, MATRIX&);
	friend std::ostream& operator<<(std::ostream&, const MATRIX&);
};
// Создание новой матрицы заданного размера и инициализирует все ее элементы нулевыми значениями. 
MATRIX::MATRIX(int rows, int columns) : n_rows(rows), n_cols(columns), size(n_rows * n_cols), data(nullptr) {
	data = new VECTOR[n_rows];

	for (int i = 0; i < n_rows; i++) {
		data[i] = new double[n_cols];
		for (int j = 0; j < n_cols; j++) {
			data[i][j] = 0;
		}
	}
}
// Создание новой матрицы
MATRIX::MATRIX(std::initializer_list<std::initializer_list<double>> matr) {

	n_rows = matr.size();
	n_cols = matr.begin()->size();
	size = n_rows * n_cols;

	data = new VECTOR[n_rows];

	auto it1 = matr.begin();
	for (int i = 0; i < n_rows; i++) {
		data[i] = new double[n_cols];
		auto it2 = it1->begin();
		for (int j = 0; j < n_cols; j++) {
			data[i][j] = *it2;
			it2++;
		}
		it1++;
	}
}
// создает новую матрицу, являющуюся точной копией существующей матрицы-аргумента.
MATRIX::MATRIX(const MATRIX& matrix) : n_rows(matrix.n_rows), n_cols(matrix.n_cols), size(matrix.size) {
	
	data = new VECTOR[n_rows];
	
	for (int i = 0; i < n_rows; i++) {
		data[i] = new double[n_cols];
		for (int j = 0; j < n_cols; j++) {
			data[i][j] = matrix.data[i][j];
		}
	}
}
// Этот деструктор отвечает за освобождение динамической памяти, выделенной для хранения матрицы. 
MATRIX::~MATRIX() {
	for (int i = 0; i < n_rows; i++)
		delete[] data[i];
	delete[] data;
}

int MATRIX::rowLen() const {
	return n_rows;
}

int MATRIX::colLen() const {
	return n_cols;
}

int MATRIX::dim() const {
	return size;
}
// функция позволяет безопасно изменить размер матрицы, сохраняя ее содержимое 
void MATRIX::resize(int newRow, int newCol, bool isSafeResize) {
	if (isSafeResize && newRow * newCol == size && newRow > 0 && newCol > 0) {

		VECTOR old_data = new double[size];
		int p = 0;
		for (int i = 0; i < n_rows; i++) {
			for (int j = 0; j < n_cols; j++) {
				old_data[p] = data[i][j];
				p++;
			}
		}

		for (int i = 0; i < n_rows; i++)
			delete[] data[i];
		delete[] data;

		n_rows = newRow;
		n_cols = newCol;

		data = new VECTOR[n_rows];

		for (int i = 0; i < n_rows; i++) {
			data[i] = new double[n_cols];
		}

		p = 0;
		for (int j = 0; j < n_cols; j++) {
			for (int i = 0; i < n_rows; i++) {
				data[i][j] = old_data[p];
				p++;
			}
		}

		delete[] old_data;
	}
}
// эта функция формирует строковое представление матрицы
string MATRIX::toString() const {

	stringstream ss;

	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_cols; j++) {
			ss << setw(6) << fixed << setprecision(2) << data[i][j] << " ";
		}
		ss << endl;
	}
	ss << endl;

	return ss.str();
}

void MATRIX::print() {
	cout << toString();
}

void MATRIX::setItem(int row, int columns, double value) {
	data[row][columns] = value;
}

void MATRIX::setRow(int rNum, VECTOR row) {
	for (int i = 0; i < n_cols; i++)
		data[rNum][i] = row[i];
}

void MATRIX::setCol(int cNum, VECTOR col) {
	for (int i = 0; i < n_rows; i++)
		data[i][cNum] = col[i];
}

double MATRIX::it(int row, int columns) const {
	return data[row][columns];
}

VECTOR MATRIX::row(int indx) {
	return data[indx];
}

VECTOR MATRIX::col(int indx) {
	VECTOR column = new double[n_rows];
	for (int i = 0; i < n_rows; i++) {
		column[i] = data[i][indx];
	}
	return column;
}


const MASSIVE& MATRIX::matr() const { 
	return data; 
} // для константных объектов

//Этот алгоритм основан на методе Гаусса для вычисления определителя матрицы. 
double MATRIX::det() {
	MATRIX matrix(*this);

	double determinant = 1;

	int size = n_rows;
	for (int i = 0; i < size; i++) {

		int pivot_index = -1;
		double pivot_value = 0;

		for (int j = i; j < size; j++) {
			if (abs(matrix.it(j, i)) > pivot_value) {
				pivot_index = j;
				pivot_value = abs(matrix.it(j, i));
			}
		}

		if (pivot_value < 1e-9)
			return 0;


		if (pivot_index != i) {
			for (int j = 0; j < n_cols; j++) {
				double tmp = matrix.it(i, j);
				matrix(i, j) = matrix.it(pivot_index, j);
				matrix(pivot_index, j) = tmp;
			}
			determinant *= -1;
		}

		for (int j = i + 1; j < size; j++) {
			if (matrix.it(j, i) != 0) {

				double multiplier = matrix.it(j, i) / matrix.it(i, i);

				for (int k = i; k < size; k++)
					matrix(j, k) -= matrix.it(i, k) * multiplier;
			}
		}

		determinant *= matrix.it(i, i);
	}

	return determinant;
}
// Транспонирование матрицы
MATRIX MATRIX::T() {
	MATRIX result(*this);

	result.resize(n_cols, n_rows);

	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_cols; j++) {
			result(j, i) = it(i, j);
		}
	}

	return result;
}
// Вычисление определителя
MATRIX MATRIX::M(int row, int col) {
	MATRIX result(n_rows - 1, n_cols - 1);

	for (int ii = 0; ii < row; ii++) {
		for (int jj = 0; jj < col; jj++)
			result(ii, jj) = it(ii, jj);

		for (int jj = col + 1; jj < n_cols; jj++)
			result(ii, jj - 1) = it(ii, jj);
	}

	for (int ii = row + 1; ii < n_rows; ii++) {
		for (int jj = 0; jj < col; jj++)
			result(ii - 1, jj) = it(ii, jj);

		for (int jj = col + 1; jj < n_cols; jj++)
			result(ii - 1, jj - 1) = it(ii, jj);
	}

	return result;
}
// Вычисляет минор
double MATRIX::Minor(int row, int col) {
	return M(row, col).det();
}
//Возвращает новую пустую матрицу
MATRIX MATRIX::MMatr() {
	return MATRIX();
}
//Вычисляет алгебраическое дополнение элемента
double MATRIX::ad(int row, int col) {
	return pow(-1, row + col) * Minor(row, col);
}
//Создает новую матрицу, размер которой совпадает с размером исходной матрицы. 
MATRIX MATRIX::adMatr() {
	MATRIX result(*this);

	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_cols; j++) {
			result(i, j) = ad(i, j);
		}
	}

	return result;
}
// Вычисляет обратную матрицу к исходной матрице
MATRIX MATRIX::inv() {
	MATRIX alg(adMatr().T());
	return alg * (1.0 / det());
}
//Проверяет, является ли матрица единичной
bool MATRIX::isE() {
	if (!isSqr())
		return false;

	for (int i = 0; i < n_rows; i++) {
		if (abs(it(i, i) - 1.0) > 1e-9) {
			return false;
		}
		for (int j = 0; j < n_cols; j++) {
			if (abs(it(i, j)) > 1e-9 and i != j)
				return false;
		}
	}

	return true;
}
//Проверяет, является ли матрица квадратной
bool MATRIX::isSqr() {
	return n_rows == n_cols;
}
//Эта функция решает систему линейных уравнений Ax = B. 
MATRIX MATRIX::solve(MATRIX A, MATRIX B) {
	//cout << A.inv();
	return A.inv() * B;
}

void MATRIX::generate() {
	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_cols; j++)
			data[i][j] = rand() % 9 + 1;
	}
}

double& MATRIX::operator()(int row, int col) {
	return data[row][col];
}

const double& MATRIX::operator()(int row, int col) const {
	return it(row, col);
}
//Этот перегруженный оператор =позволяет выполнять присваивание одной матрицы другой. 
MATRIX& MATRIX::operator=(const MATRIX& matrix) {
	if (this == &matrix)
		return *this;

	delete data;

	n_rows = matrix.n_rows;
	n_cols = matrix.n_cols;
	size = matrix.size;

	data = new VECTOR[n_rows];

	for (int i = 0; i < n_rows; i++) {
		data[i] = new double[n_cols];
		for (int j = 0; j < n_cols; j++) {
			data[i][j] = matrix.data[i][j];
		}
	}

	return *this;
}
//этот перегруженный оператор +позволяет складывать две матрицы, если они имеют одинаковые размеры. 
MATRIX MATRIX::operator+(const MATRIX& matrix) {
	if (n_rows != matrix.n_rows ||
		n_cols != matrix.n_cols)
		return MATRIX();

	MATRIX result(*this);

	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_cols; j++) {
			result(i, j) += matrix(i, j);
		}
	}

	return result;
}
//этот перегруженный оператор -позволяет вычитать одну матрицу из другой, если они имеют одинаковые размеры.  
MATRIX MATRIX::operator-(const MATRIX& matrix) {
	if (n_rows != matrix.n_rows ||
		n_cols != matrix.n_cols)
		return MATRIX();

	MATRIX result(*this);

	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_cols; j++) {
			result(i, j) -= matrix(i, j);
		}
	}

	return result;
}
//этот перегруженный оператор *позволяет умножать матрицу на скаляр, создавая новую матрицу с результатом. 
MATRIX MATRIX::operator*(const double& k) {
	MATRIX result(*this);
	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_cols; j++) {
			result(i, j) *= k;
		}
	}

	return result;
}
//этот перегруженный оператор /позволяет делить матрицу на скаляр, создавая новую матрицу с результатом. 
MATRIX MATRIX::operator/(const double& k) {
	if (abs(k) < 1e-9) {
		return MATRIX();
	}

	return (*this) * (1.0 / k);
}
//этот перегруженный оператор *позволяет умножать две матрицы, создавая новую матрицу с результатом. 
MATRIX operator*(const MATRIX& Matr1, const MATRIX& Matr2) { 
 if (Matr1.n_cols != Matr2.n_rows) 
  throw std::logic_error("Умножение матриц не возможно");
 
 MATRIX result(Matr1.n_rows, Matr2.n_cols); 
 for (int i = 0; i < Matr1.n_rows; i++) { 
  for (int j = 0; j < Matr2.n_cols; j++) { 
   result(i, j) = 0; 
   for (int k = 0; k < Matr1.n_cols; k++) { 
    result(i, j) += (Matr1.it(i, k) * Matr2.it(k, j)); 
   } 
  } 
 } 
 return result; 
}

//данная перегрузка оператора *позволяет умножать матрицу MATRIX на число

MATRIX operator*(const double num, const MATRIX& Matr) {
	return Matr * num;
}
//этот перегруженный оператор ==позволяет сравнивать две матрицы MATRIX на равенство. 

bool operator==(const MATRIX& m1, const MATRIX& m2) {
	if (m1.n_rows != m2.n_rows ||
		m1.n_cols != m2.n_cols)
		return false;

	for (int i = 0; i < m1.n_rows; i++) {
		for (int j = 0; j < m1.n_cols; j++) {
			if (abs(m1(i, j) - m2(i, j)) > 1e-9) {
				return false;
			}
		}
	}

	return true;
}
// данная перегрузка оператора != позволяет проверить, являются ли две матрицы MATRIX неравными.  

bool operator!= (const MATRIX& m1, const MATRIX& m2) {
	return !(m1 == m2);
}
//этот перегруженный оператор >> позволяет считывать матрицу MATRIX из входного потока std::istream.
std::istream& operator>>(std::istream& is, MATRIX& matrix) {
	stringstream ss;


	for (int i = 0; i < matrix.rowLen(); i++) {
		delete[] matrix.data[i];
	}

	delete[] matrix.data;

	matrix.n_rows = 0;

	string s;
	while (getline(is, s)) {

		matrix.n_cols = 1;
		bool is_num = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				if (is_num) {
					matrix.n_cols++;
				}
				is_num = false;
			}
			else {
				is_num = true;
			}
		}
		
		ss << s + '\n';
		matrix.n_rows++;
	}

	matrix.data = new VECTOR[matrix.n_rows];

	for (int i = 0; i < matrix.n_rows; i++) {
		matrix.data[i] = new double[matrix.n_cols];
		for (int j = 0; j < matrix.n_cols; j++) {
			ss >> matrix.data[i][j];
		}
	}
	return is;
}
// позволяет выводить матрицу в выходной поток std::ostream. 
std::ostream& operator<<(std::ostream& os, const MATRIX& matrix) {
	os << matrix.toString();
	return os;
}
//Этот набор тестов охватывает основные функциональные возможности класса MATRIX
void run_tests() {
	// Конструктор по умолчанию
	MATRIX m1;
	if (m1.rowLen() != 0)
    cout << "Assertion failed: m1.rowLen() should be 0, but it is " << m1.rowLen() << endl;
	if (m1.colLen() != 0)
    cout << "Assertion failed: m1.colLen() should be 0, but it is " << m1.colLen() << endl;
	if (m1.dim() != 0)
    cout << "Assertion failed: m1.dim() should be 0, but it is " << m1.dim() << endl;

	// Конструктор 1
	MATRIX m2(3, 4);
	if (m2.rowLen() != 3)
    cout << "Assertion failed: m2.rowLen() should be 3, but it is " << m2.rowLen() << endl;
	if (m2.colLen() != 4)
    cout << "Assertion failed: m2.colLen() should be 4, but it is " << m2.colLen() << endl;
	if (m2.dim() != 12) 
    cout << "Assertion failed: m2.dim() should be 12, but it is " << m2.dim() << endl;
		for (int i = 0; i < 3; i++) {
    		for (int j = 0; j < 4; j++) {
        		if (m2.it(i, j) != 0) 
            	cout << "Assertion failed: m2.it(" << i << ", " << j << ") should be 0, but it is " << m2.it(i, j) << endl;
    	}
	}

	// Конструктор 2
	int s = 12;
	VECTOR elems = new double[s];
	for (int i = 0; i < s; i++) {
		elems[i] = i;
	}

	MATRIX m3({ {1, 2}, {3, 4} });
	if (m3.rowLen() != 2)
    cout << "Assertion failed: m3.rowLen() should be 2, but it is " << m3.rowLen() << endl;
	if (m3.colLen() != 2)
    cout << "Assertion failed: m3.colLen() should be 2, but it is " << m3.colLen() << endl;

	
	if (m3(0, 0) != 1) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << m3(0, 0) << endl;
	if (m3(0, 1) != 2) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << m3(0, 1) << endl;
	if (m3(1, 0) != 3) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << m3(1, 0) << endl;
	if (m3(1, 1) != 4) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << m3(1, 1) << endl;
	
	delete[] elems;

	// Конструктор копирования
	MATRIX m5(m3);

	if (m5.rowLen() != 2)
    cout << "Assertion failed: m5.rowLen() should be 2, but it is " << m5.rowLen() << endl;
	if (m5.colLen() != 2) 
    cout << "Assertion failed: m5.colLen() should be 2, but it is " << m5.colLen() << endl;

	if (m5(0, 0) != 1) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << m5(0, 0) << endl;
	if (m5(0, 1) != 2) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << m5(0, 1) << endl;
	if (m5(1, 0) != 3) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << m5(1, 0) << endl;
	if (m5(1, 1) != 4) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << m5(1, 1) << endl;

	// Оператор присваивания
	m1 = m3;

	if (m1.rowLen() != 2)
    cout << "Assertion failed: m1.rowLen() should be 2, but it is " << m1.rowLen() << endl;
	if (m1.colLen() != 2) 
    cout << "Assertion failed: m1.colLen() should be 2, but it is " << m1.colLen() << endl;

	if (m1(0, 0) != 1) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << m1(0, 0) << endl;
	if (m1(0, 1) != 2) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << m1(0, 1) << endl;
	if (m1(1, 0) != 3) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << m1(1, 0) << endl;
	if (m1(1, 1) != 4) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << m1(1, 1) << endl;

	// Получение строки
	MATRIX m6(3, 4);
	m6(2, 0) = 1;
	m6(2, 1) = 2;
	m6(2, 2) = 3;
	m6(2, 3) = 4;
	
	VECTOR row = m6.row(2);
	
	if (row[0] != 1) 
    cout << "Assertion failed: row[0] should be 1, but it is " << row[0] << endl;
	if (row[1] != 2)
    cout << "Assertion failed: row[1] should be 2, but it is " << row[1] << endl;
	if (row[2] != 3)
    cout << "Assertion failed: row[2] should be 3, but it is " << row[2] << endl;
	if (row[3] != 4) 
    cout << "Assertion failed: row[3] should be 4, but it is " << row[3] << endl;

	// Получение столбца
	m6(0, 3) = 4;
	m6(1, 3) = 5;
	m6(2, 3) = 6;
	
	VECTOR column = m6.col(3);
	
	if (column[0] != 4)
    cout << "Assertion failed: column[0] should be 4, but it is " << column[0] << endl;
	if (column[1] != 5)
    cout << "Assertion failed: column[1] should be 5, but it is " << column[1] << endl;
	if (column[2] != 6)
    cout << "Assertion failed: column[2] should be 6, but it is " << column[2] << endl;

	
	delete[] column;

	// Запись элемента по индексам
	m3.setItem(0, 1, 45);
	if (m3(0, 1) != 45) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << m3(0, 1) << endl;

	// Запись строки в матрицу
	double row_elems[4] = { 11, 22, 33, 44 };
	m2.setRow(0, row_elems);
	if (m2(0, 0) != 11) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << m2(0, 0) << endl;
	if (m2(0, 1) != 22)
    cout << "Assertion failed: m2(0, 1) should be 22, but it is " << m2(0, 1) << endl;
	if (m2(0, 2) != 33)
    cout << "Assertion failed: m2(0, 2) should be 33, but it is " << m2(0, 2) << endl;
	if (m2(0, 3) != 44)
	cout << "Assertion failed: m2(0, 3) should be 44, but it is " << m2(0, 3) << endl;
	// Запись столбца в матрицу
	double col_elems[3] = { 55, 66, 77};
	m2.setCol(1, col_elems);
	if (m2(0, 1) != 55) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << m2(0, 1) << endl;
	if (m2(1, 1) != 66) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << m2(1, 1) << endl;
	if (m2(2, 1) != 77) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << m2(2, 1) << endl;

	// Проверка квадратной матрицы
	MATRIX m8(5, 5);
	if (!m8.isSqr())
    cout << "Assertion failed: m8 should be a square matrix, but it is not" << endl;
	if (m2.isSqr()) 
    cout << "Assertion failed: m2 should not be a square matrix, but it is" << endl;
	if (!m3.isSqr()) 
    cout << "Assertion failed: m3 should be a square matrix, but it is not" << endl;


	// Проверка единичной матрицы
	if (m8.isE())
    cout << "Assertion failed: m8 should not be an identity matrix, but it is" << endl;

		for (int i = 0; i < 5; i++)
    		m8(i, i) = 1;

		if (!m8.isE())
    	cout << "Assertion failed: m8 should be an identity matrix, but it is not" << endl;


	// Транспонирование матрицы
	MATRIX m9(2, 3);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			m9(i, j) = i + 2 * j;

	m9 = m9.T();
	for (int i = 0; i < 3; i++) {
    	for (int j = 0; j < 2; j++) {
        	if (m9(i, j) != 2 * i + j)
            	cout << "Assertion failed: m9(" << i << ", " << j << ") should be " << 2 * i + j << ", but it is " << m9(i, j) << endl;
    	}
	}

	
	// Получение минора
	MATRIX m10(3, 3);
	stringstream ss("1 4 7\n2 5 8\n3 6 9");
	ss >> m10;
	
	MATRIX minor(m10.M(0, 0));
	if (minor.rowLen() != 2) 
    cout << "Assertion failed: minor matrix should have 2 rows, but it has " << minor.rowLen() << endl;

	if (minor.colLen() != 2) 
    cout << "Assertion failed: minor matrix should have 2 columns, but it has " << minor.colLen() << endl;

	if (minor(0, 0) != 5) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << minor(0, 0) << endl;
	if (minor(0, 1) != 8) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << minor(0, 1) << endl;
	if (minor(1, 0) != 6) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << minor(1, 0) << endl;
	if (minor(1, 1) != 9) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << minor(1, 1) << endl;

	minor = m10.M(1, 2);
	if (minor.rowLen() != 2)
    cout << "Assertion failed: minor matrix should have 2 rows, but it has " << minor.rowLen() << endl;

	if (minor.colLen() != 2) 
    cout << "Assertion failed: minor matrix should have 2 columns, but it has " << minor.colLen() << endl;

	if (minor(0, 0) != 1) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << minor(0, 0) << endl;
	if (minor(0, 1) != 4) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << minor(0, 1) << endl;
	if (minor(1, 0) != 3) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << minor(1, 0) << endl;
	if (minor(1, 1) != 6) 
    cout << "Assertion failed: m2(0, 0) should be 11, but it is " << minor(1, 1) << endl;
	
	// Получение определителя
	MATRIX m11(2, 2);
	ss = stringstream("10 3\n2 5");
	ss >> m11;

	double expectedDet = 44.0;
	double actualDet = m11.det();
	if (actualDet != expectedDet)
    cout << "Assertion failed: det(m11) should be " << expectedDet << ", but it is " << actualDet << endl;

	m11 = MATRIX(3, 3);
	ss = stringstream("1 4 3\n5 5 8\n3 6 9");
	ss >> m11;

	expectedDet = -42.0;
	actualDet = m11.det();
	if (abs(actualDet - expectedDet) >= 1e-9)
    cout << "Assertion failed: det(m11) should be approximately " << expectedDet << ", but it is " << actualDet << endl;
}

int main() {
	//srand(time(0));
	
	run_tests();

	//MATRIX matrix(4, 4);
	//matrix.generate();
	MATRIX matrix{{1, 2, 3}, {5, 6, 7}, {9, 4, 1}};
	matrix.print();
	
	//MATRIX b(4, 1);
	//b.generate();
	MATRIX b{{1, 2, 3}};
	b.print();
	
	MATRIX X(MATRIX::solve(matrix, b));
	X.print();

	try {
    MATRIX RESULT = matrix * b; 
} 	catch (std::logic_error& error) {
    //cout << "Сделайте количество столбцов матрицы A, равным количеству строк матрицы B" << endl;
	cout << error.what() << endl;
}
	
	return 0;
}
