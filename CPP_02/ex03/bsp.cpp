/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:55:07 by marine            #+#    #+#             */
/*   Updated: 2022/07/29 18:57:32 by marine           ###   ########.fr       */
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

	std::cout << "Print valeurs dans sign" << std::endl;
	// std::cout << px << std::endl;
	// std::cout << py << std::endl;
	// std::cout << v1_x << std::endl;
	// std::cout << v1_x << std::endl;
	// std::cout << v2_x << std::endl;
	// std::cout << v2_y << std::endl;
		
	Fixed result = (px - v2_x) * (v1_y - v2_y) - (v1_x - v2_x) * (py - v2_y);

	std::cout << result << std::endl;
	std::cout << result.toFloat() << std::endl;
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
	// std::cout << "Print valeurs dans bsp" << std::endl;
	// std::cout << a.getX() << std::endl;
	// std::cout << a.getY() << std::endl;
	// std::cout << b.getX() << std::endl;
	// std::cout << b.getY() << std::endl;
	// std::cout << c.getX() << std::endl;
	// std::cout << c.getY() << std::endl;
	// std::cout << point.getX() << std::endl;
	// std::cout << point.getY() << std::endl;
	
	float s1, s2, s3;
	bool has_neg, has_pos;
	// Segment from A to B
	s1 = findSignOfSide(point, a, b);
	// Segment from B to C
	s2 = findSignOfSide(point, b, c);
	// Segment from A to C
	s3 = findSignOfSide(point, c, a);

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
	
	// si toutes les sides sont négatives ou positives; le point est en dehors du triangle
	has_neg = (s1 < 0) || (s2 < 0) || (s3 < 0);
    has_pos = (s1 > 0) || (s2 > 0) || (s3 > 0);

	// cas des sommets/arretes
	if (s1 == 0 || s2 == 0 || s3 == 0)
		return (false);
		
	// si (has_neg && has_pos) == true, ça veut dire que le point est en dehors, donc
	// il faut renvoyer FALSE, d'où la négation "!" juste avant.
	return !(has_neg && has_pos);
}	
