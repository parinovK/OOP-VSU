// Laba4_OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//ООП лабораторная работа #4

/*
	По поводу самой	 лабы: 
	x, e1, e2 - значения, которые передаются с объектами в класс-родитель
	NechetNumber - берёт эти x,e1,e2 и путем преобразований получает те же x,e1,e2, но уже найденые по формуле нечетких чисел (а-ля a1,a2,a3)
	Оператор перегрузки вывода выводит именно x,e1,e2, которые a1,a2,a3
	оператор перегрузки ввода принимает самые обычные x,e1,e2
	в операторах + - / мы получаем "a1,a2,a3" то есть значения сразу готовые. А используем те самые x,e1,e2 - которые передаются с A и B
*/

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Triad //класс-родитель
{
protected:
	double x;
	double e1;
	double e2;

public:

	Triad(double x = 0, double e1 = 0, double e2 = 0)
	{
		this->x = x;
		this->e1 = e1;
		this->e2 = e2;
	}

	friend std::ostream& operator<<(std::ostream &os, Triad other);
	friend std::istream& operator>>(std::istream& is, Triad& other);

	~Triad() {}
};

class FazzyNumber : public Triad //класс-потомок
{
public:

	FazzyNumber(double x = 0, double e1 = 0, double e2 = 0) : Triad(x,e1,e2){}

	FazzyNumber NechetNumber() //получаем тройку нечетких чисел
	{
		FazzyNumber new_numb;
		double tmp = this->x;
		new_numb.e1 = tmp - this->e1;
		new_numb.e2 = tmp + this->e2;
		new_numb.x = tmp;
		return new_numb;
	}

	FazzyNumber operator+(FazzyNumber other)
	{
		FazzyNumber new_numb;
		new_numb.x = this->x + other.x;
		new_numb.e1 = this->x + other.x - this->e1 - other.e1;
		new_numb.e2 = this->x + other.x + this->e2 + other.e2;
		return new_numb;
	};

	FazzyNumber operator-(FazzyNumber other)
	{
		FazzyNumber new_numb;
		new_numb.x = this->x - other.x;
		new_numb.e1 = this->x - other.x - this->e1 - other.e1;
		new_numb.e2 = this->x - other.x + this->e2 + other.e2;
		return new_numb;
	};

	FazzyNumber operator*(FazzyNumber other)
	{
		FazzyNumber new_numb;
		new_numb.x = this->x * other.x;
		new_numb.e1 = this->x * other.x - other.x * this->e1 - this->x * other.e1 + this->e1 * other.e1;
		new_numb.e2 = this->x * other.x + other.x * this->e2 + this->x * other.e2 + this->e2 * other.e2;
		return new_numb;
	};

	FazzyNumber reverse()
	{
		FazzyNumber new_numb;
		if (this->x > 0)
		{
			new_numb.x = 1 / this->x;
			new_numb.e1 = 1 / (this->x + this->e2);
			new_numb.e2 = 1 / (this->x - this->e1);
		}
		return new_numb;
	};

	FazzyNumber operator/(FazzyNumber other)
	{
		FazzyNumber new_numb;
		if (other.x > 0)
		{
			new_numb.x = this->x / other.x;
			new_numb.e1 = (this->x - this->e1) / (other.x + other.e2);
			new_numb.e2 = (this->x + this->e2) / (other.x - other.e1);
		}
		return new_numb;
	};
	~FazzyNumber() {}
};

std::ostream& operator<<(std::ostream& os, Triad other)
{
	os << "(" << other.e1 << "; " << other.x << "; " << other.e2 << ")" << endl;
	return os;
}

std::istream& operator>>(std::istream& is, Triad &other)
{
	is >> other.x >> other.e1 >> other.e2;
	return is;
}

int main()
{
	setlocale(0, "");

	FazzyNumber A;			
	cout << "Введите 3 числа: ";
	cin >> A;
	
	FazzyNumber B;
	cout << "Введите 3 числа: ";
	cin >> B;

	FazzyNumber new_n;

	cout << "Тройка чисел (A): ";
	new_n = A.NechetNumber();
	cout << new_n << endl;

	cout << "Тройка чисел (B): ";
	new_n = B.NechetNumber();
	cout << new_n << endl;

	new_n = A+B;
	cout << "Сложение:" << new_n << endl;
	new_n = A-B;
	cout << "Вычитание:" << new_n << endl;
	new_n = A*B;
	cout << "Умножение:" << new_n << endl;
	new_n = A/B;
	cout << "Деление:" << new_n << endl;
	new_n = A.reverse();
	cout << "Обратное число : " << new_n << endl;

	return 0;
}