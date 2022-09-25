#include "PhoneBook.hpp"

int main()
{
	PhoneBook PB;
	Contact	contact = add();
	PB.max = 0;
	PB.contacts[0] = contact;
	PB.max++;
	display_PB(PB);
	return (0);
}
