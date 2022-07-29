/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:07:20 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/29 02:25:15 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << "a        " << a << std::endl;
	std::cout << "++a      " << ++a << std::endl;
	std::cout << "a        " << a << std::endl;
	std::cout << "a++      " << a++ << std::endl;
	std::cout << "a        " << a << std::endl;
	
	std::cout << "b        " << b << std::endl;
	
	std::cout << "Max is : " << Fixed::max( a, b ) << std::endl;

	return 0;
}