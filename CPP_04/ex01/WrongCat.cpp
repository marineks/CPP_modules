/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:31:24 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 11:31:26 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
WrongCat::WrongCat(void) : _type("WrongCat")
{
	std::cout << "🐹 [WrongCat] Default Constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const & src)
{
	std::cout << "🐹 [WrongCat] Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

WrongCat::~WrongCat()
{
	std::cout << "🐁 [WrongCat] Destructor " << this->_type << " called" << std::endl;
	return ;
}

WrongCat &		WrongCat::operator=(WrongCat const & rhs)
{
	std::cout << "🐹 [WrongCat] Copy assignment operator called" << std::endl;
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

std::string	WrongCat::getType(void) const
{
	return this->_type;
}

void		WrongCat::setType(std::string str)
{
	this->_type = str;
	return ;
}

/*****
****** OTHER MEMBER FUNCTIONS
******
*********************************************************/

void	WrongCat::makeSound(void) const
{
	std::cout << "* wrong meows *" << std::endl;
	return ;
}