/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 21:55:28 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/26 22:04:19 by msanjuan         ###   ########.fr       */
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
// FIXME: Protect the level (command that begins w the same letter will trigger the function call)
// BUG: switch cases only accept consts values
void	Harl::complain(std::string level)
{
	switch (level[0])
	{
		case 'D':
			this->_debug();
		case 'I':
			this->_info();
		case 'W':
			this->_warning();
		case 'E':
			this->_error();
			break;
		default :
			std::cout << "[Probably complaining about insignificant problems]" << std::endl;
	}
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