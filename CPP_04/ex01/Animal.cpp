/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:39:30 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 11:54:00 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
Animal::Animal(void) : _type("Animal")
{
	std::cout << "🐞 [Animal] Default Constructor called" << std::endl;
	return ;
}

Animal::Animal(Animal const & src)
{
	std::cout << "🐸 [Animal] Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

Animal::~Animal()
{
	std::cout << "🦆 [Animal] Destructor " << this->_type << " called" << std::endl;
	return ;
}

Animal &		Animal::operator=(Animal const & rhs)
{
	std::cout << "🐥 [Animal] Copy assignment operator called" << std::endl;
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

std::string	Animal::getType(void) const
{
	return this->_type;
}

void		Animal::setType(std::string str)
{
	this->_type = str;
	return ;
}

/*****
****** OTHER MEMBER FUNCTIONS
******
*********************************************************/

void	Animal::makeSound(void) const
{
	std::cout << "* generic animal noises *" << std::endl;
	return ;
}