#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			RPN test(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		return (0);
	}
	else
	{
		std::cout << "Correct usage is `./RPN <inverted Polish expression>` :] " << std::endl;
		return (1);
	}
}
