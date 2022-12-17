#ifndef MUTANTSTACK_HPP
#define MUTANSTACK_HPP
#include <iostream>
#include <stack>
#include <queue>
#include <list>

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){};
		MutantStack(const MutantStack& ms){*this=ms;}
		MutantStack& operator=(const MutantStack& ms){*this = ms;  return *this;}
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
		~MutantStack(){};
};

#endif
