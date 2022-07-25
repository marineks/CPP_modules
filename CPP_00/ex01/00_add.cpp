/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_add.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:34:15 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/22 16:04:41 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include <cstddef>
#include "PhoneBook.hpp"

# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

void	askForFirstname(Contact *contact)
{
	std::string	firstname;

	std::cout << BLUE << "📜 Firstname?" << RESET << std::endl;
	std::getline(std::cin, firstname);
	std::getline(std::cin, firstname);
	if (std::cin.eof() == true)
			exit(0);

	while (firstname.empty())
	{
		std::cout << BLUE << "📜 Didn't hear anything. Firstname?" << RESET << std::endl;
		std::getline(std::cin, firstname);
		if (std::cin.eof() == true)
			exit(0);
	}
	contact->setFirstName(firstname);
	return ;
}

void	askForLastname(Contact *contact)
{
	std::string	lastname;

	std::cout << BLUE << "📜 Perfect. Lastname?" << RESET << std::endl;
	std::getline(std::cin, lastname);
	if (std::cin.eof() == true)
			exit(0);

	while (lastname.empty())
	{
		std::cout << BLUE << "📜 But surely you must have a lastname! Tell me." << RESET << std::endl;
		std::getline(std::cin, lastname);
		if (std::cin.eof() == true)
			exit(0);
	}
	contact->setLastName(lastname);
	return ;
}

void	askForNickname(Contact *contact)
{
	std::string	nickname;

	std::cout << BLUE << "📜 May I ask for your nickname?" << RESET << std::endl;
	std::getline(std::cin, nickname);
	if (std::cin.eof() == true)
			exit(0);

	while (nickname.empty())
	{
		std::cout << BLUE << "📜 Don't be shy! Please speak louder." << RESET << std::endl;
		std::getline(std::cin, nickname);
		if (std::cin.eof() == true)
			exit(0);
	}
	contact->setNickname(nickname);
	return ;
}

void	askForNumber(Contact *contact)
{
	long int			phonenumber = 0;

	std::cout << BLUE << "📜 Okay... No judgement there, pal! Your phone number?" << RESET << std::endl;
	std::cin >> phonenumber;
	
	if (std::cin.eof() == true)
			exit(0);
	
	while (phonenumber <= 0 || phonenumber > 9999999999)
	{
		if (std::cin.eof() == true)
			exit(0);
		if (std::cin.fail() == true || phonenumber > 9999999999)
		{
			std::cout << BLUE << "📜 Buddy, this is a phonebook... Now what is your phone number?" << RESET << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			std::cout << BLUE << "📜 Buddy, this is a phonebook... Now what is your phone number?" << RESET << std::endl;
		std::cin >> phonenumber;
	}
	contact->setPhoneNumber(phonenumber);
}

void	askForSecret(Contact *contact)
{
	std::string	secret;
	std::cout << BLUE << "📜 And last but not least... Your darkest secret, please!" << RESET << std::endl;
	std::getline(std::cin, secret);
	std::getline(std::cin, secret);
	if (std::cin.eof() == true)
			exit(0);
	
	while (secret.empty())
	{
		std::cout << BLUE << "📜 Please don't worry, this is a safe place here... for your secrets 🧙‍♂️" << RESET << std::endl;
		std::getline(std::cin, secret);
		if (std::cin.eof() == true)
			exit(0);
	}
	contact->setDarkestSecret(secret);
}

int	addContact(Contact *contact)
{
	askForFirstname(contact);
	askForLastname(contact);
	askForNickname(contact);
	askForNumber(contact);
	askForSecret(contact);
	return (0);
}
