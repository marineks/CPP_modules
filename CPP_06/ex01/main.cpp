/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:47:20 by marine            #+#    #+#             */
/*   Updated: 2022/09/26 16:24:01 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

#include <cctype>
#include <iostream>
#include <stdint.h>
#include "Data.hpp"

/*
	POINT VOCAB'

	Sérialiser = processus visant à encoder l'état d'une information qui est
				 en mémoire sous la forme d'une suite d'informations plus petites

	Déséraliser = processus inverse

	Le but ici c'est donc d'encoder puis de décoder les variables membres d'une
	structure data.

	Ici, la notion de l'exo c'est le cast "reinterpret cast", qui autorise la conversion
	d'un pointeur (ou d'un type entier) en tout autre type de pointeur.
	Syntaxe: reinterpret_cast < new-type > ( expression )		

	Pourquoi on cast en uintptr_t (au delà du fait que c'est demandé dans l'exo)?
	=> "un type d'entier non signé qui est capable de stocker un pointeur de données. 
	Ce qui signifie généralement qu'il a la même taille qu'un pointeur."
	=> "unsigned integer type with the property 
	that any valid pointer to void can be converted to this type, 
	then converted back to pointer to void, 
	and the result will compare equal to the original pointer".
	=> bref le type parfait pour ce que l'exo nous demande de faire

	Attention tout de même car tous les forums disent que c'est la conversion la plus
	dangereuse/hasardeuse.
"
*/


//  prend un pointeur et convertit celui-ci vers le type d’entier non-signé uintptr_t.
uintptr_t	serialize(Data* ptr) {

	return reinterpret_cast<uintptr_t>(ptr);
}

//  prend un entier non-signé en paramètre et le convertit en pointeur sur Data.
Data		*deserialize(uintptr_t raw) {

	return reinterpret_cast<Data *>(raw);
}

int	main(void)
{
	Data data_ptr;

	data_ptr.number = 42;
	data_ptr.string = "Ceci est un test";

	std::cout << "Original number: " << data_ptr.number << std::endl;
	std::cout << "Original string: " << data_ptr.string << std::endl << std::endl;
	
	// Utilisez serialize() sur l’adresse de l’objet Data
	uintptr_t scrambled = serialize(&data_ptr);

	std::cout << "Scrambled value: " << scrambled << std::endl << std::endl;
	
	//  passez la valeur de retour obtenue à deserialize()
	Data *unscrambled = deserialize(scrambled);
	std::cout << "Unscrambled number: " << unscrambled->number << std::endl;
	std::cout << "Unscrambled string: " << unscrambled->string << std::endl << std::endl;
	
	// assurez-vous que le retour de deserialize() est identique au pointeur d’origine.
	data_ptr.number == unscrambled->number ? std::cout << GREEN << "OK" << RESET << std::endl :  std::cout << RED << "KO" << RESET << std::endl;
	data_ptr.string == unscrambled->string ? std::cout << GREEN << "OK" << RESET << std::endl :  std::cout << RED << "KO" << RESET << std::endl;

	return (0);
}