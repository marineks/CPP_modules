/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:25:18 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/30 21:38:38 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"


/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
ScavTrap::ScavTrap(void) : _name(""), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "🦾 Default Constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	std::cout << "🧠 Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "💥 Destructor " << this->_name << " called" << std::endl;
	return ;
}

ScavTrap &		ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << "🦴 Copy assignment operator called" << std::endl;
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

ScavTrap::ScavTrap(std::string str) : _name(str), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "👑 Parametric constructor " << this->_name << " called" << std::endl;
	return ;
}


/*****
****** OTHER MEMBER FUNCTIONS
******
*********************************************************/

void		ScavTrap::attack(const std::string & target)
{
	std::cout << std::endl;
		
	if (this->_hitPoints == 0)
		std::cout << "🪶 Kind of hard to do when ScavTrap" << YELLOW << this->_name << RESET << " is dead..." << std::endl;
	else if (this->_energyPoints == 0)
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

void		ScavTrap::ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << std::endl;
	
	if (this->_hitPoints == 0)
		std::cout << "🪶 ScavTrap" << YELLOW << this->_name << RESET << " is already dead..." << std::endl;
	else
	{
		if (this->_name.empty() == false)
			std::cout << "ScavTrap " << BLUE << this->_name << RESET;
		else
			std::cout << RED << "Unnamed ScavTrap" << RESET;
		std::cout << " took " << amount;
		std::cout << " points of damage !" << std::endl;
		this->_hitPoints -= amount;
	}
	return ;
}

void		ScavTrap::ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << std::endl;
	
	if (this->_hitPoints == 0)
		std::cout << "🪶  Kind of hard to do when ScavTrap " << YELLOW << this->_name << RESET << " is dead..." << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "🔋 No energy left for ScavTrap " << PURPLE << this->_name << RESET << std::endl;
	else
	{
		if (this->_name.empty() == false)
			std::cout << "ScavTrap " << BLUE << this->_name << RESET;
		else
			std::cout << RED << "Unnamed ScavTrap" << RESET;
		std::cout << " is under repair and wins back " << amount;
		std::cout << " hit points !" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	return ;
}