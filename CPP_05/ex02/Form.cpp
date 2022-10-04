/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:05:34 by marine            #+#    #+#             */
/*   Updated: 2022/10/04 15:17:04 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
Form::Form(void) : _name("Default"), _signGrade(75), _execGrade(1), _isSigned(false)
{
	std::cout << GREEN << "📑 [Form] Default Constructor called" << RESET << std::endl;
	return ;
}

Form::Form(Form const & src): _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade), _isSigned(src._isSigned)
{
	std::cout << YELLOW "📑 [Form] Copy Constructor called" << RESET << std::endl;
	*this = src;
	return ;
}

Form::~Form()
{
	std::cout << RED << "📉 [Form] Destructor " << this->_name << " called" << RESET << std::endl;
	return ;
}

Form &		Form::operator=(Form const & rhs)
{
	std::cout << "📬 [Form] Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		// this->_name = rhs.getName();
		this->_signGrade = rhs.getSignGrade();
		this->_execGrade = rhs.getExecGrade();
		this->_isSigned = rhs.getIsSigned();
	}
	return *this;
}

/* ---------------- PARAMETRIC CONSTRUCTOR -----------------*/
Form::Form(std::string const name, int signGrade, int execGrade, bool state)
try : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(state)
{
	std::cout << BLUE << "📑 [Form] Parametric Constructor called for " << this->_name << RESET << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}
catch (Form::GradeTooLowException& exception)
{
	std::cerr << exception.what() << std::endl;
}
catch (Form::GradeTooHighException& exception)
{
	std::cerr << exception.what() << std::endl;
}

/*****
****** ACCESSORS
******
*********************************************************/

std::string const	Form::getName(void) const
{
	return this->_name;
}

int 				Form::getSignGrade(void) const
{
	return this->_signGrade;
}

int 				Form::getExecGrade(void) const
{
	return this->_execGrade;
}

bool 				Form::getIsSigned(void) const
{
	return this->_isSigned;
}

void				Form::setSignGrade(int rank)
{
	try
	{
		if (rank < 1)
			throw Form::GradeTooHighException();
		else if (rank > 150)
			throw Form::GradeTooLowException();
		else
			this->_signGrade = rank;
	}
	catch (Form::GradeTooLowException& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (Form::GradeTooHighException& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	return ;
}

void				Form::setExecGrade(int rank)
{
	try
	{
		if (rank < 1)
			throw Form::GradeTooHighException();
		else if (rank > 150)
			throw Form::GradeTooLowException();
		else
			this->_execGrade = rank;
	}
	catch (Form::GradeTooLowException& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (Form::GradeTooHighException& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	return ;
}

/*****
****** OTHER FUNCTIONS MEMBERS
******
*********************************************************/
void				Form::beSigned(Bureaucrat & bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > this->_signGrade) // Grade 1 is higher in rank than Grade 2
			throw Bureaucrat::GradeTooLowException();
		else
		{
			this->_isSigned = true;
			std::cout << bureaucrat.getName() << " is able to sign the Form!" << std::endl;
		}
			
	}
	catch (Bureaucrat::GradeTooLowException& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	return ;
}

/*****
****** OVERLOAD ON OPERATOR <<
******
*********************************************************/
std::ostream &	operator<<(std::ostream & o, Form const & f)
{
	o << "The Form is named : <" << YELLOW << f.getName() << RESET << ">. The required grade to sign it is : ";
	o << GREEN << f.getSignGrade() << RESET << ". The one to execute it is : " << CYAN << f.getExecGrade() << RESET;
	o << ". Currently, it is ";
	o << BLUE << ((f.getIsSigned() == true) ? "signed." : "not signed.") << RESET << std::endl;
	return o;
}