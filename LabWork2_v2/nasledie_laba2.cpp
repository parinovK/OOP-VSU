// nasledie_laba2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//ООП вторая лаба.
/*
Класс-родитель: Комплексное число: действительная и мнимая часть числа
Класс-наследник: Комплексное сопротивление: сопротивление резистора (действительная часть), значение индуктивности (мнимая часть), угловая частота.
Вычислить модуль и аргумент комплексной проводимости участка цепи «резистор - индуктивность».
*/

#include <iostream>
#include <cmath>

using namespace std;

class complex //класс-родитель
{
public:
	complex(double deistv = 0, double mnim = 0)
	{
		this->mnim = mnim;
		this->deistv = deistv;
	}
	~complex() { cout << "Конструктор сработал! "; }

protected:
	double mnim;
	double deistv;
};

class nasled :public complex //класс-наследник
{
private:
	double uglovaya_chastota;
public:
	nasled(double deistv, double mnim, double uglovaya_chastota = 0):complex(deistv, mnim)
	{
		this->uglovaya_chastota = uglovaya_chastota;
	}

	void show()
	{
		cout << "Сопротивление резистора = " << deistv << ", значение индуктивности = " << mnim << ", угловая частота  = " << uglovaya_chastota;
	}

	double absComplex()
	{
		double module = 0;
		module = 1/(sqrt(pow(deistv,2) + pow(mnim,2))); //находит модуль комплексного числа
		return abs(module);
	}

	double ArgcomplexProvod()
	{
		double angle;
		angle = atan(((1/deistv - 1 /(uglovaya_chastota * mnim)) * deistv));
		return angle;
	}
		~nasled() {}
};

int main(int argc, const char* argv[])
{
	setlocale(0, "");

	nasled komp_chislo(4, 2, 3); //(сопротивление резистора (deistv), значение индуктивности(mnim)

	komp_chislo.show();
	cout << endl << "Модуль комплексного числа = " << komp_chislo.absComplex() << endl;
	cout << "Аргумент комплексной проводимости = " << komp_chislo.ArgcomplexProvod() << endl;

	return 0;
}
