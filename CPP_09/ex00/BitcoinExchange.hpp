#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <ostream>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _csv_db;
	
	public:
		/* Forme canonique de Coplien */
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange&);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange&);
		
		/* Constructeur paramétrique */
		BitcoinExchange(char const *input);

		/* Méthodes */
		std::string	isDateCorrect(std::string line);
		float		isValueCorrect(std::string line);
		void		calculateUpdatedValue(std::stringstream&	buffer);
};

#endif