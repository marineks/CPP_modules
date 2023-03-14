#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <ostream>

class PmergeMe
{
	private:
		std::vector<int> _number_list;
	public:
		/* Forme canonique de Coplien */
		PmergeMe();
		PmergeMe(const PmergeMe&);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe&);
		
		/* Constructeur paramétrique */
		PmergeMe(char **input);

		/* Méthodes */
		bool			isSorted(std::vector<int> array);
		void			insertionSortVector(std::vector<int>& array);
		void			mergeSortVector(std::vector<int>& array);
		void			mergeHalves(std::vector<int>& array, std::vector<int>& left_half, std::vector<int>& right_half);

		/* Accesseurs */
		void				setNumberList(char **input);
		std::vector<int>	getNumberList(void) const;
};

std::ostream & operator<<(std::ostream & os, std::vector<int> list);

#endif