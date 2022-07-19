/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:34:15 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/19 21:27:29 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
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
	while (firstname.empty())
	{
		std::cout << BLUE << "📜 Didn't hear anything. Firstname?" << RESET << std::endl;
		std::getline(std::cin, firstname);
	}
	contact->setFirstName(firstname);
	return ;
}

void	askForLastname(Contact *contact)
{
	std::string	lastname;

	std::cout << BLUE << "📜 Perfect. Lastname?" << RESET << std::endl;
	std::getline(std::cin, lastname);
	while (lastname.empty())
	{
		std::cout << BLUE << "📜 But surely you must have a lastname! Tell me." << RESET << std::endl;
		std::getline(std::cin, lastname);
	}
	contact->setLastName(lastname);
	return ;
}

void	askForNickname(Contact *contact)
{
	std::string	nickname;

	std::cout << BLUE << "📜 May I ask your nickname?" << RESET << std::endl;
	std::getline(std::cin, nickname);
	while (nickname.empty())
	{
		std::cout << BLUE << "📜 Don't be shy! Please speak louder." << RESET << std::endl;
		std::getline(std::cin, nickname);
	}
	contact->setNickname(nickname);
	return ;
}

// FIXME: lire la doc de std::string pour methode qui regarde s'il y a une lettre dans la str
void	askForNumber(Contact *contact)
{
	std::string	input;
	int	phonenumber = 0;

	std::cout << BLUE << "📜 Okay... No judgement there, pal! Your phone number?" << RESET << std::endl;
	std::getline(std::cin, input);
	
	while (input.empty() == true)
	{
		std::cout << BLUE << "📜 Buddy, this is a phonebook... Now what is your phone number?" << RESET << std::endl;
		std::getline(std::cin, input);
	}
	phonenumber = atoi(input.c_str());
	std::cout << "res " << phonenumber << std::endl;
	if (phonenumber <= 0)
	{
		std::cout << BLUE << "📜 Buddy, this is a phonebook... Now what is your phone number?" << RESET << std::endl;
		std::getline(std::cin, input);
	}
	contact->setPhoneNumber(phonenumber);
	// std::cout << "First name registered: " << contact->getFirstName() << std::endl;
	// std::cout << "Last name registered: " << contact->getLastName() << std::endl;
	// std::cout << "Nickname registered: " << contact->getNickname() << std::endl;
	// std::cout << "Phonenumber registered: " << contact->getPhoneNumber() << std::endl;
}

void	askForSecret(Contact *contact)
{
	std::string	secret;
	std::cout << BLUE << "📜 And last but not least... Your darkest secret, please!" << RESET << std::endl;
	std::getline(std::cin, secret)
	
	while (secret.empty())
	{
		std::cout << BLUE << "📜 Please don't worry, this is a safe place here... for your secrets 🧙‍♂️" << RESET << std::endl;
		std::getline(std::cin, secret);
	}
	contact->setDarkestSecret(secret)
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
