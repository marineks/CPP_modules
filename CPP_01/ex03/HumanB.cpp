/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:29:32 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/26 16:49:59 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>
#include "HumanB.hpp"

/*****
****** CONSTRUCTOR + DESTRUCTOR MEMBER FUNCTIONS
******
*********************************************************/
HumanB::HumanB (std::string str) : _name(str)
{
	std::cout << "🪆  HumanB Constructor called" << std::endl;
	return ;
}

HumanB::~HumanB (void)
{
	std::cout << "🧸 HumanB Destructor called" << std::endl;
	return ;
}

/*****
****** INITIALIZING PRIVATES ATTRIBUTES
******
*********************************************************/
void	HumanB::setName(std::string str)
{
	this->_name = str;
	return ;
}

/*****
****** ACCESSING PRIVATES ATTRIBUTES
******
*********************************************************/
std::string	HumanB::getName(void) const {
	return (this->_name);
}

/*****
****** ATTACK MEMBER FUNCTION
******
*********************************************************/
void	HumanB::attack(void)
{
	std::cout << GREEN << this->getName();
	if (this->_weapon->getType() == "")
		std::cout << BLUE << " attacks unarmed." << RESET << std::endl;
	else
	{
		std::cout << BLUE << " attacks with their ";
		std::cout << PURPLE << this->_weapon->getType() << RESET << std::endl;
	}
	return ;
}

/*****
****** SET WEAPON MEMBER FUNCTION
******
*********************************************************/
void	HumanB::setWeapon(Weapon newWeapon)
{
	this->_weapon->setType(newWeapon.getType());
	return ;
}