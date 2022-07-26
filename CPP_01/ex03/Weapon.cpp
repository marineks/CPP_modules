/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:20:14 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/26 16:41:33 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Weapon.hpp"

/*****
****** CONSTRUCTOR + DESTRUCTOR MEMBER FUNCTIONS
******
*********************************************************/
Weapon::Weapon (void)
{
	std::cout << "🔫 Weapon Constructor called" << std::endl;
	return ;
}

Weapon::Weapon (std::string type)
{
	std::cout << "🔫 Weapon Constructor called" << std::endl;
	this->setType(type);
	return ;
}

Weapon::~Weapon (void)
{
	std::cout << "🚨 Weapon Destructor called" << std::endl;
	return ;
}

/*****
****** INITIALIZING PRIVATES ATTRIBUTES
******
*********************************************************/
void	Weapon::setType(std::string str)
{
	this->_type = str;
	return ;
}

/*****
****** ACCESSING PRIVATES ATTRIBUTES
******
*********************************************************/
const std::string & Weapon::getType(void) const {

	return (this->_type);
}
