/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:18:52 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/31 12:53:30 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
ClapTrap::ClapTrap(void) : _name(""), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "🦾 Default Constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "🧠 Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "💥 Destructor " << this->_name << " called" << std::endl;
	return ;
}

ClapTrap &		ClapTrap::operator=(ClapTrap const & rhs)
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

ClapTrap::ClapTrap(std::string str) : _name(str), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "👑 Parametric constructor " << this->_name << " called" << std::endl;
	return ;
}

/*****
****** ACCESSORS
******
*********************************************************/

std::string	ClapTrap::getName(void) const
{
	return this->_name;
}

int			ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

int			ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

int			ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}

void		ClapTrap::setName(std::string str)
{
	this->_name = str;
	return ;
}

void		ClapTrap::setHitPoints(int hp)
{
	this->_hitPoints = hp;
	return ;
}

void		ClapTrap::setEnergyPoints(int mana)
{
	this->_energyPoints = mana;
	return ;
}

void		ClapTrap::setAttackDamage(int dmg)
{
	this->_attackDamage = dmg;
	return ;
}

/*****
****** OTHER MEMBER FUNCTIONS
******
*********************************************************/

void		ClapTrap::attack(const std::string & target)
{
	std::cout << std::endl;
		
	if (this->_hitPoints <= 0)
		std::cout << "🪶 Kind of hard to do when ClapTrap" << YELLOW << this->_name << RESET << " is dead..." << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "🔋 No energy left for ClapTrap " << PURPLE << this->_name << RESET << std::endl;
	else
	{
		if (this->_name.empty() == false)
			std::cout << "ClapTrap " << BLUE << this->_name << RESET;
		else
			std::cout << RED << "Unnamed ClapTrap" << RESET;
		std::cout << " attacks ";
		if (target.empty())
			std::cout << RED << "Unnamed ClapTrap" << RESET;
		else
			std::cout << target;
		std::cout << " causing " << this->_attackDamage;
		std::cout << " points of damage !" << std::endl;
		this->_energyPoints--;
	}
	
	return ;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << std::endl;
	
	if (this->_hitPoints <= 0)
		std::cout << "🪶 ClapTrap" << YELLOW << this->_name << RESET << " is already dead..." << std::endl;
	else
	{
		if (this->_name.empty() == false)
			std::cout << "ClapTrap " << BLUE << this->_name << RESET;
		else
			std::cout << RED << "Unnamed ClapTrap" << RESET;
		std::cout << " took " << amount;
		std::cout << " points of damage !" << std::endl;
		this->_hitPoints -= amount;
	}
	return ;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << std::endl;
	
	if (this->_hitPoints <= 0)
		std::cout << "🪶  Kind of hard to do when ClapTrap " << YELLOW << this->_name << RESET << " is dead..." << std::endl;
	else if (this->_energyPoints <= 0)
		std::cout << "🔋 No energy left for ClapTrap " << PURPLE << this->_name << RESET << std::endl;
	else
	{
		if (this->_name.empty() == false)
			std::cout << "ClapTrap " << BLUE << this->_name << RESET;
		else
			std::cout << RED << "Unnamed ClapTrap" << RESET;
		std::cout << " is under repair and wins back " << amount;
		std::cout << " hit points !" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	return ;
}