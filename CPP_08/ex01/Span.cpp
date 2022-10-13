/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:23:24 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/13 10:07:54 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

Span::Span(void) : _N(0) {}

Span::Span(Span const &src) {
	*this = src;
}

Span::~Span(void) {}


Span	&Span::operator=(Span const &rhs)
{
	_N = rhs._N;
	_stack.clear();
	_stack = rhs. _stack;
	return (*this);
}

/*****
****** PARAMETRIC CONSTRUCTOR
******
*********************************************************/
Span::Span(unsigned int n) : _N(n) {}

/*****
****** OTHER MEMBER FUNCTIONS
******
*********************************************************/
void	Span::addNumber(long int number)
{
	if (_stack.size() == _N)
		throw FullSpanException();
	_stack.push_back(number);
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_stack.size() + std::distance(begin, end) > _N)
		throw FullSpanException();
	
	_stack.insert(_stack.begin(), begin, end);
}

unsigned int		Span::shortestSpan(void) {
	
	if (_stack.empty() == true || _stack.size() == 1)
		throw ImpossibleDistanceException();

	// sort
	std::vector<int>::iterator	first = _stack.begin();
	std::vector<int>::iterator	last = _stack.end();
	std::sort(first, last);
	
	// compare the diff betweem each element, the lowest is stocked
	long int shortestSpan = longestSpan();

	for (std::vector<int>::iterator it= first; it != (last - 1); ++it)
	{
		if ((*(it + 1) - *it) < shortestSpan)
			shortestSpan = *(it + 1) - *it;
	}
	return (shortestSpan);
}

unsigned int		Span::longestSpan(void) {
	
	if (_stack.empty() == true || _stack.size() == 1)
		throw ImpossibleDistanceException();
	
	std::vector<int>::iterator min = std::min_element(_stack.begin(), _stack.end());
	std::vector<int>::iterator max = std::max_element(_stack.begin(), _stack.end());

	return (*max - *min);
}

/*****
****** CUSTOMS EXCEPTIONS
******
*********************************************************/
const char * 	Span::FullSpanException::what (void) const throw() 
{
	return "Error : the Span is full; it is impossible to add another number";
}

const char * 	Span::ImpossibleDistanceException::what (void) const throw() 
{
	return "Error : it is impossible to add another number because the span is either empty or there is only one number";
}