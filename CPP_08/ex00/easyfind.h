/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:40:20 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/12 12:01:38 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

#include <string>
#include <iostream>
#include <algorithm> 

class NoOccurrenceFoundException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("There isn't any occurrence of this number in the int container.");
		};
};

/* Doit renvoyer la première occurrence du 2nd paramètre dans le 1er. */
template<typename T>
void easyfind(T const &intContainer, int const nbToFind)
{
	try
	{
		typename T::const_iterator	firstPos = intContainer.begin();
		typename T::const_iterator	lastPos = intContainer.end();
		typename T::const_iterator	occurrenceFound = std::find(firstPos, lastPos, nbToFind);
		
		if (occurrenceFound != lastPos)
			std::cout << GREEN << "The number " << *occurrenceFound << " was found at position " << occurrenceFound - firstPos << "!" << RESET << std::endl;
		else
			throw NoOccurrenceFoundException();
		
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

#endif