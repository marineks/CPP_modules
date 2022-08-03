/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:53:12 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 12:00:25 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " : ";
	j->makeSound(); //will output the dog sound!
	std::cout << i->getType() << " : ";
	i->makeSound(); //will output the cat sound!
	std::cout << meta->getType() << " : ";
	meta->makeSound();
	
	std::cout << std::endl;
	delete i;
	delete j;
	delete meta;
	
	std::cout << std::endl << "/* -------- Wrong Animals -------- */" << std::endl << std::endl;
	
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	std::cout << k->getType() << " : ";
	k->makeSound(); //will output the animal sound!
	std::cout << wrong->getType() << " : ";
	wrong->makeSound();

	std::cout << std::endl;
	delete k;
	delete wrong;
	
	return (0);
}