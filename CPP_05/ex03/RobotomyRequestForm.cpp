/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:58:54 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/07 23:52:22 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
RobotomyRequestForm::RobotomyRequestForm(void)
: Form("Robotomy Request Form", 72, 45, false), _target("Default target") {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
: Form(src) 
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	if (this != &rhs)
	{
		*this = rhs;
	}
	return *this;
}

/* ---------------- PARAMETRIC CONSTRUCTOR -----------------*/
RobotomyRequestForm::RobotomyRequestForm(std::string const target)
: Form("Robotomy Request Form", 72, 45, false), _target(target) {}

/*****
****** ACCESSORS
******
*********************************************************/

std::string const	RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

/*****
****** OTHER FUNCTIONS MEMBERS
******
*********************************************************/

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > 45)
		throw Form::GradeTooLowException();
	else if (this->getIsSigned() == false)
		throw Form::UnsignedFormException();
	else
	{
		std::cout << "BJJJZZZZ BJJJJJJZZZZ BBJJZZZZZZZ" << std::endl; // bruits de perceuse
		
		int RobotomyTry = std::rand() % 2;
		std::cout << this->getTarget();
		if (RobotomyTry == 0)
			std::cout << " was successfully robotomised!" << std::endl;
		else
			std::cout << "'s operation failed. Sorry their brain is intact!" << std::endl;
	}
}

std::ostream &	operator<<(std::ostream & o, RobotomyRequestForm const & f)
{
	o << "Form name is : " << f.getName() << std::endl;
	o << "Form's target is : " << f.getTarget() << std::endl;
	o << "Form's required execution grade is : " << f.getSignGrade() << std::endl;
	o << "Form's required signature grade is : " << f.getExecGrade() << std::endl;
	o << "Currently, it is : " << ((f.getIsSigned() == true) ? GREEN "signed." : RED "not signed.") << RESET << std::endl;
	return o;
}