#include <iostream>
using namespace std;

template<typename T>
class Point
{
	T x, y, z;
public:
	//конструктор без параметров
	Point()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	//конструктор с параметрами
	Point(T x, T y, T z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	//конструктор копирования
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
	}

	//перегрузка оператора =
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;
		return*this;
	}

	//перегрузка оператора +
	Point operator+(const Point& other)
	{
		Point tmp;
		tmp.x = this->x + other.x;
		tmp.y = this->y + other.y;
		tmp.z = this->z + other.z;
		return tmp;
	}

	//перегрузка оператора +=
	Point& operator+=(const Point& other)
	{
		this->x = this->x + other.x;
		this->y = this->y + other.y;
		this->z = this->z + other.z;
		return *this;
	}

	//перегрузка оператора ++ (префикс)
	Point operator++()
	{
		this->x++;
		this->y++;
		this->z++;
		return*this;
	}

	//перегрузка оператора ++ (постфикс)
	Point operator++(int value)
	{
		Point tmp(*this);
		this->x++;
		this->y++;
		this->z++;
		return tmp;
	}

	//перегрузка оператора <<
	friend ostream& operator<<(ostream& stream, const Point& other)
	{
		stream << other.x << " " << other.y << " " << other.z;
		return stream;
	}
};


template <typename T>
class Matrix
{
	T** arr;
	int line;
	int column;
public:
	//конструктор без параметров 
	Matrix()
	{

	}

	//конструктор с параметрами
	Matrix(int line, int column)
	{
		this->line = line;
		this->column = column;
		arr = new T * [line];
		for (int i = 0; i < line; i++)
		{
			arr[i] = new T[column];
		}
	}

	//конструктор копирования
	Matrix(const Matrix& other)
	{
		this->line = other.line;
		this->column = other.column;
		this->arr = new T * [line];
		for (int i = 0; i < line; i++)
		{
			this->arr[i] = new T[column];
		}
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < column; j++) {
				this->arr[i][j] = other.arr[i][j];
			}
		}
	}

	//перегрузка оператора =
	Matrix& operator=(const Matrix& other)
	{
		for (int i = 0; i < line; i++)
		{
			delete[] arr[i];
		}

		this->line = other.line;
		this->column = other.column;


		this->arr = new T * [other.line];
		for (int i = 0; i < other.line; i++)
		{
			this->arr[i] = new T[other.column];
		}
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < other.column; j++) {
				this->arr[i][j] = other.arr[i][j];
			}
		}
		return *this;
	}


	//перегрузка оператора +
	Matrix operator+(const Matrix& other)
	{
		if (this->arr != nullptr && other.arr != nullptr)
		{	
			if (this->line == other.line && this->column == other.column) {
				Matrix tmp(line,column);
				for (int i = 0; i < line; i++) {
					for (int j = 0; j < column; j++) {
						tmp.arr[i][j] = this->arr[i][j] + other.arr[i][j];
					}
				}
				return tmp;
			}
			else 
			{
				cout << "this->line != other.line or this->column != other.column";
			}
			

		}    
		else if(this->arr != nullptr && other.arr == nullptr)
		{
			return *this;

		}

		else if (this->arr == nullptr && other.arr != nullptr) 
		{
			return other;
		}

		else 
		{
			return *this;
		}
	}

	//заполнение массива int
	void filling_arr_int()		
	{
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < column; j++) {
				arr[i][j] = i * (line - 1) + j;
			}

		}
	}

	//заполнение массива char
	void filling_arr_char()
	{

		for (int i = 0; i < line; i++) {
			for (int j = 0; j < column; j++) {
				cin >> arr[i][j];
			}

		}
	}

	//пегрузка оператора <<
	friend ostream& operator<<(ostream& out, const Matrix<T>& other)
	{
		for (int i = 0; i < other.line; i++) {
			for (int j = 0; j < other.column; j++) {
				out << other.arr[i][j] << "\t";
			}
			out << endl;
		}
		return out;
	}

	//деструктор
	~Matrix()
	{
		for (int i = 0; i < line; i++)
		{
			delete[] arr[i];
		}
	}
};

int main()
{
	//Matrix<int> a(12, 13);
	//a.filling_arr_int();
	//cout << a << endl;

	Matrix<int> a(3, 3);
	Matrix<int> b(3, 3);
	a.filling_arr_int();
	b.filling_arr_int();
	

	Matrix<int> c = a + b;

	cout << c << endl;



	return 0;
}