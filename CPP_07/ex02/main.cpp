/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:41:04 by marine            #+#    #+#             */
/*   Updated: 2022/10/11 21:57:31 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <cstdlib>

#define MAX_VAL 9999

int main(void)
{	

	Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
	
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
   
    //SCOPE
    {
		std::cout << "Scope" << std::endl;
        Array<int> tmp = numbers;
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (tmp[i] != numbers[i])
			{
				std::cerr << "ERROR : didn't save the same value!!" << std::endl;
				return (1);
			}
		}
        Array<int> test(tmp);
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (test[i] != numbers[i])
			{
				std::cerr << "ERROR : didn't save the same value!!" << std::endl;
				return (1);
			}
		}
		test[1] = 4;
		for (int i = 0; i < MAX_VAL; i++)
		{
			if (test[i] != numbers[i])
			{
				std::cerr << "ERROR : didn't save the same value!!" << std::endl; // devrait être triggered
			}
		}
    }

	// ON CHECK QUE NOTRE ARRAY A LE MEME COMPORTEMENT QUE MIRROR
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "ERROR : didn't save the same value!!" << std::endl;
            return (1);
        }
    }
    
	// 2 CAS QUI SONT SENSES TRIGGER DES EXCEPTIONS (range : [0, MAX_VAL - 1])
	try { numbers[-2] = 0; }
    catch(const std::exception& e) {  std::cerr << e.what() << '\n'; }
    
	try { numbers[MAX_VAL] = 0; }
    catch(const std::exception& e) {  std::cerr << e.what() << '\n'; }

    for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
    
	delete [] mirror;

	return (0);
}