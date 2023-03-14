#include "PmergeMe.hpp"
#include <cstdlib> // atoi
#include <limits> // int max
#include <cstring> // strcmp
#include <algorithm> // advance, copy
#include <iomanip> // setprecision
#include <sys/time.h>

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
		this->_number_vector = rhs._number_vector;
		this->_number_list = rhs._number_list;
	}
	return *this;
};

/* Autre */

PmergeMe::PmergeMe(char **input)
{
	setNumberVector(input);
	setNumberList(_number_vector);
};

void	PmergeMe::setNumberVector(char **input)
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
		_number_vector.push_back(element);
	}
};


void	PmergeMe::setNumberList(std::vector<int> copy)
{
	for (size_t i = 0; i < copy.size(); i++)
	{
		_number_list.push_back(copy[i]);
	}
};

std::vector<int>	PmergeMe::getNumberVector(void) const 
{
	return (this->_number_vector);
};

std::list<int>	PmergeMe::getNumberList(void) const 
{
	return (this->_number_list);
};

std::ostream & operator<<(std::ostream & os, PmergeMe sort)
{
	std::string concl1 = "Time to process a range of ";
	std::string concl2 = " elements with std::vector<int> : ";
	std::string concl3 = " elements with std::list<int>   : ";
	std::vector<int> vect = sort.getNumberVector();
	std::list<int>	 list = sort.getNumberList();
	
	os << "Before : ";

	for (size_t i = 0; i < vect.size(); i++)
		os << vect[i] << " ";
	os << "\n";

	struct timeval start;
	struct timeval end;
	gettimeofday(&start, NULL);
	vect = sort.mergeSort(vect);
	gettimeofday(&end, NULL);

	os << "After  : ";
	for (size_t i = 0; i < vect.size(); i++)
		os << vect[i] << " ";
	os << "\n";

	std::cout << concl1 << vect.size() << concl2 << end.tv_usec - start.tv_usec << " us\n";

	gettimeofday(&start, NULL);
	list = sort.mergeSort(list);
	gettimeofday(&end, NULL);
	std::cout << concl1 << list.size() << concl3 << end.tv_usec - start.tv_usec << " us\n" ;
	
    return os;
};


// ###################################################
// ###################################################
// ########                                  #########
// ########            VECTOR                #########
// ########                                  #########
// ###################################################
// ###################################################

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

std::vector<int>	PmergeMe::insertionSort(std::vector<int>& array)
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
	return (array);
}

std::vector<int>	PmergeMe::mergeSort(std::vector<int>& array)
{
	if (array.size() <= 1) // list already sorted
		return array;
	
	if (_number_vector.size() <= THRESHOLD)
		return insertionSort(array);
	
	// partition the list of numbers in two parts
	std::vector<int> left_half;
	std::vector<int> right_half;

	left_half.assign(array.begin(), array.begin() + array.size() / 2);
	right_half.assign(array.begin() + array.size() / 2, array.end());

	// recursively sort the two partitions
	left_half = mergeSort(left_half);
	right_half = mergeSort(right_half);
	
	// merge them
	return mergeHalves(left_half, right_half);
		
};

std::vector<int>	PmergeMe::mergeHalves(std::vector<int>& left_half, std::vector<int>& right_half)
{
	std::vector<int> sorted;

	// Merge the halves : store l'élément le plus petit dans le temp vector sorted
	while (left_half.empty() == false && right_half.empty() == false)
	{
		if (left_half.front() <= right_half.front())
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
	return sorted;
};

// ###################################################
// ###################################################
// ########                                  #########
// ########              LIST                #########
// ########                                  #########
// ###################################################
// ###################################################



bool	PmergeMe::isSorted(std::list<int> array)
{
	std::list<int>::iterator it = array.begin();
	std::list<int>::iterator next_it;
	while (it != array.end())
	{
		next_it = it;
		next_it++;
		if (next_it != array.end() && *next_it < *it)
			return (false);
		it = next_it;
	}
	return (true);
}

std::list<int>	PmergeMe::insertionSort(std::list<int>& array)
{
	while (isSorted(array) == false)
	{
		std::list<int>::iterator it = array.begin();
        size_t i = 0;
        while (i < array.size())
        {
            std::list<int>::iterator next_it = it;
            next_it++;
            if (next_it != array.end() && *it > *next_it)
            {
                int tmp = *it;
                *it = *next_it;
                *next_it = tmp;
            }
            i++;
           it ++;
        }
	}
	return (array);
}

std::list<int>	PmergeMe::mergeSort(std::list<int>& array)
{
	if (array.size() <= 1) // list already sorted
		return array;
	
	if (_number_list.size() <= THRESHOLD)
		return insertionSort(array);
	
	// partition the list of numbers in two parts
	std::list<int> left_half;
	std::list<int> right_half;

	std::list<int>::iterator middle = array.begin();
	std::advance(middle, array.size() / 2);
	std::copy(array.begin(), middle, std::back_inserter(left_half));
	std::copy(middle, array.end(), std::back_inserter(right_half));

	// recursively sort the two partitions
	left_half = mergeSort(left_half);
	right_half = mergeSort(right_half);
	
	// merge them
	return mergeHalves(left_half, right_half);
		
};

std::list<int>	PmergeMe::mergeHalves(std::list<int>& left_half, std::list<int>& right_half)
{
	std::list<int> sorted;

	// Merge the halves : store l'élément le plus petit dans le temp list sorted
	while (left_half.empty() == false && right_half.empty() == false)
	{
		if (left_half.front() <= right_half.front())
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

	// Insert all the remaining values into the list sorted
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
	return sorted;
};
