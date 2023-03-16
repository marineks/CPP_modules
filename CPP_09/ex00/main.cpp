#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Correct usage is : ./btc <input db>" << std::endl;
		return (1);
	}
	else
	{
		BitcoinExchange test(argv[1]);
		return (0);
	}
}