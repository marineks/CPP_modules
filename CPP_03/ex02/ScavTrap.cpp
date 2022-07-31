/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:25:18 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/31 12:54:20 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
ScavTrap::ScavTrap(void) : ClapTrap::ClapTrap()
{
	std::cout << "🦿 [SCAVTRAP] Default Constructor called" << std::endl;
	this->_name = "";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap::ClapTrap(src)
{
	std::cout << "🫀  [SCAVTRAP] Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "🦚 [SCAVTRAP] Destructor " << this->_name << " called" << std::endl;
	return ;
}

ScavTrap &		ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << "🍒 [SCAVTRAP] Copy assignment operator called (" << rhs.getName() << " copied)." << std::endl;
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

ScavTrap::ScavTrap(std::string str) : ClapTrap::ClapTrap(str)
{
	this->_name = str;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "🦕 [SCAVTRAP] Parametric constructor " << this->_name << " called" << std::endl;
	return ;
}

/*****
****** OTHER MEMBER FUNCTIONS
******
*********************************************************/

void		ScavTrap::attack(const std::string & target)
{
	std::cout << std::endl;
		
	if (this->_hitPoints <= 0)
		std::cout << "🪶 Kind of hard to do when ScavTrap" << YELLOW << this->_name << RESET << " is dead..." << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "🔋 No energy left for ScavTrap " << PURPLE << this->_name << RESET << std::endl;
	else
	{
		if (this->_name.empty() == false)
			std::cout << "ScavTrap " << BLUE << this->_name << RESET;
		else
			std::cout << RED << "Unnamed ScavTrap" << RESET;
		std::cout << " attacks ";
		if (target.empty())
			std::cout << RED << "Unnamed ScavTrap" << RESET;
		else
			std::cout << target;
		std::cout << " causing " << this->_attackDamage;
		std::cout << " points of damage !" << std::endl;
		this->_energyPoints--;
	}
	
	return ;
}

void		ScavTrap::guardGate(void)
{
	std::cout << std::endl;
	
	if (this->_hitPoints <= 0)
		std::cout << "🪶 Kind of hard to do when ScavTrap" << YELLOW << this->_name << RESET << " is dead..." << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "🔋 No energy left for ScavTrap " << PURPLE << this->_name << RESET << std::endl;
	else
	{
		std::cout << "ScavTrap " << PURPLE << this->_name << RESET;
		std::cout << " entered Gate keeper mode." << std::endl;
	}
}