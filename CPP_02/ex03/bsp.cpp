/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:55:07 by marine            #+#    #+#             */
/*   Updated: 2022/07/29 19:13:31 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/**
 * @brief On trace des segments selon les sommets 1 et 2 du triangle.
 * 			Si le point est du "bon côté" de l'arrête choisie, le signe est +.
 * 			Sinon, il est négatif.
 * 
 * @param point coordonnées du point dont il faut déterminer la "position" par 
 * 				rapport au triangle
 * @param vertex1 un des sommets du triangle
 * @param vertex2 un autre des sommets du triangle
 * @return float 
 */
float	findSignOfSide(Point const & point, Point const & vertex1, Point const & vertex2)
{
	Fixed const px = point.getX();
	Fixed const py = point.getY();
	Fixed const v1_x = vertex1.getX();
	Fixed const v1_y = vertex1.getY();
	Fixed const v2_x = vertex2.getX();
	Fixed const v2_y = vertex2.getY();

	// std::cout << "Print valeurs dans sign" << std::endl;
	// std::cout << px << std::endl;
	// std::cout << py << std::endl;
	// std::cout << v1_x << std::endl;
	// std::cout << v1_x << std::endl;
	// std::cout << v2_x << std::endl;
	// std::cout << v2_y << std::endl;
		
	Fixed result = (px - v2_x) * (v1_y - v2_y) - (v1_x - v2_x) * (py - v2_y);

	return result.toFloat();
}

/**
 * @brief Tells whether a given point is inside a triangle 
 * 
 * @param a, b, c => sommets du triangle
 * @param point => le point à évaluer
 * @return true : si le point est à l'intérieur du triangle
 * @return false : si point est en dehors du triangle (inclus si le point
 * 					est un sommet ou placé sur une arrête).
 */
bool bsp(Point const & a, Point const & b, Point const & c, Point const & point)
{
	float AB, BC, AC;
	bool is_inside = true;
	
	AB = findSignOfSide(point, a, b);
	BC = findSignOfSide(point, b, c);
	AC = findSignOfSide(point, c, a);
	
	if ((AB < 0 || BC < 0 || AC < 0) 
		&& (AB > 0 || BC > 0 || AC > 0))
		is_inside = false;
	
	// cas du point sur l'un des sommets/arrêtes
	if (AB == 0 || BC == 0 || AC == 0)
		is_inside = false;
		
	return (is_inside);
}	

	// std::cout << "Print valeurs dans bsp" << std::endl;
	// std::cout << a.getX() << std::endl;
	// std::cout << a.getY() << std::endl;
	// std::cout << b.getX() << std::endl;
	// std::cout << b.getY() << std::endl;
	// std::cout << c.getX() << std::endl;
	// std::cout << c.getY() << std::endl;
	// std::cout << point.getX() << std::endl;
	// std::cout << point.getY() << std::endl;
	
void	print_result(Point const & a, Point const & b, Point const & c, Point const & point)
{
	if (bsp(a, b, c, point) == true)
	 	std::cout << "Le point est dans le triangle : Oui" << std::endl;
	else
		std::cout << "Le point est dans le triangle : Non" << std::endl;
	return ;
}