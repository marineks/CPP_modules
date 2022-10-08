/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:16:18 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/08 15:07:59 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << YELLOW << "VERIF ACQUIS DU 1ER EXO" << RESET << std::endl;
	Bureaucrat one(5, "Ollie");
	std::cout << one << std::endl;
	one.riseGrade();
	std::cout << one << std::endl;
	one.lowerGrade();
	std::cout << one << std::endl;

	std::cout << "###############" << std::endl;

	Bureaucrat two(150, "Max");
	std::cout << two << std::endl;
	
	two.lowerGrade(); // should throw an exception (grade = 151)
	std::cout << two << std::endl;
	
	Bureaucrat three(1, "Jim");
	std::cout << three << std::endl;
	
	three.riseGrade(); // should throw an exception (grade = 0)
	std::cout << three << std::endl;
	
	std::cout << "###############" << std::endl;

	try
	{
		Bureaucrat four(666, "Satan"); // should throw an exception (too high)
		std::cout << four << std::endl;
	}
	catch (std::exception& exception) {}
		
	try
	{
		Bureaucrat five(-8, "Pam"); // should throw an exception (too low)
		std::cout << five << std::endl;
	}
	catch (std::exception& exception) {}

	std::cout << YELLOW << "NOW LA VRAIE CORRECTION" << RESET << std::endl;
	std::cout << std::endl;
	
	Form form_1("Buy more toilet paper", 78, 140, false);

	std::cout << form_1 << std::endl << std::endl;
	
	Form form_2;
	std::cout << form_2 << std::endl << std::endl;
	
	try
	{
		Form form_3("Burn Hippietech", 0, 140, false); // should throw a "too high" exception
	}
	catch (std::exception& exception) {}
	// HEHEHE CA HERITE DONC CA CATCHE TOUT
	
	try
	{
		Form form_4("Switch the babyfoot for a salary raise", 2, 268, false); // should throw a "too low" exception
	}
	catch (std::exception& exception) {}

	std::cout << std::endl << CYAN << "Tests de signature d'un form" << RESET << std::endl;
	std::cout << std::endl;
	
	std::cout << "Can Max sign Form 1 ?" << std::endl;
	two.signForm(form_1); // should throw a "too low" exception
	std::cout << std::endl;
	
	std::cout << "Can Ollie sign Form 1 ?" << std::endl;
	one.signForm(form_1);
	std::cout << std::endl;
	
	std::cout << "What's the current status of Form 1 ?" << std::endl;	
	std::cout << form_1 << std::endl << std::endl;

	return (0);
}