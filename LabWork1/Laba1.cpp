// Laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include "Header.h"
#include <cmath>

int main()
{
	int a, b, c, d, max; //дано четыре целых числа
	double sum; //для вычисления среднего арифметического

	std::cout << "enter four digits with space: " << std::endl;
	std::cin >> a >> b >> c >> d;

	int_digit Digits(a,b,c,d);
	sum = Digits.Funct();
	max = Digits.max_digit();

	std::cout << "arithmetic mean = " << sum << std::endl << "Max digit = " << max << std::endl;
	return 0;
}

