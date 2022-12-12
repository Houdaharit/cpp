#include "Convert.hpp"

Convert::Convert() : input(""), cvalue(0), fvalue(0.0f), dvalue(0.0), ivalue(0)
{
}

Convert::Convert(std::string &str) : input(str), cvalue(0), fvalue(0.0f), dvalue(0.0), ivalue(0)

{
}

void Convert::display()
{
	char c = input_type(this->input);
	if (c == 'c')
		displayChar();
	if (c == 'f')
		displayFloat();
	if (c == 'd')
		displayDouble();
	if (c == 'i')
		displayInt();
	if (c == 'n')
		displayImpossible();
}

Convert::~Convert()
{
}
