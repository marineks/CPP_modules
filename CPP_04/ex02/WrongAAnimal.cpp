/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:32:48 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 11:51:46 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAAnimal.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
WrongAAnimal::WrongAAnimal(void) : _type("WrongAAnimal")
{
	std::cout << "🦖 [WrongAAnimal] Default Constructor called" << std::endl;
	return ;
}

WrongAAnimal::WrongAAnimal(WrongAAnimal const & src)
{
	std::cout << "🦖 [WrongAAnimal] Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

WrongAAnimal::~WrongAAnimal()
{
	std::cout << "🦕 [WrongAAnimal] Destructor " << this->_type << " called" << std::endl;
	return ;
}

WrongAAnimal &		WrongAAnimal::operator=(WrongAAnimal const & rhs)
{
	std::cout << "🦖 [WrongAAnimal] Copy assignment operator called" << std::endl;
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

std::string	WrongAAnimal::getType(void) const
{
	return this->_type;
}

void		WrongAAnimal::setType(std::string str)
{
	this->_type = str;
	return ;
}

/*****
****** OTHER MEMBER FUNCTIONS
******
*********************************************************/

void	WrongAAnimal::makeSound(void) const
{
	std::cout << "* wrong generic WrongAAnimal noises *" << std::endl;
	return ;
}