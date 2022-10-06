/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:27:16 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/06 18:58:38 by msanjuan         ###   ########.fr       */
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
	: Form("Robotomy Request Form", 145, 137, false), _target(target) {}

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

/* Échelons requis : signature 25, exécution 5
Informe que la <target> a été pardonnée par Zaphod Beeblebrox.*/
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() > 45 && this->getIsSigned() == false)
			throw Form::InvalidExecutionGradeException();
		else
		{

			std::string contents[] = 
			{
				"				,@@@@@@@,",
				"       ,,,.   ,@@@@@@/@@,  .oo8888o.",
				"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o",
				"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'",
				"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'",
				"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'",
				"   `&%\\ ` /%&'    |.|        \\ '|8'",
				"       |o|        | |         | |",
				"       |.|        | |         | |",
				"_\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_",
			};

			// creates a replace file to put the content into
			std::string newFilename = this->getTarget();
			newFilename.append("_shrubbery");

			// copies the contents of <filename> into a new file
			std::ofstream newFile(newFilename.c_str());
			newFile << contents;
			newFile.close();
		}
	}
	catch (Form::InvalidExecutionGradeException &exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	return;
}

std::ostream &	operator<<(std::ostream & o, ShrubberyCreationForm const & f)
{
	o << "Form name is : " << f.getName();
	o << "Form's target is : " << f.getTarget();
	o << "Form's required execution grade is : " << f.getSignGrade();
	o << "Form's required signature grade is : " << f.getExecGrade();
	o << "Currently, it is : " << ((f.getIsSigned() == true) ? "signed." : "not signed.") << std::endl;
	return o;
}