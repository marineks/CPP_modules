/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:40:22 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/12 12:03:50 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"
#include <vector>
#include <algorithm>

int main(void)
{
	// Situation oú on ne trouve pas l'occurrence
	std::vector<int>			array(15, 8);
	
	try {  easyfind(array, 0); }
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n'; // devrait être triggered
	}
	
	// Vérifier qu'il trouve bien le 1er élément
	easyfind(array, 8);

	// Vérifier qu'il trouve l'élément qq soit sa position dans l'array
	std::vector<int>			v1; // {5, 2, -9999}
	v1.push_back(5);
	v1.push_back(2);
	v1.push_back(-9999);

	easyfind(v1, 5); // first
	easyfind(v1, 2); // mid
	easyfind(v1, -9999); // last

	// Test avec des chars
	std::vector<char>			v2; // {'d', 'w', 'a'}
	v2.push_back('d');
	v2.push_back('w');
	v2.push_back('a');

	easyfind(v2, 97); // 97 = 'a' (cf. proto qui doit prendre un int)
	
	return (0);
}
