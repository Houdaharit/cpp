#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::vector<int> v;

	if (argc > 1)
	{
		if (check_input(argc, argv) == -1)
			return 1;
		sort_vector(argc, argv);
		sort_deque(argc, argv);
	}
	return 0;	
}
