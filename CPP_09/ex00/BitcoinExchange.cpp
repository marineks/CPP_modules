#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream> // stringstream
#include <cstdlib> // atof
#include <iomanip> // setprecision
#include <regex>

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
		std::cout << "Error : could not open the csv file.\n";
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

		_csv_db.insert(std::pair<std::string, float>(key, exchange_rate));
	}

	buffer.clear();
	line.clear();
	std::ifstream		file(input);

	// // retrieve contents of the file
	if (file)
	{
		buffer << file.rdbuf();
		file.close();
	} else {
		std::cout << "Error : could not open the file.\n";
	}

	// do the bitcoin exchange for each line (error handling and exec)
	while (std::getline(buffer, line))
	{
		std::string date;
		std::string val;

		if (line == "date | value")
			continue;
		if ((date = isDateCorrect(line)) == false)
			std::cout << "Error : incorrect format (date)" << std::endl;
		if (line.find("|") == std::string::npos)
			std::cout << "Error : incorrect format (missing pipe)" << std::endl;
		if ((val = isValueCorrect(line)) == false)
			std::cout << "Error : incorrect format (value)" << std::endl;
		else
		{
			// date
			// val
			// use f lowerbound and decrement by one
		}
	}

};

bool	BitcoinExchange::isDateCorrect(std::string line)
{
	std::regex date_regex("\\d{4}-\\d{2}-\\d{2}");
	std::string date;

	date = (line.find_first_of(" ") != std::string::npos) ?
		date.assign(line, 0, line.find_first_of(" "))
		: date.assign(line, 0, std::string::npos);

	if (std::regex_match(date, date_regex))
		return (true);
	else
		return (false);
	// TODO : return la val et NULL si pas bon
}

bool	BitcoinExchange::isValueCorrect(std::string line)
{
	std::string val;
	val.assign(line, line.find("|") + 1, std::string::npos);
	
	// TODO : return la val et NULL si pas bon

}

std::ostream & operator<<(std::ostream & os, BitcoinExchange sort)
{
	(void) sort;
    return os;
};

const char * 	BitcoinExchange::FormatException::what (void) const throw() 
{
	return "Incorrect format (for more specifications see above).";
}

