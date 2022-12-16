#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <algorithm>
#include <vector>

class IndexOutOfBoundsException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "index out of bounds";
	}
};

class NoMoreSpace : public std::exception
{
	public:
		const char* what() const throw()
		{
			return "No space left!";
		}
};
class Span
{
	std::vector<int> v;
	unsigned int n;
	public:
	Span();
	Span(unsigned int&);
	Span(const Span&);
	Span& operator=(const Span&);
	int operator[](int);
	~Span();
	void addNumber(int);
	template <typename T> void addManyNumbers(T, T);
	int shortestSpan();
	int longestSpan();
};

#include "Span.tpp"
#endif
