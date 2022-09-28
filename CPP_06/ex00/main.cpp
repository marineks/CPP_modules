/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:31:14 by marine            #+#    #+#             */
/*   Updated: 2022/09/25 18:21:07 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1) detecter le type du litteral passé en paramètre

2) le convertir de sa représentation sous forme de chaines de caractères vers son véritable type

3) le convertir explicitement vers les trois autres types de données

! Gérer si une conversion n'a pas de sens ou overflow
! Gérer les limites numériques et les valeurs spéciales

*/

#include <iostream>
#include "Convert.hpp"

int main(int argc, char** argv) 
{
	if (argc == 2)
	{
		Convert *input;

		// ##### ASSIGNING THE LITERAL TO ITS TYPE #######
		try { 
			input = new Convert(argv[1]);
		}
		catch (std::exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
			return 1;
		}

		// ######## DISPLAY CONVERSION RESULTS #########
		std::cout << "char: ";
		try {
			std::cout << input->ltoChar() << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl; 
		}

		std::cout << "int: ";
		try {
			std::cout << input->ltoInt() << std::endl;
		}
		catch (std::exception& e) {
			 std::cout << e.what() << std::endl; 
		}
		
		// float fmod(float a, float b) => retourne le reste d'une division de a par b (ici, toujours 1)
		// instant nerd : difference remainder v. fmod = la façon dont on arrondit
		/*
			remainder : x - r * y, où r est le résultat de x/y, arrondi à la valeur entière la plus proche
			fmod : x _ t * y, où t est le résultat tronqué (aka arrondi vers 0) de x/y

			EXEMPLE : 
			double x = 5.1, y = 3;
			double result = remainder(x, y); => output is -0.9 (car 5.1/3 = 1.7, et là on arrondit à 2. Donc 5.1 - 2 * 3 = -0.9)
			double result2 = fmod(x, y); => output is 2.1
			Source: https://stackoverflow.com/questions/25734144/difference-between-c-functions-remainder-and-fmod 
		*/
		std::cout << "float: ";
		try {
			std::cout << input->ltoFloat();
			if (!fmod(input->ltoFloat(), 1)) // s'il n'y a pas de reste, on rajoute manuellement .0
			{
				std::cout << ".0"; 
			}
			std::cout << "f" << std::endl;
		} 
		catch (std::exception& e) { 
			std::cout << e.what() << std::endl; 
		}

		std::cout << "double: ";
		try {
			std::cout << input->ltoDouble();
			if (!fmod(input->ltoDouble(), 1))
			{
				std::cout << ".0";
			}
			std::cout << std::endl;
		} 
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		delete input;
		return 0;
	}
	else
	{
		std::cerr << "Correct usage is ./convert <litteral>" << std::endl;
		return 1;
	}
}