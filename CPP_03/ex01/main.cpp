/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:57:28 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/31 12:33:31 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{	
	std::cout << "#--------------- SCAVTRAP PART ----------------#" << std::endl;

	ScavTrap	Serena("Serena");
	ScavTrap	Fl4k;
	ScavTrap	Jack;
	ScavTrap 	Handsome("Handsome Jack");
	ScavTrap	Lilith("Lilith");
	ScavTrap	copy(Lilith);

	
	Fl4k.setName("Fl4k");
	Serena.attack(Fl4k.getName());
	Fl4k.takeDamage(20); // ClapTrap in output bc of subject
	std::cout << "Its HP are now : " << Fl4k.getHitPoints() << std::endl;
	Fl4k.guardGate();
	Fl4k.beRepaired(10);
	std::cout << "Its HP are now : " << Fl4k.getHitPoints() << std::endl << std::endl;
	
	Jack = Handsome;
	Fl4k.attack(Jack.getName());
	Jack.attack(Serena.getName());
	Jack.setName("Jack");
	
	copy.guardGate();
	std::cout << std::endl;
	return (0);
}