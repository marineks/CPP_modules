/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:53:12 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 16:21:20 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main(void)
{
	unsigned int	i = 0;
	unsigned int	n = 10;
	const Animal	*tab[n];


	std::cout << " # --------------- Call to constructors ----------------- # " << std::endl;
	
	while (i < n / 2)
	{
		tab[i] = new Dog();
		std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl;
		i++;
	}
	while (i < n)
	{
		tab[i] = new Cat();
		std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl;
		i++;
	}

	std::cout << " # --------------- Make them do things ----------------- # " << std::endl;
	
	std::cout << "Index 5 animal should be a cat and is a : " << tab[5]->getType() << std::endl;
	std::cout << "Index 2 animal should be a dog and is a : " << tab[2]->getType() << std::endl;

	
	std::cout << std::endl;
	std::cout << " # --------------- Call to destructors ----------------- # " << std::endl;

	for (int j = 0; j < 10; j++)
	{
		delete tab[j];
		std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl;
	}
	
	std::cout << std::endl << std::endl;
	std::cout << " # --------------- From the subject ----------------- # " << std::endl;
	
	const Animal *o = new Dog();
	const Animal *p = new Cat();

	delete o;
	delete p;
	
	std::cout << std::endl << std::endl;
	std::cout << " # --------------- Let's try and deep copy!  ----------------- # " << std::endl;
	
	Cat origin;
	std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl;
	Cat copy(origin);
	std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl;
	Cat assign;
	std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl;
	assign = origin;
	std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl;
	

	Cat *first = new Cat();
	Cat *second = new Cat(*first);

	delete first;
	delete second;
	return (0);
}