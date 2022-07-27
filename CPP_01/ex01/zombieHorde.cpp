/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:45:02 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/27 17:27:36 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *zombies;
	
	try
	{
		zombies = new Zombie[N];
	}
	catch (std::bad_alloc const & e)
	{
		std::cerr << "Error while creating Horde: " << e.what() << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++)
		zombies[i].setName(name);
	return (zombies);
}