#pragma once
#ifndef Header_h
#define Header_h

class int_digit
{
public:
	int_digit()
	{
		a = 0;
		b = 0;
		c = 0;
		d = 0;
	}
	
	int_digit(int a, int b, int c, int d)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}

	double Funct()
	{
		double sum = 0;
		sum = (a + b + c + d)/4;
		return sum;
	}

	int max_digit()
	{
		int max;
		if ((a > b) && (a > c))
			max = a;
		else
		{
			if (b > c)
				max = b;
			else
				max = c;
		}
		if (d > max)
			max = d;
		return max;
	}

	~int_digit()
	{
		std::cout << "Изничтожено";
	};

private:
	int a;
	int b;
	int c;
	int d;
};
#endif /* Vector_h */