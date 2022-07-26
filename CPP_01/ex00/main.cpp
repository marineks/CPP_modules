/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:02:41 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/26 11:36:15 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

#define SUCCESS 0

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	// ANNOUNCE MEMBER FUNCTION TEST
	Zombie test;
	test.setName("Marine");
	test.announce();

	Zombie zombie;
	zombie.setName("Charlie");
	zombie.announce();

	std::cout << "-----------------------------------" << std::endl;
	// NEW ZOMBIE FUNCTION TEST
	Zombie *walkingDead = newZombie("Rick");
	walkingDead->announce();

	Zombie *theCranberries = newZombie("");
	theCranberries->announce();

	delete walkingDead;
	delete theCranberries;

	std::cout << "-----------------------------------" << std::endl;
	// RANDOM CHUMP FUNCTION TEST
	randomChump("Alpha");
	randomChump("Bravo");
	return (SUCCESS);
}