/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:51:06 by marine            #+#    #+#             */
/*   Updated: 2022/10/08 15:38:52 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>


/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/
/* ---------------- CANONICAL -----------------*/
Intern::Intern(void) {
	std::cout << "A random Intern appears" << std::endl;
}

Intern::Intern(Intern const & src)
{
	*this = src;
}

Intern::~Intern(){
	std::cout << "This work was not very efficient... Intern dismissed" << std::endl;
}

Intern &	Intern::operator=(Intern const & rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}


/*****
****** OTHER MEMBERS FUNCTIONS
******
*********************************************************/
Form	*Intern::makeForm(std::string formName, std::string target)
{
	std::string validForms[3] = {
		"robotomy request",
		"shrubbery creation",
		"presidential pardon"};
	
	try
	{
		for (int i = 0; i < 3; i++)
			if (formName == validForms[i])
			{
				std::cout << "Intern creates the " + formName + " form." << std::endl;
				switch (i)
				{
					case 0: return new RobotomyRequestForm(target);
					case 1: return new ShrubberyCreationForm(target);
					case 2: return new PresidentialPardonForm(target);
				}
			}
		throw UnknownFormException();
	}
	catch (const Intern::UnknownFormException & exception)
	{
		std::cout << exception.what() << RESET << std::endl;
		return (NULL);
	}
}

/*****
****** EXCEPTIONS
******
*********************************************************/
const char * 	Intern::UnknownFormException::what (void) const throw()
{
	return "This Form does not exist.";
}