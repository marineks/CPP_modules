/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:08:34 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 16:19:12 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
Brain::Brain(void)
{
	std::cout << "🧠 [Brain] Default Constructor called" << std::endl;
	return ;
}

Brain::Brain(Brain const & src)
{
	std::cout << "🧠 [Brain] Copy Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	return ;
}

Brain::~Brain()
{
	std::cout << "🧠 [Brain] Destructor called" << std::endl;
	return ;
}

Brain &		Brain::operator=(Brain const & rhs)
{
	std::cout << "🧠 [Brain] Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}
