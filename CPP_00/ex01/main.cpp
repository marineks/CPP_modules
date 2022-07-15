/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:37:37 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/15 16:45:40 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

#define MSG_USAGE "Correct usage is ./PhoneBook"
#define SUCCESS 0

int	addContact(PhoneBook phonebook, int contact_count)
{

	return (0);
}

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
			std::cout << "Please enter a command (ADD, SEARCH or EXIT)" << std::endl;
			std::cin >> input;
			
			if (input.compare(add) == SUCCESS)
			{
				if (contact_count < 8)
				{
					Contact c_instance;
					std::cout << "Nouvelle instance (num" << contact_count << ") de la classe contact" << std::endl;
					std::cout << "Non function member: " << c_instance.getContactNb() << std::endl;
					addContact(instance, contact_count);
				}
				else
				{
					std::cout << "Je dois remplacer le contact le plus ancien" << std::endl;
				}
				contact_count++;
				 // instance detruite hors du scope d'une fonction
			}
			else if (input.compare(search) == SUCCESS)
				std::cout << "Je suis tombée sur search" << std::endl;
			else if (input.compare(exit) == SUCCESS)
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