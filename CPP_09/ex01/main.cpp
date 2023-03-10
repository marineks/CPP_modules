#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN test(argv[1]);
		return (0);
	}
	else
	{
		std::cout << "Correct usage is `./RPN <inverted Polish expression>` :] " << std::endl;
		return (1);
	}
	
}
