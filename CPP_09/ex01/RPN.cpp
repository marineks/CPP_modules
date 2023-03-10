#include "RPN.hpp"

/* FORME COPLIENNE */

// constructeur par defaut
RPN::RPN(){};

// constructeur par copie
RPN::RPN(const RPN &src)
{
	*this = src;
	return;
}

// destructeur
RPN::~RPN(){};

// affectation
RPN &RPN::operator=(RPN const &rhs)
{
	if (this != &rhs)
	{
		this->_postfix_expr = rhs._postfix_expr;
	}
	return *this;
};

/* Autre */

RPN::RPN(char const *input)
{
	std::string tokens_handled = "+-/*";
	// on convertit input en string pour plus facilement le manip
	std::string expr(input);

	if (expr.empty() == true)
	{
			std::cout << "Error" << std::endl;
			return ;
	}

	// on push char par char dans la stack en faisant des checks
	for (size_t i = 0; i < expr.size(); i++)
	{
		if (expr[i] == ' ') // on passe les espaces
			continue;
		if (isdigit(expr[i])) // on store les nombres ensemble
		{
			this->_postfix_expr.push(int(expr[i]) - 48);
		}
		else if (tokens_handled.find(expr[i]) != std::string::npos) // et les operateurs ensemble
		{
			this->_operators += expr[i];
		}
		else // renvoyer erreur si pb de format
		{
			std::cout << "Error" << std::endl;
			return ;
		}
	}
	// std::cout << "Numbers : " << _postfix_expr << std::endl;
	// std::cout << "Operators : " << _operators[0] << " " << _operators[1] << std::endl;
	resolveEquation();
};

void RPN::resolveEquation()
{
	for (size_t i = 0; i < this->getOperators().size(); i++)
	{
		int a = _postfix_expr.top();
		_postfix_expr.pop();
		int b = _postfix_expr.top();
		_postfix_expr.pop();

		switch (this->getOperators()[i])
			{
			case '+':
				_postfix_expr.push(a + b);
				break;
			case '-':
				_postfix_expr.push(a - b);
				break;
			case '*':
				_postfix_expr.push(a * b);
				break;
			case '/':
				_postfix_expr.push(a / b);
				break;
			}
	}
	
	// on print le resultat (normalement la size de la stack est de 1, c'est le résultat)
	std::cout << "Result is : " << _postfix_expr.top() << std::endl;
};

std::stack<int> RPN::getPostfixExpr(void) const { return (this->_postfix_expr); };

std::string RPN::getOperators(void) const { return (this->_operators); };

std::ostream & operator<<(std::ostream & os, std::stack<int> stack)
{
    while(!stack.empty()) 
    {
        os << stack.top() << " ";
        stack.pop();
    }
	// os << std::endl;
    return os;
}