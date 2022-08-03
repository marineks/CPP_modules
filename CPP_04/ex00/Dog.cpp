/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:29:15 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 18:32:10 by msanjuan         ###   ########.fr       */
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
	std::cout << "🐶 [Dog] Default Constructor called" << std::endl;
	return ;
}

Dog::Dog(Dog const & src) : Animal(src)
{
	std::cout << "🐕‍🦺 [Dog] Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

Dog::~Dog()
{
	std::cout << "🦮 [Dog] Destructor " << this->_type << " called" << std::endl;
	return ;
}

Dog &		Dog::operator=(Dog const & rhs)
{
	std::cout << "🦴 [Dog] Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
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