/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:16:18 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/07 23:15:49 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	srand(time(NULL));
	/* CHECK DECLARATION OF CLASSES */
	std::cout << YELLOW << " ### OVERVIEW OF THE CLASSES ###" << RESET << std::endl;
	Bureaucrat Georges(46, "Georges");
	std::cout << Georges << std::endl;

	Bureaucrat Alicia(2, "Alicia");
	std::cout << Alicia << std::endl;
	
	Intern intern;

	/* CHECK CREATION OF FORMS BY INTERN */	
	Form *test = intern.makeForm("test non concluant", "Alicia");
	(void) test;
	
	Form *anotherTest = intern.makeForm("", "");
	(void) anotherTest;
	
	Form *Robotomy = intern.makeForm("robotomy request", "Bender");

	Form *Shrubbery = intern.makeForm("shrubbery creation", "Mansion");

	Form *Pardon = intern.makeForm("presidential pardon", "me");
	
	/* CHECK THAT IT WORKS */
	std::cout << YELLOW << " ### SIGN EACH FORM ###" << RESET << std::endl;
	
	Robotomy->beSigned(Georges);
	Georges.signForm(*Robotomy);
	
	Pardon->beSigned(Alicia);
	Alicia.signForm(*Pardon);

	Shrubbery->beSigned(Georges);
	Georges.signForm(*Shrubbery);
	
	/* CHECK EXECUTER CHAQUE FORM */
	Alicia.executeForm(*Robotomy);
	
	Alicia.executeForm(*Pardon);

	Georges.executeForm(*Shrubbery);

	delete test;
	delete anotherTest;
	delete Robotomy;
	delete Shrubbery;
	delete Pardon;
	return (0);
}