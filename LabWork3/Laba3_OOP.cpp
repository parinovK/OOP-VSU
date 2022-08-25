// Laba3_OOP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

class Triad
{
public:
	Triad(int a = 0, int b = 0, int c = 0)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}

	void show()
	{
		cout << "тройка чисел : " << a << " " << b << " " << c << endl;
	}

	Triad operator+(const int e)
	{
		Triad tmp;
		tmp.a = a + e;
		tmp.b = b + e;
		tmp.c = c + e;
		return tmp;
	}

	Triad operator*(const int e)
	{
		Triad tmp;
		tmp.a = a * e;
		tmp.b = b * e;
		tmp.c = c * e;
		return tmp;
	}

	bool operator ==(Triad& other)
	{
		return (this->a == other.a && this->b == other.b && this->c == other.c);
	}

	~Triad() {}
protected:
	int a, b, c;
};

class Vector3D :public Triad
{
public:
	Vector3D(int a=0, int b=0, int c=0) :Triad(a, b, c) {}

	Vector3D Summa(Vector3D& other)
	{
		Vector3D vector;
		vector.a = this->a + other.a;
		vector.b = this->b + other.b;
		vector.c = this->c + other.c;
		return vector;
	}

	double scalyar(Vector3D& other)
	{
		double scalyar;
		scalyar = this->a * other.a + this->b * other.b + this->c * other.c;
		return scalyar;
	}

	~Vector3D() {}
};

int main()
{
	setlocale(0, "");

	int const e = 2;


	Triad tr(1, 2, 3);
	Triad tr2(1, 2, 3);
	Triad tr3;

	tr.show();
	cout << "Сумма с числом " << e << " - ";
	tr3 = tr+(e);
	tr3.show();
	cout << "Произведение с числом " << e << "- ";
	tr3 = tr*(e);
	tr3.show();

	if (tr==tr2)
		cout << "равны";
	else cout << "не равны";

	Vector3D vect(4, 5, 6);
	Vector3D vect2(7, 8, 9);
	Vector3D vec;
	vec = vect.Summa(vect2);
	cout << endl << "Сложение векторов - ";
	vec.show();
	cout << "Скалярное произведение векторов = " << vect.scalyar(vect2);

	return 0;
}