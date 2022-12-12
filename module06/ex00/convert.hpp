#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <iostream>
#include <sstream>

class NotEnoughArgumentsException : public std::exception
{
	public:
	virtual const char* what() const throw()
	{
		return "Not enough arguments!";
	}
};

class TooManyArgumentsException : public std::exception
{
	public:
	virtual const char* what() const throw()
	{
		return "Too many arguments!";
	}
};

class Convert
{
	std::string input;

	public:
	Convert();
	Convert(std::string&);
	~Convert();
};
int isChar(std::string&);
int isFloat(std::string&);
int isInt(std::string&);
#endif
