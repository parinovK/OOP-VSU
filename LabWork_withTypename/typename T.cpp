// typename T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Queue_class.h"

using namespace std;

template <typename T>
Queue<T>::Queue()
{
	head = NULL;
	tail = NULL;
	count = 0;
};

template <typename T>
bool Queue<T>::Empty()//проверка очереди на пустоту
{
	return count == 0;
};

template <typename T>
void Queue<T>::add(T value)//добавление элемента в очередь
{
	List* new_L = new List();
	new_L->data = value;
	new_L->Next = NULL;

	if (count == 0)//если в очереди нет ни одного элемента
	{
		head = tail = new_L;
	}
	else
	{
		tail->Next = new_L;
		tail = new_L;
	}
	count++;//тк в очереди стало на один эл больше
};

template <typename T>
void Queue<T>::DelElement()//извлечение элемента из очереди
{
	List* temp = head;
	if (temp != NULL)
	{
		head = head->Next;
		delete temp;
		count--;
	}
};

template <typename T>
void Queue<T>::output()//вывод очереди
{
	List* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->Next;
	};
};

template<typename T>
Queue<T>::~Queue()
{
	while (head != NULL)
		DelElement();
}

int main()
{
	setlocale(0, "");

	Queue <double> queue1;

	cout << "Введите данные(double) (пробел не учитывается как символ, 0 - конец ввода): ";
	double temp1;

	while (cin >> temp1)
	{
		if (temp1 == 0)
			break;
		queue1.add(temp1);
	};

	//проверка очереди на пустоту
	if (queue1.Empty() == true)
		cout << "Очередь пуста!" << endl;
	else
	{
		cout << "В очереди имеются данные!" << endl;
		//вывод заполненной очереди
		cout << "Очередь заполненная данными: ";
		queue1.output();
		cout << endl;
		//удаляем первый элемент из очереди
		queue1.DelElement();
		//вывод очередь без удаленного элемента
		cout << "Очередь, после удаления элемента: ";
		queue1.output();
		if (queue1.Empty() == true)
			cout << "Очередь пуста!" << endl;
	};

	cout << endl;
	
	  //===================================//
	 //             Другой объект         //
	//===================================//

	Queue <char> queue2;

	cout << "Введите данные(символы, предложение) (пробел не учитывается как символ, 0 - конец ввода): ";
	char temp2;
	while (cin >> temp2)
	{
		if (temp2 == '0')
			break;
		queue2.add(temp2);
	};
	//проверка очереди на пустоту
	if (queue2.Empty() == true)
		cout << "Очередь пуста!" << endl;
	else
	{
		cout << "В очереди имеются данные!" << endl;
		//вывод заполненной очереди
		cout << "Очередь заполненная данными: ";
		queue2.output();
		cout << endl;
		//удаляем первый элемент из очереди
		queue2.DelElement();
		//вывод очередь без удаленного элемента
		cout << "Очередь, после удаления элемента: ";
		queue2.output();
		if (queue2.Empty() == true)
			cout << "Очередь пуста!" << endl;
		cout << endl;
	};

	//===================================//
   //             Другой объект         //
  //===================================//

	Queue <int> queue3;

	cout << "Введите данные(целые) (пробел не учитывается как символ, 0 - конец ввода): ";
	int temp3;
	while (cin >> temp3)
	{
		if (temp3 == 0)
			break;
		queue3.add(temp3);
	};

	//проверка очереди на пустоту
	if (queue3.Empty() == true)
		cout << "Очередь пуста!" << endl;
	else
	{
		cout << "В очереди имеются данные!" << endl;
		//вывод заполненной очереди
		cout << "Очередь заполненная данными: ";
		queue3.output();
		cout << endl;
		//удаляем первый элемент из очереди
		queue3.DelElement();
		//вывод очередь без удаленного элемента
		cout << "Очередь, после удаления элемента: ";
		queue3.output();
		if (queue3.Empty() == true)
			cout << "Очередь пуста!" << endl;
		cout << endl;
	}

	return 0;
}