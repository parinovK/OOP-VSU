#pragma once
#ifndef ADD_H
#define ADD_H

template <typename T>
class Queue
{
	struct List
	{
		List* Next;
		T data;
	};

public:
	Queue();
	bool Empty();
	void add(T);
	void DelElement();
	void output();
	~Queue();
private:
	List* head; //��������� �� ������
	List* tail; //��������� �� �����/�����
	int count; //���������� ��������� �������
};
#endif