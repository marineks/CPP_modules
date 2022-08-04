/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:16:18 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/04 17:37:51 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
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

	std::cout << "###############" << std::endl;

	Bureaucrat three(1, "Max");
	std::cout << three << std::endl;
	three.riseGrade(); // should throw an exception (grade = 0)
	std::cout << three << std::endl;
	
	std::cout << "###############" << std::endl;

	// Bureaucrat four(666, "Satan"); // should throw an exception (too high)
	
	// Bureaucrat five(-8, "Pam"); // should throw an exception (too low)
	
	return (0);
}