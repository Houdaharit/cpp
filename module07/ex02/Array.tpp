#ifndef ARRAY_TPP
#define ARRAY_TPP
#include "Array.hpp"

template <class T> Array<T>::Array()
{
	this->array = NULL;
	this->_size = 0;
}

template <class T> Array<T>::Array(unsigned int& n)
{
	this->array = new T[n];
	this->_size = n;
}

template <class T> Array<T>::Array(const Array& a)
{
	this->array = new T[a._size];
	for (int i = 0; i < a._size; i++)
		this->array[i] = a.array[i];
	this->_size = a._size;
}

template <class T> Array<T>&  Array<T>::operator=(const Array& a)
{
	if (this != &a)
	{
		this->_size = a._size;
		for (int i = 0; i < a._size; i++)
			this->array[i] = a.array[i];
	}
	return (*this);
}

template <class T> T Array<T>::operator[](int index)
{
	if (index < 0 || index >= this->_size)
		throw IndexOutOfBoundsException();
	return this->array[index];
}

template <class T> Array<T>::~Array()
{
	if (this->array)
		delete[] this->array;
}

template <class T> int Array<T>::size() const
{
	return (this->_size);
}

template <class T> void Array<T>::setValues(int index, T& value)
{
	if (index < 0 || index >= this->_size)
		throw IndexOutOfBoundsException();
	this->array[index] = value;
}

#endif
