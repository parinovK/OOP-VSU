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
	List* head; //указатель на голову
	List* tail; //указатель на хвост/конец
	int count; //количество элементов очереди
};
#endif