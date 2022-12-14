#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <exception>

class IndexOutOfBoundsException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "index out of bounds";
	}
};

template <class T>
class Array
{
	T* array;
	int _size;
	public:
	Array();
	Array(unsigned int&);
	Array& operator=(const Array&);
	T operator[](int);
	Array(const Array&);
	~Array();
	int size() const;
	void setValues(int, T);
};
#include "Array.tpp"

#endif
