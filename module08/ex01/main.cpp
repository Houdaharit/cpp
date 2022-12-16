#include "Span.hpp"

int main()
{
	unsigned int n = 10000;

	Span sp = Span(n);
	std::vector<int> vc;
	for (int i = 0; i < 10000; i++)
		vc.push_back(i);
	try
	{
		/*sp.addNumber(-6);
		  sp.addNumber(3);
		  sp.addNumber(17);
		  sp.addNumber(9);
		  sp.addNumber(11);
		  sp.addNumber(10);*/
		sp.addManyNumbers(vc.begin(), vc.end());
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "shortest: "<< sp.shortestSpan() << std::endl;
	std::cout << "largest: "<<sp.longestSpan() << std::endl;
	return 0;
}
