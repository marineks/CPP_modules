#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iomanip>

int main(int argc, char **argv)
{
	//récupérer valeurs
	if (argc < 2)
	{
		std::cout << "You need to add a positive integer sequence as an argument." << std::endl;
		return (1);
	}
	else
	{
		try
		{
			PmergeMe test(argv);
			std::cout << test;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		

		return (0);
	}
}