#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctype.h>
#include <sstream>
#include <string>
#include <limits.h>



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
	char cvalue;
	int ivalue;
	double dvalue;
	float fvalue;
	public:
	Convert();
	Convert(std::string&);
	Convert(const Convert&);
	Convert& operator=(const Convert&);
	~Convert();
	void setValues();
	char getCvalue()const;
	int getIvalue() const;
	double getDvalue() const;
	float getFvalue() const;
};

std::ostream& operator<<(std::ostream& os, const Convert& convert);
char input_type(std::string&);
int display(const std::string&);
int check_inf(std::string&);
#endif
