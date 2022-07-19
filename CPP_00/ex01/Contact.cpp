/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:47:27 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/19 21:07:58 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

/*****
****** CONSTRUCTOR + DESTRUCTOR MEMBER FUNCTIONS
******
*********************************************************/
Contact::Contact (void)
{
	std::cout << "🔧 Contact Constructor called" << std::endl;
	Contact::_contactNb += 1;
	return ;
}

Contact::~Contact (void)
{
	std::cout << "💥 Contact Destructor called" << std::endl;
	Contact::_contactNb -= 1;
	return ;
}

/*****
****** INITIALIZING PRIVATES ATTRIBUTES
******
*********************************************************/
void	Contact::setFirstName(std::string str)
{
	this->_firstName = str;
	return ;
}

void	Contact::setLastName(std::string str)
{
	this->_lastName = str;
	return ;
}

void	Contact::setNickname(std::string str)
{
	this->_nickname = str;
	return ;
}

int		Contact::setPhoneNumber(int number)
{
	if (number <= 0)
		return (-1);
	else
	{
		this->_phoneNumber = number;
		return (0);
	}
}

void	Contact::setDarkestSecret(std::string str)
{
	this->_darkestSecret = str;
	return ;
}

/*****
****** ACCESSING PRIVATES ATTRIBUTES
******
*********************************************************/
std::string	Contact::getFirstName(void) const {
	return (this->_firstName);
}

std::string	Contact::getLastName(void) const {
	return (this->_lastName);
}

std::string	Contact::getNickname(void) const {
	return (this->_nickname);
}

int	Contact::getPhoneNumber(void) const {
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const {
	return (this->_darkestSecret);
}


/*****
****** COUNTING NUMBER OF INSTANCES OF CLASS CONTACT
******
*********************************************************/
int	Contact::getContactNb(void)
{
	return (Contact::_contactNb);
}

int Contact::_contactNb = 0;