#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <ostream>
#include <cstdlib> // atoi

class RPN
{
	private:
		std::stack<int> _postfix_expr;
		std::string		_operators;
	public:
		/* Forme canonique de Coplien */
		RPN();
		RPN(const RPN&);
		~RPN();
		RPN &operator=(const RPN&);
		
		/* Constructeur paramétrique */
		RPN(char const *input);

		/* Méthodes */
		void			resolveEquation();

			/* Accesseurs */
		std::stack<int>	getPostfixExpr(void) const;
		std::string		getOperators() const;

		
};

/* Overload supplémentaire */
std::ostream & operator<<(std::ostream & os, std::stack<int> stack);

#endif