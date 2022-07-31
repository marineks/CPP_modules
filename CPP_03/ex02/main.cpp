/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:57:28 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/31 13:21:20 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{	
	std::cout << "#--------------- FRAGTRAP PART ----------------#" << std::endl;

	FragTrap	Mordecai("Mordecai");
	FragTrap	Moxxi;
	FragTrap	Steele;
	FragTrap 	Captain("Captain Steele");
	FragTrap	Krieg("Krieg");
	FragTrap	copy(Krieg);

	
	Moxxi.setName("Moxxi");
	Mordecai.attack(Moxxi.getName()); // ClapTrap in output bc of subject
	Moxxi.takeDamage(20); // ClapTrap in output bc of subject
	std::cout << "Its HP are now : " << Moxxi.getHitPoints() << std::endl;
	Moxxi.highFivesGuys();
	Moxxi.beRepaired(20); // ClapTrap in output bc of subject
	std::cout << "Its HP are now : " << Moxxi.getHitPoints() << std::endl << std::endl;
	
	Steele = Captain;
	Moxxi.attack(Steele.getName());
	Steele.attack(Mordecai.getName());
	Steele.setName("Steele");
	
	copy.highFivesGuys();
	std::cout << std::endl;
	return (0);
}