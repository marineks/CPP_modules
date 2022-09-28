/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:39:14 by marine            #+#    #+#             */
/*   Updated: 2022/09/27 00:37:07 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define LEN 5

int main() {

	int intArray[LEN] = { 0, 1, 2, 3, 4 };
	char charArray[LEN] = { 'a', 'b', 'c', 'd', 'e' };
	std::string	stringArray[LEN] = { "hello", "this", "is", "a", "test"};

	std::cout << " --- Iter on an array of ints --- " << std::endl;
	iter(intArray, LEN, pow);

	std::cout << " --- Iter on an array of chars --- " << std::endl;
	iter(charArray, LEN, print);

	std::cout << " --- Iter on an array of strings --- " << std::endl;
	iter(stringArray, LEN, print);
	
	return (0);
}