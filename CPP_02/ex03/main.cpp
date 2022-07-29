/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:47:12 by marine            #+#    #+#             */
/*   Updated: 2022/07/29 19:10:07 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

// bool bsp(Point const a, Point const b, Point const c, Point const point);
bool 	bsp(Point const & a, Point const & b, Point const & c, Point const & point);
void	print_result(Point const & a, Point const & b, Point const & c, Point const & point);


// https://planetcalc.com/8108/ pour verifier
int main( void )
{	
	/* Test qui doit renvoyer TRUE */
	Point a(2.0f, 6.0f);
	Point b(2.0f, 1.0f);
	Point c(5.0f, 1.0f);
	Point point(2.5f, 2.5f);
	
	// std::cout << "Print valeurs dans le main" << std::endl;
	// std::cout << a.getX() << std::endl;
	// std::cout << a.getY() << std::endl;
	// std::cout << b.getX() << std::endl;
	// std::cout << b.getY() << std::endl;
	// std::cout << c.getX() << std::endl;
	// std::cout << c.getY() << std::endl;
	// std::cout << point.getX() << std::endl;
	// std::cout << point.getY() << std::endl;
	
	print_result(a, b, c, point);

	/* Test qui doit renvoyer FALSE */
	Point const a2(2, 5);
	Point const b2(2, 1);
	Point const c2(4, 1);
	Point const point2(7, 15);
	
	print_result(a2, b2, c2, point2);

	/* Test qui doit renvoyer FALSE (le point == un des sommets) */
	Point const a3(2, 5);
	Point const b3(2, 1);
	Point const c3(4, 1);
	Point const point3(4, 1);
	
	print_result(a3, b3, c3, point3);

	/* Test qui doit renvoyer FALSE (le point => sur une des arrêtes) */
	Point const a4(2, 5);
	Point const b4(2, 1);
	Point const c4(4, 1);
	Point const point4(3, 1);
	
	print_result(a4, b4, c4, point4);
	return 0;
}