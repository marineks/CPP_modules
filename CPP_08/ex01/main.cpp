/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:23:26 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/13 10:04:36 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <algorithm>
#define __STDC_LIMIT_MACROS
#include <stdint.h>

int main(void)
{
	std::cout << CYAN << "################# DEPUIS LE SUJET ################# " << RESET << std::endl;
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << CYAN << "################# TESTS COMPLEMENTAIRES ################# " << RESET << std::endl;
	
	// Trigger the FullSpanException
	try
	{
		Span error = Span(3);
		error.addNumber(255425);
		error.addNumber(1);
		error.addNumber(354);
		error.addNumber(4); // should trigger the exception
	}
	catch(const std::exception& e)
	{ std::cerr << RED << e.what() << RESET << '\n'; }
	
	// Trigger the ImpossibleDistanceException
	try
	{
		Span error = Span(3);
		
		// std::cout << error.shortestSpan() << std::endl; // decomment to trigger
		error.addNumber(1); // at this point, only one elt in the stack
		std::cout << error.longestSpan() << std::endl; // decomment to trigger
	}
	catch(const std::exception& e)
	{ std::cerr << RED << e.what() << RESET << '\n'; }

	// Tests on SHORTEST SPAN
	Span sameVal(4);

	sameVal.addNumber(2);
	sameVal.addNumber(-2);
	sameVal.addNumber(2);
	sameVal.addNumber(42);
	
	std::cout << sameVal.shortestSpan() << std::endl; // should be 0

	Span sameVal2(4);

	sameVal2.addNumber(-2);
	sameVal2.addNumber(-3);
	sameVal2.addNumber(-24);
	sameVal2.addNumber(-42);
	
	std::cout << sameVal2.shortestSpan() << std::endl; // should be 1
	
	// Tests on LONGEST SPAN
	Span limits(4);

	limits.addNumber(INT32_MAX);
	limits.addNumber(INT32_MIN);
	
	std::cout << limits.shortestSpan() << std::endl; // should be 4294967295
	std::cout << limits.longestSpan() << std::endl; // should be 4294967295

	Span signs(2);

	signs.addNumber(-2);
	signs.addNumber(2);

	std::cout << signs.shortestSpan() << std::endl; // should be 4
	std::cout << signs.longestSpan() << std::endl; // should be 4

	// Tests on a big Span
	int	size = 42000;
	Span big(size);
	std::vector<int> add;

	for (int i = 0; i < 10; i++)
		add.push_back(i);
	
	try 
	{	
		big.addRange(add.begin(), add.end());
	}
	catch(const std::exception& e)
	{ std::cerr << e.what() << '\n'; }
	
	std::cout << big.shortestSpan() << std::endl; // should be 1
	std::cout << big.longestSpan() << std::endl; // should be size - 1
	
	return (0);
}
