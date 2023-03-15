#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	//récupérer valeurs
	if (argc != 2)
	{
		std::cout << "" << std::endl;
		return (1);
	}
	else
	{
		try
		{
			BitcoinExchange test(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		

		return (0);
	}
}