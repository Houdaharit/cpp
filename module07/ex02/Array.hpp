#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>

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
	public:
	Array();
	Array(unsigned int&);
	Array& operator=(const Array&);
	T operator[](int);
	Array(const Array&);
	~Array();
	int size() const;
};

#endif
