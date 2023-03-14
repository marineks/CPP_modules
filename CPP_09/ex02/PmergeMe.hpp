#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <ostream>

class PmergeMe
{
	private:
		std::vector<int>	_number_vector;
		std::list<int>		_number_list;
	public:
		/* Forme canonique de Coplien */
		PmergeMe();
		PmergeMe(const PmergeMe&);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe&);
		
		/* Constructeur paramétrique */
		PmergeMe(char **input);

		/* Méthodes */
		bool						isSorted(std::vector<int> array);
		bool						isSorted(std::list<int> array);

		std::vector<int>			insertionSort(std::vector<int>& array);
		std::list<int>				insertionSort(std::list<int>& array);

		std::vector<int>			mergeSort(std::vector<int>& array);
		std::list<int>				mergeSort(std::list<int>& array);

		std::vector<int>			mergeHalves(std::vector<int>& left_half, std::vector<int>& right_half);
		std::list<int>				mergeHalves(std::list<int>& left_half, std::list<int>& right_half);

		/* Accesseurs */
		void				setNumberVector(char **input);
		void				setNumberList(std::vector<int> copy);
		std::vector<int>	getNumberVector(void) const;
		std::list<int>		getNumberList(void) const;
};

std::ostream & operator<<(std::ostream & os, std::vector<int> list);

#endif