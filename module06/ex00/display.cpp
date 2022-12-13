#include "Convert.hpp"

void Convert::displayDouble()
{
	try
	{
		this->dvalue = std::stod(this->input);
		if (dvalue < 0 || dvalue > 255)
			std::cout << "char: Impossible" << std::endl;
		else
		{
			this->cvalue = static_cast<char>(this->dvalue);
			if (!std::isprint(this->cvalue))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: " << this->cvalue << std::endl;
		}
		if (this->dvalue <= std::numeric_limits<int>::max() && this->dvalue >= std::numeric_limits<int>::min())
		{
			this->ivalue = static_cast<int>(this->dvalue);
			std::cout << "int: " << this->ivalue << std::endl;
		}
		else
			std::cout << "int: Impossible" << std::endl;
		if (dvalue <= std::numeric_limits<float>::max() && dvalue >= std::numeric_limits<float>::min())
		{
			this->fvalue = static_cast<float>(this->dvalue);
			std::cout << "float: " << this->fvalue;
			if (this->fvalue - (int)this->fvalue == 0)
				std::cout << ".0";
			std::cout << "f" << std::endl;
		}
		else
			std::cout << "float: Impossible" << std::endl;
		std::cout << "double: " << this->dvalue << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "char: Inpossible" << std::endl;
		std::cout << "int: Inpossible" << std::endl;
		std::cout << "float: Impossible" << std::endl;
		std::cout << "double: Impossible" << std::endl;
	}
}

void Convert::displayFloat()
{
	try
	{
		this->fvalue = stof(this->input);
		if (fvalue < 0 || fvalue > 255)
			std::cout << "char: Impossible" << std::endl;
		else
		{
			this->cvalue = static_cast<char>(this->fvalue);
			if (!std::isprint(this->cvalue))
				std::cout << "char: Non displayable" << std::endl;
			else
				std::cout << "char: " << this->cvalue << std::endl;
		}
		if (this->fvalue <= std::numeric_limits<int>::max() && this->fvalue >= std::numeric_limits<int>::min())
		{
			this->ivalue = static_cast<int>(this->fvalue);
			std::cout << "int: " << this->ivalue << std::endl;
		}
		else
			std::cout << "int: Impossible" << std::endl;
		std::cout << "float: " << this->fvalue;
		if (this->fvalue - (int)this->fvalue == 0)
			std::cout << ".0";
		std::cout << "f" << std::endl;
		this->dvalue = static_cast<double>(this->fvalue);
	}
	catch (std::exception &e)
	{
		std::cout << "char: Inpossible" << std::endl;
		std::cout << "int: Inpossible" << std::endl;
		std::cout << "float: Impossible" << std::endl;
	}
	try
	{
		this->dvalue = std::stod(this->input);
		std::cout << "double: " << this->dvalue << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "double: Impossible" << std::endl;
	}
}

void Convert::displayInt()
{
	try
	{
		this->ivalue = std::stoi(this->input);
		this->fvalue = static_cast<float>(this->ivalue);
		this->dvalue = static_cast<double>(this->ivalue);
		if (this->ivalue < 0 || this->ivalue > 255)
			std::cout << "char: Impossible" << std::endl;
		else
			this->cvalue = static_cast<int>(this->ivalue);
		if (!std::isprint(this->cvalue))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: " << this->cvalue << std::endl;
		std::cout << "int: " << this->ivalue << std::endl;
		std::cout << "float: " << this->fvalue;
		if (this->fvalue - (int)this->fvalue == 0)
			std::cout << ".0";
		std::cout << "f" << std::endl;
		std::cout << "double: " << this->dvalue << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		try
		{
			this->dvalue = std::stod(this->input);
			try
			{
				this->fvalue = std::stof(this->input);
				std::cout << "float: " << this->fvalue;
				if (this->fvalue - (int)this->fvalue == 0)
					std::cout << ".0";
				std::cout << "f" << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cout << "float: Impossible" << std::endl;
			}
			std::cout << "double: " << this->dvalue << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << "float: Impossible" << std::endl;
			std::cout << "double: Imposible" << std::endl;
		}
	}
}

void Convert::displayChar()
{
	this->cvalue = this->input[0];
	if (!std::isprint(this->cvalue))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << this->cvalue << std::endl;
	this->ivalue = static_cast<int>(this->cvalue);
	this->fvalue = static_cast<float>(this->cvalue);
	this->dvalue = static_cast<double>(this->cvalue);
	std::cout << "int: " << this->ivalue << std::endl;
	std::cout << "float: " << this->fvalue;
	if (this->fvalue - (int)this->fvalue == 0)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << this->dvalue << std::endl;
}

void Convert::displayImpossible()
{
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: Impossible" << std::endl;
	std::cout << "double: Impossible" << std::endl;
}