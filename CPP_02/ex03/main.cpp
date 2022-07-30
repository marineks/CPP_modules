/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:47:12 by marine            #+#    #+#             */
/*   Updated: 2022/07/30 11:52:58 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool 	bsp(Point const a, Point const b, Point const c, Point const point);
void	print_result(Point const a, Point const b, Point const c, Point const point);


// https://planetcalc.com/8108/ pour verifier
int main( void )
{	
	/* Test qui doit renvoyer TRUE */
	Point a(2.0f, 6.0f);
	Point b(2.0f, 1.0f);
	Point c(5.0f, 1.0f);
	Point point(2.5f, 2.5f);

	print_result(a, b, c, point);

	/* Test qui doit renvoyer FALSE */
	Point const a2(2, 5);
	Point const b2(2, 1);
	Point const c2(4, 1);
	Point const point2(7, 15);
	
	print_result(a2, b2, c2, point2);

	/* Test qui doit renvoyer FALSE (le point == un des sommets) */
	Point const point3(4, 1);
	
	print_result(a2, b2, c2, point3);

	/* Test qui doit renvoyer FALSE (le point => sur une des arrêtes) */
	Point const point4(3, 1);
	
	print_result(a2, b2, c2, point4);
	return 0;
}