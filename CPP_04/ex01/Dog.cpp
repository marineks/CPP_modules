/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:29:15 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 18:44:50 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
Dog::Dog(void) : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "🐶 [Dog] Default Constructor called" << std::endl;
	return ;
}

Dog::Dog(Dog const & src) : Animal(src)
{
	std::cout << "🐕‍🦺 [Dog] Copy Constructor called" << std::endl;
	this->_type = src.getType();
	this->_brain = new Brain(*src._brain);
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

	if (this != &rhs)
	{
		this->_type = rhs.getType();
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return *this;
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