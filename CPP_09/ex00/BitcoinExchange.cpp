#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream> // stringstream
#include <cstdlib> // atof
#include <iomanip> // setprecision

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

BitcoinExchange::BitcoinExchange(char const *input)
{
	// open data.csv
	std::stringstream	buffer;
	std::ifstream		csv_file("./data.csv");

	if (csv_file) {
		buffer << csv_file.rdbuf();
		csv_file.close();
	} else {
		std::cout << "Error : could not open the csv file.\n";
	}

	// parse csv and put in map container
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
	std::ifstream		file(input);

	// retrieve contents of the user's file
	if (file) {
		buffer << file.rdbuf();
		file.close();
	} else {
		std::cout << "Error : could not open the file.\n";
	}

	calculateUpdatedValue(buffer);
};

std::string	BitcoinExchange::isDateCorrect(std::string line)
{
	std::string date;

	date = (line.find_first_of(" ") != std::string::npos) ?
		date.assign(line, 0, line.find_first_of(" "))
		: date.assign(line, 0, std::string::npos);

	if (date.size() != 10)
		return "";
	
	size_t i = 0;
	while (i < 4)
	{
		if (!isdigit(date[i]))
			return "";
		i++;
	}
	if (date[i] != '-')
		return "";
	i++;
	while (i < 7)
	{
		if (!isdigit(date[i]))
			return "";
		i++;
	}
	if (date[i] != '-')
		return "";
	i++;
	while (i < 10)
	{
		if (!isdigit(date[i]))
			return "";
		i++;
	}
	return (date);
}

float	BitcoinExchange::isValueCorrect(std::string line)
{
	std::string val;
	if (val.find("|") + 1 != std::string::npos)
		val.assign(line, line.find("|") + 1, std::string::npos);
	
	// gestion de la virgule
	if (val.find(",") != std::string::npos)
		val.replace(val.find(","), 1, ".");

	float bitcoins = atof(val.c_str());
	return (bitcoins);
}

// do the bitcoin exchange for each line (error handling and exec)
void	BitcoinExchange::calculateUpdatedValue(std::stringstream& buffer)
{
	std::string line;
	
	while (std::getline(buffer, line))
	{
		std::string date;
		float val;

		if (line == "date | value")
			continue;
		if (line.find("|") == std::string::npos)
			std::cout << "Error : incorrect format (missing pipe)" << std::endl;
		else 
		{
			date = isDateCorrect(line);
			val = isValueCorrect(line);

			if (date.empty() == true)
				std::cout << "Error : incorrect format (date)" << std::endl;
			else if (val == 0.0) // means no conversion can be performed
				std::cout << "Error : incorrect format (value)" << std::endl;
			else if (val < 0)
				std::cout << "Error : not a positive number." << std::endl;
			else if (val > 1000 )
				std::cout << "Error : too large a number (> 1000)" << std::endl;
			else
			{
				// chercher la bonne date par la key
				std::map<std::string, float>::iterator it = _csv_db.find(date);
				if (it != _csv_db.end())
				{
					// print val * exchange rate
					std::cout << date << " => " << val << " = " << val * it->second << std::endl; 
				}
				else
				{
					std::map<std::string, float>::iterator closest_date = _csv_db.lower_bound(date);
					if (closest_date != _csv_db.begin())
					{
						closest_date--;
						std::cout << date << " (closest date [" << closest_date->first << "]) => " << val << " = " << val * closest_date->second << std::endl;
					}
					else
					{
						std::cout << "Error : the date you're looking for is older than our eldest date." << std::endl;
					}
				}
			}
		}
	}
}
