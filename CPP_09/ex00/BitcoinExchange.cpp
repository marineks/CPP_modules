#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib> // atof
#include <iomanip>

/* FORME COPLIENNE */

BitcoinExchange::BitcoinExchange(){};
BitcoinExchange::~BitcoinExchange(){};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
	return;
};

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
		this->_csv_db = rhs._csv_db;
	}
	return *this;
};

/*
Ressources :
https://stackoverflow.com/questions/132358/how-to-read-file-content-into-istringstream
*/
BitcoinExchange::BitcoinExchange(char const *input)
{
	(void)input;
	std::stringstream	buffer;
	std::ifstream		csv_file("./data.csv");

	if (csv_file) {
		buffer << csv_file.rdbuf();
		csv_file.close();
	} else {
		std::cout << "Error when trying to open the csv file.\n";
	}

	// parse and put in map container
	std::string input_data = buffer.str();
	std::string line;
	while (std::getline(buffer, line))
	{
		
		std::string key;
		std::string value;

		key.assign(line, 0, line.find(","));
		
		value.assign(line, line.find(",") + 1, std::string::npos);
		
		float exchange_rate = atof(value.c_str());
		
		// DEBUG
		// std::cout << "Line : " << line << std::endl;
		// std::cout << "Key   : " << key << std::endl;
		// std::cout << "Value : " << value << std::endl;
		// std::cout << "Excha : " << std::fixed << std::setprecision(2) << exchange_rate << std::endl;

		_csv_db.insert(std::pair<std::string, int>(key, exchange_rate));
	}

	// buffer.clear();
	// std::ifstream		file(input);

	// // retrieve contents of the file
	// if (file)
	// {
		
	// 	buffer << file.rdbuf();
	// 	file.close();
	// } else {
	// 	std::cout << "Error when trying to open the file. Input incorrect or empty file\n";
	// }

	
	// do the bitcoin exchange for each line (error handling and exec)


};


std::ostream & operator<<(std::ostream & os, BitcoinExchange sort)
{
	(void) sort;
    return os;
};

const char * 	BitcoinExchange::FormatException::what (void) const throw() 
{
	return "Incorrect format (for more specifications see above).";
}

