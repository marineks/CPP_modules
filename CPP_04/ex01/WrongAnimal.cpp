/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:32:48 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 11:51:46 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "🦖 [WrongAnimal] Default Constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout << "🦖 [WrongAnimal] Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "🦕 [WrongAnimal] Destructor " << this->_type << " called" << std::endl;
	return ;
}

WrongAnimal &		WrongAnimal::operator=(WrongAnimal const & rhs)
{
	std::cout << "🦖 [WrongAnimal] Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return *this;
}

/*****
****** ACCESSORS
******
*********************************************************/

std::string	WrongAnimal::getType(void) const
{
	return this->_type;
}

void		WrongAnimal::setType(std::string str)
{
	this->_type = str;
	return ;
}

/*****
****** OTHER MEMBER FUNCTIONS
******
*********************************************************/

void	WrongAnimal::makeSound(void) const
{
	std::cout << "* wrong generic WrongAnimal noises *" << std::endl;
	return ;
}