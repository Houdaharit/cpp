#include <iostream>
#include <string>
#include <sstream>

int main()
{
	std::string date("2022f-04-05");
	int day;
	int month;
	int year;
	char sep;

	std::istringstream iss(date);
	iss >> year >>month >> day;
	std::cout << year << " " << month << " " << day << std::endl; 
}
