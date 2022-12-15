#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <algorithm>
#include <vector>

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
	~Span();
	void addNumber(int);
	void addManyNumbers();
	int shortestSpan();
	int longestSpan();
};

#endif
