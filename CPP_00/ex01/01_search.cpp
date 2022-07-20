/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_search.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:34:36 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/20 11:20:41 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <iomanip>
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

// "Ensuite, le programme demande à l’utilisateur d’entrer l’index du contact à af-
// ficher. Si l’index ou son format sont incorrects, gérez cela de manière pertinente.
// Sinon, affichez les informations du contact, une par ligne"
void	displayOneContact(PhoneBook *phonebook, int index)
{
	std::cout << GREEN << "Firstname: " << RESET << phonebook->contacts[index - 1].getFirstName() << std::endl;
	std::cout << GREEN << "Lastname: " << RESET << phonebook->contacts[index - 1].getLastName() << std::endl;
	std::cout << GREEN << "Nickname: " << RESET << phonebook->contacts[index - 1].getNickname() << std::endl;
	std::cout << GREEN << "Phone number: " << RESET << phonebook->contacts[index - 1].getPhoneNumber() << std::endl;
	std::cout << GREEN << "Darkest secret: " << RESET << phonebook->contacts[index - 1].getDarkestSecret() << std::endl;
	return ;
}

// "Si le texte dépasse la largeur de la colonne, il faut le tronquer et remplacer 
// le dernier caractère affiché par un point (’.’)."
std::string	trunc(std::string info)
{
	if (info.length() > 10)
	{
		info.resize(9);
		info.append(".");
	}
	return info;
}

// "Affiche les contacts enregistrés sous la forme d’une liste de 4 colonnes : index,
// first name, last name et nickname.
// Chaque colonne doit faire 10 caractères de long. Elles doivent être séparées
// par un pipe (’|’). Leur texte est aligné à droite."
void	searchContact(PhoneBook *phonebook, int contact_count)
{
	int format;
	
	std::cout << std::right << BLUE << std::setw(10) << "Index" << " | ";
	std::cout << std::right << std::setw(10) << "Firstname" << " | ";
	std::cout << std::right << std::setw(10) << "Lastname" << " | ";
	std::cout << std::right << std::setw(10) << "Nickname" << std::endl;
	std::cout << "-------------------------------------------------" << RESET << std::endl;
	for (int i = 0; i < contact_count; i++)
	{
		format = i + 1;
		
		std::cout << std::right << std::setw(10) << format << BLUE << " | " << RESET;
		std::cout << std::right << std::setw(10) << trunc(phonebook->contacts[i].getFirstName()) << BLUE << " | " << RESET;
		std::cout << std::right << std::setw(10) << trunc(phonebook->contacts[i].getLastName()) << BLUE << " | " << RESET;
		std::cout << std::right << std::setw(10) << trunc(phonebook->contacts[i].getNickname()) << std::endl;
	}
	std::cout << std::endl;
	std::cout << PURPLE << "Please enter the contact's index you want to display" << RESET << std::endl;
	
	int	index;
	std::cin >> index;
	while (std::cin.fail())
	{ //if type wasn't right
		std::cin.clear(); //clear stream
		std::cin.ignore(); //ignore left over data
		std::cout << BLUE << "Invalid value! An index is a number. Check the table." << RESET << std::endl;
		std::cin >> index;
	}
	while (index < 1 || index > 8 || index > contact_count)
	{
		std::cout << BLUE << "The phonebook only contains " << contact_count << " contact(s). Please enter a contact between 1 and " << contact_count << "." << RESET << std::endl;
		std::cin.clear(); //clear stream
		std::cin.ignore(); //ignore left over data
		std::cin >> index;
	}
	displayOneContact(phonebook, index);
}