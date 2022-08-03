/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:39:30 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 11:54:00 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << "🐞 [AAnimal] Default Constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const & src)
{
	std::cout << "🐸 [AAnimal] Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

AAnimal::~AAnimal()
{
	std::cout << "🦆 [AAnimal] Destructor " << this->_type << " called" << std::endl;
	return ;
}

AAnimal &		AAnimal::operator=(AAnimal const & rhs)
{
	std::cout << "🐥 [AAnimal] Copy assignment operator called" << std::endl;
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

std::string	AAnimal::getType(void) const
{
	return this->_type;
}

void		AAnimal::setType(std::string str)
{
	this->_type = str;
	return ;
}
