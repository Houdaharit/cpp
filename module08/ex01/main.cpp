#include "Span.hpp"

int main()
{
	unsigned int n = 5;

	Span sp = Span(n);
	try
	{
		sp.addNumber(-6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(10);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
