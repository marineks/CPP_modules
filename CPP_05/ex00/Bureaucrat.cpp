/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:17:19 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/04 17:41:04 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
Bureaucrat::Bureaucrat(void) : _name("")
{
	std::cout << "📑 [Bureaucrat] Default Constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	std::cout << "📑 [Bureaucrat] Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "📉 [Bureaucrat] Destructor " << this->_name << " called" << std::endl;
	return ;
}

Bureaucrat &		Bureaucrat::operator=(Bureaucrat const & rhs)
{
	std::cout << "📬 [Bureaucrat] Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		// this->_name = rhs.getName();
		this->_grade = rhs.getGrade();
	}
	return *this;
}

/* ---------------- PARAMETRIC CONSTRUCTOR -----------------*/
Bureaucrat::Bureaucrat(unsigned int grade, std::string name) 
try : _name(name), _grade(grade)
{
	std::cout << "📑 [Bureaucrat] Parametric Constructor called" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
}
catch (Bureaucrat::GradeTooLowException& exception)
{
	std::cerr << exception.what() << std::endl;	
}
catch (Bureaucrat::GradeTooHighException& exception)
{
	std::cerr << exception.what() << std::endl;
}

/*****
****** ACCESSORS
******
*********************************************************/

std::string const	Bureaucrat::getName(void) const
{
	return this->_name;
}

unsigned int 		Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void				Bureaucrat::setGrade(unsigned int rank)
{
	this->_grade = rank;
	return ;
}

/*****
****** OTHER FUNCTIONS MEMBERS
******
*********************************************************/

void				Bureaucrat::riseGrade(void)
{
	try
	{
		this->_grade--; // Grade 1 is higher in rank than Grade 2
		if (this->_grade < 1)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooLowException& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	return ;
}

void				Bureaucrat::lowerGrade(void)
{
	try
	{
		this->_grade++; // Grade 150 is lower in rank than Grade 149
		if (this->_grade > 150)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (Bureaucrat::GradeTooHighException& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	return ;
}

/*****
****** OVERLOAD ON OPERATOR <<
******
*********************************************************/
std::ostream &	operator<<(std::ostream & o, Bureaucrat const & b)
{
	o << b.getName()<< ", bureaucrat grade " << b.getGrade() << "." << std::endl; 
	return o;
}
