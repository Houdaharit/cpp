#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <iostream>
#include <cstdlib>
#include <string>

class NotEnoughArgumentsException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Not enough arguments!";
	}
}more_arguments;

class TooManyArgumentsException : public std::exception
{
	virtual const char* what() const throw()
	{
		return "Too many arguments!";
	}
}too_many_arguments;
#endif
