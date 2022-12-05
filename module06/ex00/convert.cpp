#include "convert.hpp"

Convert::Convert(): input("") , cvalue(0), ivalue(0), dvalue(0.0), fvalue(0.0f)
{
}

void Convert::setValues()
{
	char type = input_type(this->input);
	std::stringstream str(this->input);
	if (type == 'i')
	{
		str >> this->ivalue;
		this->cvalue = static_cast<char>(this->ivalue);
		this->fvalue = static_cast<float>(this->ivalue);
		this->dvalue = static_cast<double>(this->ivalue);
	}
	if (type == 'd')
	{
		str >> this->dvalue;
		this->cvalue = static_cast<char>(this->dvalue);
		this->fvalue = static_cast<float>(this->dvalue);
		this->ivalue = static_cast<int>(this->dvalue);
	}
	if(type == 'f')
	{
		str >> this->fvalue;
		this->cvalue = static_cast<char>(this->fvalue);
		this->dvalue = static_cast<double>(this->fvalue);
		this->ivalue = static_cast<int>(this->fvalue);
	}
	if (type == 'c')
	{
		str >> this->cvalue;
		this->ivalue = static_cast<int>(this->cvalue);
		this->fvalue = static_cast<float>(this->cvalue);
		this->dvalue = static_cast<double>(this->cvalue);
	}
}

Convert::Convert(std::string& str) : input(str)
{
	setValues();
}

Convert::Convert(const Convert& convert)
{
	this->input = convert.input;
	this->ivalue = convert.ivalue;
	this->cvalue = convert.cvalue;
	this->fvalue = convert.fvalue;
	this->dvalue = convert.dvalue;
}

int Convert::getIvalue() const
{
	return this->ivalue;
}

char Convert::getCvalue() const
{
	return this->cvalue;
}

float Convert::getFvalue() const
{
	return this->fvalue;
}

double Convert::getDvalue() const
{
	return this->dvalue;
}

Convert& Convert::operator=(const Convert& convert)
{
	if (this != &convert)
	{
		this->input = convert.input;
		this->ivalue = convert.ivalue;
		this->cvalue = convert.cvalue;
		this->dvalue = convert.dvalue;
		this->fvalue = convert.fvalue;
	}
	return (*this);
}

Convert::~Convert()
{
}

std::ostream& operator<<(std::ostream& os, const Convert& convert)
{
	if (convert.getCvalue() < 32 || convert.getCvalue() > 126)
		os << "char: Non displayable" << std::endl;
	else
		os << "char: " << convert.getCvalue() << std::endl;
	os << "int: " << convert.getIvalue() << std::endl;
	os << "float: " << convert.getFvalue();
	if (!(convert.getFvalue() - (int)convert.getFvalue()))
		os << ".0f" << std::endl;
	else
		os << "f" << std::endl;
	os << "double: " << convert.getDvalue();
	if (!(convert.getDvalue() - (int)convert.getDvalue()))
		os << ".0" << std::endl;
	else
		os << std::endl;

	return os;
}
