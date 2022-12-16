#include "Span.hpp"

Span::Span() : n(0)
{
}

Span::Span(unsigned int& n) : n(n)
{
}

Span::Span(const Span& span)
{
	this->n = span.n;
	this->v = span.v;
}

Span& Span::operator=(const Span& span)
{
	if (this != &span)
	{
		this->n = span.n;
		this->v = span.v;
	}
	return (*this);
}

int Span::operator[](int index)
{
	if (index < 0 || (size_t)index > this->v.size())
		throw IndexOutOfBoundsException();
	return this->v[index];
}

void Span::addNumber(int number)
{
	if (v.size() < this->n)
		v.push_back(number);
	else
		throw NoMoreSpace(); 
}

int Span::shortestSpan()
{
	int shortest = INT_MAX;
	std::vector<int> _v = this->v;

	std::sort(_v.begin(), _v.end());
	for (size_t i = 0; i < _v.size(); i++)
	{
		if (abs(_v[i+1] - _v[i]) < shortest)
			shortest = abs(_v[i+1] - _v[i]);
	}
	return (shortest);
}

int Span::longestSpan()
{
	int min = *std::min_element(this->v.begin(), this->v.end());
	int max = *std::max_element(this->v.begin(), this->v.end());
	return (abs(max- min));
}	

/*template <typename T> void Span::addManyNumbers(typename T::iterator first, typename T::iterator last)
  {
  typename T::iteretor itr;
  for (itr = first; itr != last; itr++)
  addNumber(*itr);

  }
 */
Span::~Span()
{
}
