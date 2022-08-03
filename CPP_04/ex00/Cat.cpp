/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:37:04 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 18:32:12 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
Cat::Cat(void) : Animal()
{
	this->_type = "Cat";
	std::cout << "🐱 [Cat] Default Constructor called" << std::endl;
	return ;
}

Cat::Cat(Cat const & src): Animal(src)
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
****** OTHER MEMBER FUNCTIONS
******
*********************************************************/

void	Cat::makeSound(void) const
{
	std::cout << "* cute meows *" << std::endl;
	return ;
}