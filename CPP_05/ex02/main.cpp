/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:16:18 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/08 15:31:08 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	srand(time(NULL));
	/* CHECK DECLARATION DE CLASSES */
	std::cout << YELLOW << " ### OVERVIEW OF THE CLASSES ###" << RESET << std::endl;
	Bureaucrat Georges(46, "Georges");
	std::cout << Georges << std::endl;

	Bureaucrat Alicia(2, "Alicia");
	std::cout << Alicia << std::endl;
	
	RobotomyRequestForm Robotomy("Claire");
	std::cout << Robotomy << std::endl;
	
	PresidentialPardonForm Pardon("Xavier");
	std::cout << Pardon << std::endl;
	
	ShrubberyCreationForm Shrubbery("Garden");
	std::cout << Shrubbery << std::endl;

	// Form testAbstrait; // should raise a compiling error

	/* CHECK SIGNER CHAQUE FORM */
	std::cout << YELLOW << " ### SIGN EACH FORM ###" << RESET << std::endl;
	Robotomy.beSigned(Georges);
	Georges.signForm(Robotomy);
	std::cout << Robotomy << std::endl;
	
	Alicia.executeForm(Pardon); // Alicia should not be able to execute
	Pardon.beSigned(Georges); // Georges should not be able to sign
	Pardon.beSigned(Alicia);
	Alicia.signForm(Pardon);
	std::cout << Pardon << std::endl;

	Shrubbery.beSigned(Georges);
	Georges.signForm(Shrubbery);
	std::cout << Shrubbery << std::endl;
	
	/* CHECK EXECUTER CHAQUE FORM */
	std::cout << YELLOW << " ### OVERVIEW OF THE CLASSES ###" << RESET << std::endl;
	Georges.executeForm(Robotomy); // Georges should not be able to exec
	Alicia.executeForm(Robotomy);
	Alicia.executeForm(Robotomy);
	Alicia.executeForm(Robotomy);
	Alicia.executeForm(Robotomy);
	Alicia.executeForm(Robotomy);
	Alicia.executeForm(Robotomy);
	Alicia.executeForm(Robotomy);
	Alicia.executeForm(Robotomy);

	Georges.executeForm(Pardon); // Georges should not be able to exec
	Alicia.executeForm(Pardon);

	Georges.executeForm(Shrubbery);
	
	
	return (0);
}