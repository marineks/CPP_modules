#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private:
		std::stack<char> _postfix_expr;
	public:
		/* Forme canonique de Coplien */
		RPN();
		RPN(const RPN&);
		~RPN();
		RPN &operator=(const RPN&);
		
		/* Constructeur paramétrique */
		RPN(char const *input);

		/* Méthodes */
		int	resolveEquation();

			/* Accesseurs */
		std::stack<char>	getPostfixExpr(void);
};




#endif