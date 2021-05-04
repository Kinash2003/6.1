// Array.cpp
#include "Array.h"
#include <iostream>
#include <stdexcept>
#include <exception>

using namespace std;

Array::Array(const size_type& n)//конструктор для створення контейнера
throw(bad_alloc, invalid_argument)
{
	First = 0;
	Count = Size = n;
	elems = new double[Size];
	for (unsigned int i = 0; i < Size; i++)
		elems[i] = 0;
}
Array::Array(const double* first, const double* last)//конструктор для створення контейнера
throw(bad_alloc, invalid_argument)//специфікація винятків
{
	First = 0;
	if (first <= last) {
		Count = Size = (last - first) + 1;
		elems = new double[Size];
		for (unsigned int i = 0; i < Size; ++i)
			elems[i] = 0;
	}
	else
		throw invalid_argument("!!!");
}
Array::Array(const size_type first, const size_type last)//конструктор для створення контейнера
throw(bad_alloc, invalid_argument)//специфікація винятків
{
	if (first <= last) {
		First = first;
		Count = Size = (last - first) + 1;
		elems = new double[Size];
		for (unsigned int i = 0; i < Size; ++i)
			elems[i] = 0;
	}
	else
		throw invalid_argument("!!!");
}
Array::Array(const Array& t) throw(bad_alloc)//конструктор копіювання
	: Size(t.Size), Count(t.Count), First(t.First), elems(new double[Size])
{
	for (unsigned int i = 0; i < Size; ++i)
		elems[i] = t.elems[i];
}
Array& Array::operator =(const Array& t)//Присвоєння
{
	Array tmp(t);
	swap(tmp);
	return *this;
}
Array::~Array()//Деструктор
{
	delete[]elems;
	elems = 0;
}
void Array::push_back(const double& v)
{
	if (Count == Size) //місця нема
		resize(Size * 2); //збільшили "місткість"
	elems[Count++] = v;//присвоїли
}

//доступ до елементів контейнера
double& Array::operator [](size_type index) throw(out_of_range)
{
	if ((First <= index) && (index < First + Size))
		return elems[index - First];
	else
		throw out_of_range("Index out of range!");
}
const double& Array::operator [](size_type index) const
throw(out_of_range)
{
	if ((First <= index) && (index < First + Size))
		return elems[index - First];
	else
		throw out_of_range("Index out of range!");
}

void Array::resize(size_type newsize) throw(bad_alloc)//змінити розмір контейнера
{
	if (newsize > capacity())
	{
		double* data = new double[newsize];
		for (size_type i = 0; i < Count; ++i)
			data[i] = elems[i];
		delete[] elems;
		elems = data;
		Size = newsize;
	}
}

void Array::swap(Array& other)
{
	std::swap(elems, other.elems); //функція обміну
	std::swap(Size, other.Size);
}

Array::size_type Array::capacity() const //виділено пам’яті для елементів
{
	return Size;
}
Array::size_type Array::size() const  //кількість елементів в контейнері
{
	return Count;
}
bool Array::empty() const//перевірка на наявність елементів в контейнері
{
	return Count == 0;
}
ostream& operator <<(ostream& out, const Array& tmp)// Функція виводу даних
{
	for (size_t j = 0; j < tmp.Count; j++)
		cout << tmp[j] << " ";
	cout << endl;
	return out;
}
istream& operator >>(istream& in, const Array& tmp)//Функція ввід даних
{
	for (int i = 0; i < tmp.size(); i++)
	{
		cout << "arr[" << i << "] = ";
		in >> tmp[i];
	}
	return in;
}
void Array::pop_back() throw(bad_alloc)
{
	if (size() > 0)
	{
		double* tmp = new double[size() - 1];
		for (size_type i = 0; i < size() - 1; ++i)
			tmp[i] = elems[i];
		delete[] elems;
		elems = tmp;
		Size = size() - 1;
	}
}


void Array::Print()
{
	for (int i = 0; i < size(); i++)
		cout << elems[i] << " ";
	cout << "\n\n";
}
double Array::Sum() const
{
	int sum = 0;

	for (int i = 0; i < size(); i++)
		sum += elems[i];

	return sum;
}

double Array::Number() const
{
	double Number;

	for (int i = 0; i < size(); i++)
		if (elems[i] < 0)
		{
			Number = elems[i];
			break;
		}

	return Number;
}
void Array::Subtract()
{
	double Number = this->Number();

	for (int i = 0; i < size(); i++)
	{
		
		elems[i] += ((Number + elems[51]) / 2.);
		
	}
}