/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:51:22 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/07 15:03:27 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
PresidentialPardonForm::PresidentialPardonForm(void)
: Form("Presidential Pardon Form", 25, 5, false), _target("Default target") {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
: Form(src), _target(src.getName()) 
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

/* ---------------- PARAMETRIC CONSTRUCTOR -----------------*/
PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
: Form("Presidential Pardon Form", 25, 5, false), _target(target) {}

/*****
****** ACCESSORS
******
*********************************************************/

std::string const	PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

/*****
****** OTHER FUNCTIONS MEMBERS
******
*********************************************************/

/* Échelons requis : signature 25, exécution 5
Informe que la <target> a été pardonnée par Zaphod Beeblebrox.*/
bool	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > 5 || this->getIsSigned() == false)
			throw Form::InvalidExecutionGradeException();
		else
			std::cout << this->getTarget() << " was forgiven by Zaphod Beeblebrox." << std::endl;
	}
	catch (Form::InvalidExecutionGradeException& exception)
	{
		// std::cout << RED << executor.getName() << " cannot execute this form. Reason : ";
		// std::cerr << exception.what() << RESET << std::endl;
		return false;
	}
	return true;
}

std::ostream &	operator<<(std::ostream & o, PresidentialPardonForm const & f)
{
	o << "Form name is : " << f.getName() << std::endl;
	o << "Form's target is : " << f.getTarget() << std::endl;
	o << "Form's required execution grade is : " << f.getSignGrade() << std::endl;
	o << "Form's required signature grade is : " << f.getExecGrade() << std::endl;
	o << "Currently, it is : " << ((f.getIsSigned() == true) ? GREEN "signed." : RED "not signed.") << RESET << std::endl;
	return o;
}