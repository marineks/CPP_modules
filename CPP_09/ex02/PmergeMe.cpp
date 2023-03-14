#include "PmergeMe.hpp"
#include <cstdlib> // atoi
#include <limits> // int max
#include <cstring> // strcmp

#define THRESHOLD 7
// sources pour cette value : 
// https://stackoverflow.com/questions/47945589/why-is-insertion-sort-on2-better-at-sorting-small-array-7-elements-compare
// https://www.quora.com/For-small-arrays-insertion-sort-is-faster-than-merge-sort-An-optimization-to-merge-sort-would-use-insertion-sort-if-the-array-is-small-enough-at-any-step-How-will-you-decide-the-length-of-the-largest-array-thatll-be


/* FORME COPLIENNE */

PmergeMe::PmergeMe(){};
PmergeMe::~PmergeMe(){};

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
	return;
};

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
	setNumberList(input);
	mergeSortVector(_number_list);
	std::cout << "After : " << _number_list << std::endl;
};

// TODO : checker les doublons
void	PmergeMe::setNumberList(char **input)
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
	std::cout << "Before : " << _number_list << std::endl;
};

std::vector<int>	PmergeMe::getNumberList(void) const 
{
	return (this->_number_list);
};

bool	PmergeMe::isSorted(std::vector<int> array)
{
	size_t i = 0;
	while (i < array.size() - 2)
	{
		if (array[i + 1] && array[i] > array[i + 1])
			return (false);
		i++;
	}
	return (true);
}

void	PmergeMe::insertionSortVector(std::vector<int>& array)
{
	while (isSorted(array) == false)
	{
		std::vector<int>::iterator it = array.begin();
		size_t i = 0;
		while (i < array.size())
		{
			if (it[i + 1] && it[i] > it[i + 1])
			{
				int tmp;
				tmp = array.at(i);

				array.erase(array.begin() + i);
				array.insert(array.begin() + (i + 1), tmp);
			}
			i++;
		}
	}
}

void	PmergeMe::mergeSortVector(std::vector<int>& array)
{
	if (_number_list.size() <= 1) // list already sorted
		return ;
	
	if (_number_list.size() <= THRESHOLD)
	{
		insertionSortVector(array);
		return ;
	}
	
	// partition the list of numbers in two parts
	std::vector<int> left_half;
	std::vector<int> right_half;
	left_half.assign(array.begin(), array.begin() + array.size() / 2);
	right_half.assign(array.begin() + array.size() / 2 + 1, array.end());
	
	// recursively sort the two partitions
	mergeSortVector(left_half);
	mergeSortVector(right_half);
	
	// merge them
	mergeHalves(_number_list, left_half, right_half);
		
};

void	PmergeMe::mergeHalves(std::vector<int>& list, std::vector<int>& left_half, std::vector<int>& right_half)
{
	(void) list;
	std::vector<int> sorted;

	// Merge the halves : store l'élément le plus petit dans le temp vector sorted
	while (left_half.empty() == false && right_half.empty() == false)
	{
		if (left_half.front() < right_half.front())
		{
			sorted.push_back(left_half.front()); // on push la valeur la plus petite
			left_half.erase(left_half.begin()); // on l'efface du sub array
		}
		else
		{
			sorted.push_back(right_half.front());
			right_half.erase(right_half.begin());
		}
	}

	// Insert all the remaining values into the vector sorted
	while (left_half.empty() == false)
	{
		sorted.push_back(left_half.front());
		left_half.erase(left_half.begin());
	}

	while (right_half.empty() == false)
	{
		sorted.push_back(right_half.front());
		right_half.erase(right_half.begin());
	}
};


std::ostream & operator<<(std::ostream & os, std::vector<int> list)
{
    for (size_t i = 0; i < list.size(); i++)
	{
		os << list[i] << " ";
	}
    return os;
};