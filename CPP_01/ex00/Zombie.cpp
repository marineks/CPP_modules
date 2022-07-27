/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:24:13 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/27 17:20:49 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

/*****
****** CONSTRUCTOR + DESTRUCTOR MEMBER FUNCTIONS
******
*********************************************************/
Zombie::Zombie (void)
{
	std::cout << "🧟 Zombie Constructor called" << std::endl;
	return ;
}

Zombie::~Zombie (void)
{
	std::cout << "💥 Zombie Destructor " << this->getName() << " called" << std::endl;
	return ;
}

/*****
****** INITIALIZING PRIVATES ATTRIBUTES
******
*********************************************************/
void	Zombie::setName(std::string str)
{
	this->_name = str;
	return ;
}

/*****
****** ACCESSING PRIVATES ATTRIBUTES
******
*********************************************************/
std::string	Zombie::getName(void) const {
	return (this->_name);
}

/*****
****** ANNOUNCE MEMBER FUNCTION
******
*********************************************************/
void	Zombie::announce(void) {

	if (Zombie::getName() == "")
		std::cout << RED << "Your zombie must be named to announce itself." << RESET << std::endl;
	else
	{
		std::cout << BLUE << Zombie::getName() << RESET;
		std::cout << GREEN << ": BraiiiiiiinnnzzzZ.." << RESET << std::endl;
	}
	return ;
}