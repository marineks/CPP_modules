/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:37:04 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 10:50:01 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
Cat::Cat(void) : _type("Cat")
{
	std::cout << "🐱 [Cat] Default Constructor called" << std::endl;
	return ;
}

Cat::Cat(Cat const & src)
{
	std::cout << "🐅 [Cat] Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

Cat::~Cat()
{
	std::cout << "🐆 [Cat] Destructor " << this->_type << " called" << std::endl;
	return ;
}

Cat &		Cat::operator=(Cat const & rhs)
{
	std::cout << "🐈 [Cat] Copy assignment operator called" << std::endl;
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

std::string	Cat::getType(void) const
{
	return this->_type;
}

void		Cat::setType(std::string str)
{
	this->_type = str;
	return ;
}

/*****
****** OTHER MEMBER FUNCTIONS
******
*********************************************************/

void	Cat::makeSound(void) const
{
	std::cout << "* cute meows *" << std::endl;
	return ;
}