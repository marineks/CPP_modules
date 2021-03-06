/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:37:37 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/25 17:39:10 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

#define MSG_USAGE "Correct usage is ./PhoneBook"
#define MSG_COMMAND "Please enter a command (ADD, SEARCH or EXIT)"
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

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		PhoneBook instance;
		std::string input;
		int	contact_count = 0;
		int eldest_index = 0;
		
		while (1)
		{
			std::cout << YELLOW << MSG_COMMAND << RESET << std::endl;
			std::cin >> input;
			
			if (input == "ADD")
			{
				addContact(&instance.contacts[(contact_count < 8) ? contact_count++ : eldest_index++]);
				if (eldest_index == 8)
					eldest_index = 0;
			}
			else if (input == "SEARCH")
				searchContact(&instance, contact_count);
			else if (input == "EXIT" || std::cin.eof() == true)
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