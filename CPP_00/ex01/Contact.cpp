/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:47:27 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/19 18:02:11 by msanjuan         ###   ########.fr       */
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
	// if (str == NULL)
	// 	std::cout << "Please type your firstname." << std::endl;
	// else
		this->_firstName = str;
	return ;
}

void	Contact::setLastName(std::string str)
{
	// if (str == NULL)
	// 	std::cout << "Please type your lastname." << std::endl;
	// else
		this->_lastName = str;
	return ;
}

void	Contact::setNickname(std::string str)
{
	// if (str == NULL)
	// 	std::cout << "Please type your nickname." << std::endl;
	// else
		this->_nickname = str;
	return ;
}

void	Contact::setPhoneNumber(int number)
{
	if (number > 0)
		this->_phoneNumber = number;
	else
		std::cout << "Invalid phone number. Try again!" << std::endl;
	return ;
}

void	Contact::setDarkestSecret(std::string str)
{
	// if (str == NULL || *str == '\n')
	// 	std::cout << "Don't be shy! It's a safe place here." << std::endl;
	// else
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