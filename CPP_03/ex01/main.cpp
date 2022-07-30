/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:57:28 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/30 16:38:20 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Roland;
	ClapTrap	Rhys("Rhys");
	ClapTrap	Lilith;

	Lilith.setName("Lilith");
	Roland.attack(Lilith.getName());
	Lilith.takeDamage(0);
	
	std::cout << std::endl;
	std::cout << "#-------------------------------#" << std::endl;

	Rhys.setAttackDamage(5);
	Rhys.attack(Roland.getName()); // No name exception
	Roland.takeDamage(5);
	Roland.beRepaired(2);
	std::cout << "Its HP are now : " << Roland.getHitPoints() << std::endl;

	std::cout << std::endl;
	std::cout << "#-------------------------------#" << std::endl;

	for (int i = 0; i < 10; i++)
		Lilith.attack(Rhys.getName());
	Lilith.attack(Rhys.getName()); // Must fail bc there are no EP left
	
	Rhys.setAttackDamage(10);
	Rhys.attack(Lilith.getName());
	Lilith.takeDamage(10);
	Lilith.beRepaired(10); // Must fail bc it has no HP left
	
	return (0);
}