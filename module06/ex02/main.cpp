#include "Base.hpp"
#include "B.hpp"
#include "C.hpp"
#include "A.hpp"

int main()
{
	Base* b = generate();
	identify(b);
	(void)b;
}
