#include "RPN.hpp"

/* FORME COPLIENNE */

// constructeur par defaut
RPN::RPN() {};

// constructeur par copie
RPN::RPN(const RPN & src){
	*this = src;
	return ;
}

// destructeur
RPN::~RPN() {};

// affectation
RPN & RPN::operator=(RPN const & rhs)
{
	if (this != &rhs)
	{
		this->_postfix_expr = rhs._postfix_expr;
	}
	return *this;
};

/* Autre */

RPN::RPN(char const  *input)
{
	// on convertit input en string

	// on push dans la stack 

	// renvoyer erreur si char pas correct (parenthese, operateur pas implemente, > à 10)
};

int	RPN::resolveEquation()
{
	// on resout

	// on print le resultat
};


std::stack<char>	RPN::getPostfixExpr(void) { return (this->_postfix_expr); };