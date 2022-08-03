/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:29:15 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 15:45:05 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
Dog::Dog(void) : _type("Dog")
{
	this->_brain = new Brain();
	std::cout << "🐶 [Dog] Default Constructor called" << std::endl;
	return ;
}

Dog::Dog(Dog const & src)
{
	std::cout << "🐕‍🦺 [Dog] Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "🦮 [Dog] Destructor " << this->_type << " called" << std::endl;
	return ;
}

Dog &		Dog::operator=(Dog const & rhs)
{
	std::cout << "🦴 [Dog] Copy assignment operator called" << std::endl;
	
	Dog *copy = new Dog();
	if (this != &rhs)
	{
		copy->_type = rhs.getType();
		copy->_brain = new Brain(*rhs._brain);
	}
	return *copy;
}

/*****
****** ACCESSORS
******
*********************************************************/

std::string	Dog::getType(void) const
{
	return this->_type;
}

void		Dog::setType(std::string str)
{
	this->_type = str;
	return ;
}

/*****
****** OTHER MEMBER FUNCTIONS
******
*********************************************************/

void	Dog::makeSound(void) const
{
	std::cout << "* inoffensive barking *" << std::endl;
	return ;
}