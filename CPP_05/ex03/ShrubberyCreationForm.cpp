/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:27:16 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/07 15:11:05 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include <sstream>

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
ShrubberyCreationForm::ShrubberyCreationForm(void)
	: Form("Shrubbery Creation Form", 145, 137, false), _target("Default target") {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
	: Form(src), _target(src.getName())
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

/* ---------------- PARAMETRIC CONSTRUCTOR -----------------*/
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: Form("Shrubbery Creation Form", 145, 137, false), _target(target) {}

/*****
****** ACCESSORS
******
*********************************************************/

std::string const ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

/*****
****** OTHER FUNCTIONS MEMBERS
******
*********************************************************/

bool ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > 137 || this->getIsSigned() == false)
			throw Form::InvalidExecutionGradeException();
		else
		{
			std::string newFilename = this->getTarget();
			newFilename.append("_shrubbery");

			std::ofstream newFile(newFilename.c_str());

			newFile << "				,@@@@@@@," << std::endl;
			newFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
			newFile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o"<< std::endl;
			newFile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
			newFile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'"<< std::endl;
			newFile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
			newFile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
			newFile << "       |o|        | |         | |" << std::endl;
			newFile << "       |.|        | |         | |"<< std::endl;
			newFile << "_\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_"  << std::endl;
			
			newFile.close();
			
		}
	}
	catch (Form::InvalidExecutionGradeException &exception)
	{
		// std::cout << RED << executor.getName() << " cannot execute this form. Reason : ";
		// std::cerr << exception.what() << RESET << std::endl;
		return false;
	}
	return true;
}

std::ostream &	operator<<(std::ostream & o, ShrubberyCreationForm const & f)
{
	o << "Form name is : " << f.getName() << std::endl;
	o << "Form's target is : " << f.getTarget() << std::endl;
	o << "Form's required execution grade is : " << f.getSignGrade() << std::endl;
	o << "Form's required signature grade is : " << f.getExecGrade() << std::endl;
	o << "Currently, it is : " << ((f.getIsSigned() == true) ? GREEN "signed." : RED "not signed.") << RESET << std::endl;
	return o;
	return o;
}