/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:53:12 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 19:17:12 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main(void)
{
	unsigned int	i = 0;
	unsigned int	n = 10;
	const AAnimal	*tab[n];

	// AAnimal test; // Must return an error of compilation because it cannot be instanciated (abstract class)
		
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
	
	std::cout << "Index 5 AAnimal should be a cat and is a : " << tab[5]->getType() << std::endl;
	std::cout << "Index 2 AAnimal should be a dog and is a : " << tab[2]->getType() << std::endl;

	
	std::cout << std::endl;
	std::cout << " # --------------- Call to destructors ----------------- # " << std::endl;

	for (int j = 0; j < 10; j++)
	{
		delete tab[j];
		std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl;
	}
	
	std::cout << std::endl << std::endl;
	std::cout << " # --------------- From the subject ----------------- # " << std::endl;
	
	const AAnimal *o = new Dog();
	const AAnimal *p = new Cat();

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
	std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl << std::endl;
	

	Cat *first = new Cat();
	std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl;
	Cat *second = new Cat(*first);
	std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl;

	delete first;
	std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl;
	delete second;
	std::cout << " # ~~~~~~~~~~~~~~~~~~~~~~ # " << std::endl;
	return (0);
}