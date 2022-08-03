/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:29:15 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 19:12:38 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
Dog::Dog(void) : AAnimal()
{
	this->_brain = new Brain();
	this->_type = "Dog";
	std::cout << "🐶 [Dog] Default Constructor called" << std::endl;
	return ;
}

Dog::Dog(Dog const & src) : AAnimal(src)
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
	
	Dog *copy = new Dog();
	if (this != &rhs)
	{
		copy->_type = rhs.getType();
		copy->_brain = new Brain(*rhs._brain);
	}
	return *copy;
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