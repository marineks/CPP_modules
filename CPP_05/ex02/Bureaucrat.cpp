/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:17:19 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/07 23:43:43 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
Bureaucrat::Bureaucrat(void) : _name(""), _grade(150)
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
Bureaucrat::Bureaucrat(int grade, std::string name)
try : _name(name), _grade(grade)
{
	std::cout << "📑 [Bureaucrat] Parametric Constructor called for " << this->_name << std::endl;
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

int 				Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void				Bureaucrat::setGrade(int rank)
{
	try
	{
		if (rank > 150)
			throw Bureaucrat::GradeTooHighException();
		else if (rank < 1)
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade = rank;
	}
	catch (Bureaucrat::GradeTooLowException& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException& exception)
	{
		std::cerr << exception.what() << std::endl;
	}
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
		if (this->_grade - 1 < 1) // Grade 1 is higher in rank than Grade 2
			throw Bureaucrat::GradeTooLowException();
		else
			this->_grade--;
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
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooHighException();
		else
			this->_grade++; // Grade 150 is lower in rank than Grade 149
	}
	catch (Bureaucrat::GradeTooHighException& exception)
	{
		std::cerr << exception.what() << std::endl;
		return ;
	}
	return ;
}

void				Bureaucrat::signForm(Form &form)
{
	std::cout << "Bureaucrat " <<  this->getName();
	std::cout << ((form.getIsSigned() == true) ? " signed." : " couldn't sign because he does not have the right credentials.") << std::endl;
	return ;
}

void				Bureaucrat::executeForm(Form const & form)
{
	try { form.execute(*this); }
	catch (std::exception & exception)
	{
		std::cout << RED << this->getName() << " cannot execute the " << form.getName() << ". ";
		std::cerr << exception.what() << RESET << std::endl << std::endl;
		return ;
	}
	std::cout << GREEN "Bureaucrat " << this->getName();
	std::cout << " executed " << form.getName() << RESET << std::endl << std::endl;		
	return ;
}


/*****
****** EXCEPTIONS
******
*********************************************************/
const char * 	Bureaucrat::GradeTooHighException::what (void) const throw() 
{
	return "The grade is too high.";
}


const char * 	Bureaucrat::GradeTooLowException::what (void) const throw() 
{
	return "The grade is too low.";
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
