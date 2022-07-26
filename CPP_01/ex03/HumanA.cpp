/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:28:34 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/26 16:26:19 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "HumanA.hpp"

/*****
****** CONSTRUCTOR + DESTRUCTOR MEMBER FUNCTIONS
******
*********************************************************/
// HumanA::HumanA (void) {
// 	std::cout << "📯 HumanA Constructor called" << std::endl;
// 	// this->_name = name;

// 	// Weapon &weaponREF = weapon;
// 	// this->setWeapon(weaponREF); 
// 	return ;
// }

HumanA::HumanA (std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	std::cout << "📯 HumanA Constructor called" << std::endl;
	// this->_name = name;

	// Weapon &weaponREF = weapon;
	// this->setWeapon(weaponREF); 
	return ;
}

HumanA::~HumanA (void)
{
	std::cout << "🛌 HumanA Destructor called" << std::endl;
	return ;
}

/*****
****** INITIALIZING PRIVATES ATTRIBUTES
******
*********************************************************/
void	HumanA::setName(std::string str)
{
	this->_name = str;
	return ;
}

/*****
****** ACCESSING PRIVATES ATTRIBUTES
******
*********************************************************/
std::string	HumanA::getName(void) const {
	return (this->_name);
}

/*****
****** ATTACK MEMBER FUNCTION
******
*********************************************************/
void	HumanA::attack(void)
{
	std::cout << GREEN << this->getName();
	std::cout << BLUE << " attacks with their ";
	std::cout << PURPLE << this->_weapon.getType() << RESET << std::endl;
	return ;
}


/*****
****** SET WEAPON MEMBER FUNCTION
******
*********************************************************/
// void	HumanA::setWeapon(Weapon & newWeapon)
// {
// 	this->_weapon = newWeapon;
// 	// this->_weapon.setType(newWeapon.getType());
// }