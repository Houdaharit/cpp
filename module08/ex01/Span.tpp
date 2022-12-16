#ifndef SPAN_TPP
#define SPAN_TPP

template <typename T> void Span::addManyNumbers(T first, T last)
{
	T itr;
	for (itr = first; itr != last; itr++)
		addNumber(*itr);

}
#endif
