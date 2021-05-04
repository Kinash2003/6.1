// Array.h
#pragma once
#include <iostream>

using namespace std;

class Array
{
public:
	typedef unsigned int UINT;
	typedef double value_type;
	typedef double* iterator;
	typedef const double* const_iterator;
	typedef double& reference;
	typedef const double& const_reference;
	typedef std::size_t size_type;
private:
	static const size_type minsize = 10; // ��������� ����� ������
	size_type Size; // ������� ����� ��� ��������
	size_type Count; // ������� �������� � �����
	size_type First; // �������� ������� ������� �������� � �����
	double* elems;// �������� �� ���
public:
	Array(const size_type& n = minsize)	throw(bad_alloc, invalid_argument);
	Array(const Array&) throw(bad_alloc);
	Array(const double* first, const double* last) throw(bad_alloc, invalid_argument);
	Array(const size_type first, const size_type last) throw(bad_alloc, invalid_argument);
	~Array();
	Array& operator=(const Array&);

	
	double* begin() { return elems; }
	const double* begin() const { return elems; }
	double* end() { return elems + Count; }
	const double* end() const { return elems + Count; }

	
	size_type size() const; 
	bool empty() const; 
	size_type capacity() const; 
	void resize(size_type newsize) 
		throw(bad_alloc);

	
	double& operator[](size_type) throw(out_of_range);
	const double& operator[](size_type) const throw(out_of_range);
	double& front() { return elems[0]; }
	const double& front() const { return elems[0]; }
	double& back() { return elems[size() - 1]; }
	const double& back() const { return elems[size() - 1]; }

	
	void push_back(const double& v); 
	void pop_back(); 
	void clear() { Count = 0; } 
	void swap(Array& other); 

	
	friend ostream& operator <<(ostream& out, const Array& a);
	friend istream& operator >>(istream& in, Array& a);

	
	
	double Sum() const;
	void Print();
	void Subtract();
	double Number() const;
};
