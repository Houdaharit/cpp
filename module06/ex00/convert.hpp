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
	char cvalue;
	float fvalue;
	double dvalue;
	int ivalue;
	public:
void display();
	void displayChar();
	void displayInt();
	void displayDouble();
	void displayFloat();
	void displayImpossible();
	Convert();
	Convert(std::string&);
	Convert(const Convert&);
	Convert& operator=(const Convert&);
	~Convert();
};
int input_type(std::string&);
#endif
