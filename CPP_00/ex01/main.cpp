/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:37:37 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/19 20:15:58 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

#define MSG_USAGE "Correct usage is ./PhoneBook"
#define SUCCESS 0

# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

int	addContact(Contact *contact);


// TODO: gerer les controle D
// FIXME: quand qqch est faux (mettre des chars dans un int), ca boucle sans fin

int	main(int argc, char **argv)
{
	std::string	add ("ADD");
	std::string search ("SEARCH");
	std::string	exit ("EXIT");
		
	if (argc == 1)
	{
		// INSTANCIATION DE LA CLASSE PHONEBOOK
		PhoneBook instance;
		int	contact_count = 1;
		
		while (1)
		{
			std::string input;
			std::cout << YELLOW << "Please enter a command (ADD, SEARCH or EXIT)" << RESET << std::endl;
			std::cin >> input;
			
			if (input == "ADD")
			{
				if (contact_count < 8)
				{
					Contact c_instance;
					instance.contacts[contact_count] = c_instance;
					std::cout << "Nouvelle instance (num" << contact_count << ") de la classe contact" << std::endl;
					// std::cout << "Non function member: " << c_instance.getContactNb() << std::endl;
					addContact(&instance.contacts[contact_count]);
					// std::cout << "First name registered: " << instance.contacts[contact_count].getFirstName() << std::endl;
					// std::cout << "Last name registered: " << instance.contacts[contact_count].getLastName() << std::endl;
					// std::cout << "Nickname registered: " << instance.contacts[contact_count].getNickname() << std::endl;
					// std::cout << "Phonenumber registered: " << instance.contacts[contact_count].getPhoneNumber() << std::endl;
					// std::cout << "Darkest secret registered: " << instance.contacts[contact_count].getDarkestSecret() << std::endl;
					contact_count++;
				}
				else
				{
					std::cout << "Je dois remplacer le contact le plus ancien" << std::endl;
				}
				 // instance detruite hors du scope d'une fonction
			}
			else if (input == "SEARCH")
				std::cout << "Je suis tombée sur search" << std::endl;
			else if (input == "EXIT")
			{
				std::cout << "Je suis tombée sur exit" << std::endl;
				break ;
			}
			// std::cout << "dans main  " << instance.contacts->getContactNb() << std::endl;
		}
	}
	else
	{
		std::cout << MSG_USAGE << std::endl;
		return (1);
	}
	return (0);
}