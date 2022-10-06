/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:16:18 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/06 19:06:00 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat b_1(41, "Georges");
	std::cout << b_1 << std::endl;
	
	const Form *f_1 = new RobotomyRequestForm("Georges");
	std::cout << "Form name is : " << f_1->getName() << std::endl;
	// std::cout << "Form's target is : " << f_1->getTarget() << std::endl;
	std::cout << "Form's required execution grade is : " << f_1->getSignGrade() << std::endl;
	std::cout << "Form's required signature grade is : " << f_1->getExecGrade() << std::endl;
	std::cout << "Currently, it is : " << ((f_1->getIsSigned() == true) ? "signed." : "not signed.") << std::endl;

	PresidentialPardonForm f_2("Xavier");
	
	std::cout << f_2 << std::endl;
	
	// Form f_3 = ShrubberyCreationForm("Garden");
	// std::cout << f_3 << std::endl;
	

	delete f_1;
	// delete f_2;
	// delete f_3;

	return (0);
}