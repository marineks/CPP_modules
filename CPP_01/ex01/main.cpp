/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:46:10 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/26 12:01:34 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define SUCCESS 0

Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	int		z_count = 3;
	Zombie	*undeadArmy = zombieHorde(z_count, "Nameless Zombie");

	std::cout << "-----------------------------------" << std::endl;
	for (int i = 0; i < z_count; i++)
	{
		std::cout << PURPLE << " i: " << i + 1 << " " << RESET;
		undeadArmy[i].announce();
	}

	std::cout << "-----------------------------------" << std::endl;
	delete [] undeadArmy;	
	
	return (SUCCESS);
}