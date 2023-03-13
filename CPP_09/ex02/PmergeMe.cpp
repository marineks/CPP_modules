#include "PmergeMe.hpp"
#include <cstdlib> // atoi
#include <limits> // int max
#include <cstring> // strcmp

/* FORME COPLIENNE */

PmergeMe::PmergeMe(){};
PmergeMe::~PmergeMe(){};

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
	return;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		this->_number_list = rhs._number_list;
	}
	return *this;
};

/* Autre */

PmergeMe::PmergeMe(char **input)
{
	for (size_t i = 1; input[i]; i++)
	{
		long int element = atol(input[i]);
		if (element == 0 && strcmp(input[i], "0") != 0){
			std::cout << "Error : this is not a correctly formatted integer." << std::endl;
			return ;
		}
		if (element < 0) {
			std::cout << "Error : there is an int < 0 in this sequence." << std::endl;
			return ;
		} else if (element > std::numeric_limits<int>::max()) {
			std::cout << "Error : exceeds INT_MAX." << std::endl;
			return ;
		}
		_number_list.push_back(element);
	}
	std::cout << "List : " << _number_list << std::endl;
}

std::ostream & operator<<(std::ostream & os, std::vector<int> list)
{
    for (size_t i = 0; i < list.size(); i++)
	{
		os << list[i] << " ";
	}
    return os;
}