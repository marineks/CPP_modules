/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:05:10 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/26 13:56:24 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define RESET "\033[0m"
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define SUCCESS 0

void	printAddress(std::string str, void *var, std::string color)
{
	std::cout << PURPLE << str << color<< var << RESET << std::endl;
	return ;
}

void	printValue(std::string str, std::string var, std::string color)
{
	std::cout << PURPLE << str << color<< var << RESET << std::endl;
	return ;
}

int main(void)
{
	std::string greeting("HI THIS BRAIN");
	std::string	*stringPTR = &greeting;
	std::string &stringREF = greeting;

	// print memory address 
	printAddress("Memory address of the string: ", static_cast<void*>(&greeting), YELLOW);
	printAddress("Memory address of stringPTR : ", stringPTR, CYAN);
	printAddress("Memory address of stringREF : ", &stringREF, BLUE);
	
	std::cout << "-----------------------------------------------------" << std::endl;
	// print value
	printValue("Value of the string variable : ", greeting, YELLOW);
	printValue("Value pointed to by stringPTR: ", *stringPTR, CYAN);
	printValue("Value pointed to by stringREF: ", stringREF, BLUE);

	
	return (SUCCESS);
}