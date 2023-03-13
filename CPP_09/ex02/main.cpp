#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	//récupérer valeurs
	if (argc < 2)
	{
		std::cout << "You need to add a positive integer sequence as an argument" << std::endl;
		return (1);
	}
	else
	{
		PmergeMe test(argv);
		return (0);
	}
}