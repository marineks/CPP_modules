#include "RPN.hpp"

/* FORME COPLIENNE */

RPN::RPN(){};
RPN::~RPN(){};

RPN::RPN(const RPN &src)
{
	*this = src;
	return;
}

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
		std::cout << "Error (inverted expression missing)" << std::endl;
		return ;
	}

	// on push_back char par char dans la stack en faisant des checks
	for (size_t i = 0; i < expr.size(); i++)
	{
		if (expr[i] == ' ') // on passe les espaces
			continue;
		if (isdigit(expr[i])) // on store les nombres ensemble
		{
			this->_postfix_expr.push_back(int(expr[i]) - 48);
		}
		else if (tokens_handled.find(expr[i]) != std::string::npos) // et les operateurs ensemble
		{
			this->_operators += expr[i];
		}
		else // renvoyer erreur si pb de format
		{
			std::cout << "Error (not a correct inverted expression)" << std::endl;
			return ;
		}
	}
	std::cout << "Numbers : " << _postfix_expr << std::endl;
	std::cout << "Operators : ";
	for (size_t i = 0; i < _operators.size(); i++)
		std::cout << _operators[i];
	std::cout << std::endl;
	resolveEquation();
};

void RPN::resolveEquation()
{
	if (_postfix_expr.size() < 2)
	{
		std::cout << "Error (not a correct inverted expression)" << std::endl;
		return ;
	}

	if (_postfix_expr.size() - this->getOperators().size() != 1)
	{
		std::cout << "Error" << std::endl;
		return ;
	}

	for (size_t i = 0; i < this->getOperators().size(); i++)
	{
		int a = _postfix_expr.front();
		_postfix_expr.pop_front();
		int b = _postfix_expr.front();
		_postfix_expr.pop_front();

		switch (this->getOperators()[i])
			{
			case '+':
				std::cout << "a + b " << a << " " << b << std::endl;
				std::cout << a + b << std::endl;
				_postfix_expr.push_front(a + b);
				break;
			case '-':
				std::cout << "a - b " << a << " " << b << std::endl;
				std::cout << a - b << std::endl;
				_postfix_expr.push_front(a - b);
				break;
			case '*':
				std::cout << "a * b " << a << " " << b << std::endl;
				std::cout << a * b << std::endl;
				_postfix_expr.push_front(a * b);
				break;
			case '/':
				if (b == 0)
				{
					std::cout << "Error (division by zero)" << std::endl;
					return ;
				}
				std::cout << "a / b " << a << " " << b << std::endl;
				std::cout << a / b  << std::endl;
				_postfix_expr.push_front(a / b);
				// gérer la division par 0
				break;
			}
	}
	
	// on print le resultat (normalement la size de la stack est de 1, c'est le résultat)
	std::cout << "Result is : " << _postfix_expr.front() << std::endl;
};

std::deque<int> RPN::getPostfixExpr(void) const { return (this->_postfix_expr); };

std::string RPN::getOperators(void) const { return (this->_operators); };

std::ostream & operator<<(std::ostream & os, std::deque<int> stack)
{
    while(!stack.empty()) 
    {
        os << stack.front() << " ";
        stack.pop_front();
    }
    return os;
}