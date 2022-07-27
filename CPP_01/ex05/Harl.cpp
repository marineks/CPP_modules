/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:45:25 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/27 17:25:02 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

#include <string>
#include <iostream>
#include "Harl.hpp"

/*****
****** CONSTRUCTOR + DESTRUCTOR MEMBER FUNCTIONS
******
*********************************************************/
Harl::Harl (void)
{
	std::cout << "🪆  Harl Constructor called" << std::endl;
	return ;
}

Harl::~Harl (void)
{
	std::cout << "🧸 Harl Destructor called" << std::endl;
	return ;
}

/*****
****** COMPLAIN PUBLIC MEMBER FUNCTION
******
*********************************************************/
void	Harl::complain(std::string level)
{
	void (Harl::*tab[4])(void) = {
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};	
	
	std::string levels[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"	
	};
	
	for (int i = 0; i < 4; i++)
		if (level == levels[i]) (this->*tab[i])();

	return ;
}

/*****
****** ACCESSING PRIVATE FUNCTIONS MEMBER
******
*********************************************************/
void	Harl::_debug(void) {
	std::cout << GREEN << "<DEBUG> I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RESET << std::endl;
	return ;
}

void	Harl::_info(void) {
	std::cout << CYAN << "<INFO> I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
	return ;
}

void	Harl::_warning(void) {
	std::cout << BLUE << "<WARNING> I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << RESET << std::endl;
	return ;
}

void	Harl::_error(void) {
	std::cout << RED << "<ERROR> This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}