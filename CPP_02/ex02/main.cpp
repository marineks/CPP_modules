/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:07:20 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/29 11:48:02 by msanjuan         ###   ########.fr       */
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

	std::cout << std::endl;
	std::cout << "---------- MY OWN TESTS ----------" << std::endl;
	
	Fixed c;
	Fixed d(Fixed (4) / Fixed(2));

	std::cout << "c - d  : " << c - d << std::endl;

	c = 3;

	std::cout << "--c    : " << --c << std::endl;
	std::cout << "d is   : " << d << std::endl;

	d = c + d;
	
	std::cout << "d is   : " << d << std::endl;
	std::cout << "Min is : " << Fixed::min(c, d) << std::endl;
	
	return 0;
}