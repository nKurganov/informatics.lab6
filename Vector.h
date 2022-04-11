#pragma once
#include <iostream>

using namespace std;
class Iterator
{
	friend class Vector;
public:
	Iterator() { elem = 0; }
	Iterator(const Iterator& it) { elem = it.elem; }
	bool operator == (const Iterator& it) { return elem == it.elem; }
	bool operator != (const Iterator& it) { return elem != it.elem; }
	void operator++ () { ++elem; }
	void operator ++(int) { elem++; }
	void operator --() { --elem; }
	int& operator *() const { return *elem; }
private:
	int* elem;
};


class Vector
{
public:
	//конструкторы с параметрами
	//s - длина, k - значение каждого элемента
	Vector(int s, int k = 0);
	//клонирование
	Vector(const Vector& a);
	//деструктор
	~Vector();
	//перегрузка присваивания
	Vector& operator= (const Vector& a);
	//перегрузка обращения по индексу
	int& operator[] (int index);
	//перегрузка добавления
	Vector operator+(const int k);

	//возвращение длины вектора
	int operator()();
	Iterator first() { return beg; };
	Iterator last() { return end; }
	//перегрузка ввода вывода
	friend istream& operator>>(istream& in, Vector& a);
	friend ostream& operator<<(ostream& out, const Vector&a);
private:
	int size;
	int* data;
	Iterator beg;
	Iterator end;
};
