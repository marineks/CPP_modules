/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:37:37 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/19 22:23:52 by msanjuan         ###   ########.fr       */
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

int		addContact(Contact *contact);
void	searchContact(PhoneBook *phonebook, int contact_count);


// TODO: gerer les controle D
// FIXME: quand qqch est faux (mettre des chars dans un int), ca boucle sans fin
// TODO: tester quand y a plus de 8 contacts
int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		PhoneBook instance;
		int	contact_count = 0;
		
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
					addContact(&instance.contacts[contact_count]);
					contact_count++;
				}
				else if (contact_count == 8)
				{
					std::cout << "Je dois remplacer le contact le plus ancien" << std::endl;
					contact_count = 0;
				}
			}
			else if (input == "SEARCH")
			{
				searchContact(&instance, contact_count);
			}
				
			else if (input == "EXIT")
				break ;
		}
	}
	else
	{
		std::cout << MSG_USAGE << std::endl;
		return (1);
	}
	return (0);
}