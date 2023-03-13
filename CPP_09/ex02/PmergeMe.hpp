#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <ostream>

class PmergeMe
{
	private:
		PmergeMe();
		std::vector<int> _number_list;
	public:
		/* Forme canonique de Coplien */
		PmergeMe(const PmergeMe&);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe&);
		
		/* Constructeur paramétrique */
		PmergeMe(char **input);

		/* Méthodes */
		// void			resolveEquation();

			/* Accesseurs */
		// std::deque<int>	getPostfixExpr(void) const;
		// std::string		getOperators() const;

		
};

std::ostream & operator<<(std::ostream & os, std::vector<int> list);

#endif