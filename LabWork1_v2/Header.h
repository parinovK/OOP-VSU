#pragma once
#ifndef Header_h
#define Header_h

class Vector
{
private:
	double x1;
	double x2;
	double y1;
	double y2;
	double Dlina_Vect;

public:
	Vector()
	{
		x1 = 0;
		y1 = 0;
		x2 = 0;
		y2 = 0;
		Dlina_Vect = 0;
	}

	Vector(int a, int b, int c, int d)
	{
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
		Dlina_Vect = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	}

	void Length_Vector()
	{
		std::cout << "Длина вектора (с координатами " << "x1 = " << x1 << "," << "y1 = " << y1 << " x2= " << x2 << "," << " y2 = " << y2 << ") = " << Dlina_Vect << std::endl;
	}
	void show()
	{
		std::cout<<"Координаты вектора"<<"x1="<<x1<<","<<"y1="<<y1<<"x2="<<x2<<","<<"y2="<<y2<<std::endl;
	}

	void scalyar_proizv(Vector &CD)
	{
		double angle;
		angle = ((this->x2 - this->x1) * (CD.x2 - CD.x1) + (this->y2 - this->y1) * (CD.y2 - CD.y1)) / (sqrt(pow((this->x2 - this->x1), 2) + pow((this->y2 - this->y1), 2)) * sqrt(pow((CD.x2 - CD.x1), 2) + pow((CD.y2 - CD.y1), 2)));
		double scalyar;
		scalyar = this->Dlina_Vect * CD.Dlina_Vect * cos(angle);
		std::cout << "Скалярное произведение векторов равно = " << scalyar << std::endl;
	}

	~Vector()
	{
		std::cout << "Вектор уничтожен"<<std::endl;
	};
};
#endif /* Vector_h */
