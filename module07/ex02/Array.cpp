#include "Array.hpp"

template <class T> Array<T>::Array()
{
	this->array = NULL;
	this->size = 0;
}

template <class T> Array<T>::Array(unsigned int& n)
{
	this->array = new T[n];
	this->size = n;
}

template <class T> Array<T>::Array(const Array& a)
{
	this->array = new T[a.size];
	for (int i = 0; i < a.size; i++)
		this->array[i] = a.array[i];
	this->size = a.size;
}

template <class T> Array<T>&  Array<T>::operator=(const Array& a)
{
	if (this != &a)
	{
		this->size = a.size;
		for (int i = 0; i < a.size; i++)
			this->array[i] = a.array[i];
	}
	return (*this);
}

template <class T> T Array<T>::operator[](int index)
{
	if (index < 0 || index >= this->size)
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
	return (this->size);
}
