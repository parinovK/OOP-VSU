// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//посчитать длину вектора и найти скалярное произведение двух векторов

#include <iostream>
#include "Header.h"
#include <cmath>

using namespace std;

int main()
{
	setlocale(0, "");
	double x1, x2, y1, y2; //Где (x1,y1) - Начало, (x2,y2) - конец вектора
		
	cout<<"Введите координаты вектора X:"<< endl;
	cin>>x1>>y1>>x2>>y2; 
		
	Vector AB(x1, y1, x2, y2);
	AB.show();
	AB.Length_Vector();
	
	cout << "Введите координаты вектора Y:" << endl;
	cin >> x1 >> y1 >> x2 >> y2;

	Vector CD(x1, y1, x2, y2);
	CD.show();
	CD.Length_Vector();

	AB.scalyar_proizv(CD);

	return 0;
}