/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:41:01 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/31 13:14:45 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
FragTrap::FragTrap(void) : ClapTrap::ClapTrap()
{
	std::cout << "🐬 [FRAGTRAP] Default Constructor called" << std::endl;
	this->_name = "";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap::ClapTrap(src)
{
	std::cout << "😻 [FRAGTRAP] Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "🌝 [FRAGTRAP] Destructor " << this->_name << " called" << std::endl;
	return ;
}

FragTrap &		FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << "💅 [FRAGTRAP] Copy assignment operator called (" << rhs.getName() << " copied)." << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}


/* ------------- PARAMETRIC CONSTRUCTORS  --------------*/

FragTrap::FragTrap(std::string str) : ClapTrap::ClapTrap(str)
{
	this->_name = str;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "🍓 [FRAGTRAP] Parametric constructor " << this->_name << " called" << std::endl;
	return ;
}

/*****
****** OTHER MEMBER FUNCTIONS
******
*********************************************************/

// void		FragTrap::attack(const std::string & target)
// {
// 	std::cout << std::endl;
		
// 	if (this->_hitPoints <= 0)
// 		std::cout << "🪶 Kind of hard to do when FragTrap" << YELLOW << this->_name << RESET << " is dead..." << std::endl;
// 	else if (this->_energyPoints <= 0)
// 		std::cout << "🔋 No energy left for FragTrap " << PURPLE << this->_name << RESET << std::endl;
// 	else
// 	{
// 		if (this->_name.empty() == false)
// 			std::cout << "FragTrap " << BLUE << this->_name << RESET;
// 		else
// 			std::cout << RED << "Unnamed FragTrap" << RESET;
// 		std::cout << " attacks ";
// 		if (target.empty())
// 			std::cout << RED << "Unnamed FragTrap" << RESET;
// 		else
// 			std::cout << target;
// 		std::cout << " causing " << this->_attackDamage;
// 		std::cout << " points of damage !" << std::endl;
// 		this->_energyPoints--;
// 	}
	
// 	return ;
// }

void		FragTrap::highFivesGuys(void)
{
	std::cout << std::endl;
	
	if (this->_hitPoints <= 0)
		std::cout << "🪶  Kind of hard to do when FragTrap " << YELLOW << this->_name << RESET << " is dead..." << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "🔋 No energy left for FragTrap " << PURPLE << this->_name << RESET << std::endl;
	else
	{
		std::cout << "'HEYYYY my dudes GIMME A HIGH FIVE yeahhhh 🤙🤙🤙', said " ;
		std::cout << "FragTrap " << PURPLE << this->_name << RESET << std::endl;
		
	}
}