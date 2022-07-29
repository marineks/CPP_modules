/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:48:46 by marine            #+#    #+#             */
/*   Updated: 2022/07/29 18:42:57 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*****
****** CANONICAL CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

Point::Point(void) : _x(Fixed(0)), _y(Fixed(0))
{
	return ;
}

Point::Point(Point const & src)
{
	*this = src;
	return ;
}

Point::~Point(void)
{
	return ;
}

Point &		Point::operator=(Point const & rhs)
{
	// if (this != &rhs)
	// {
	// 	this->_x = rhs.getX();
	// 	this->_y = rhs.getY();
	// }
	return *this;
}

/*****
****** PARAMETRIC CONSTRUCTORS
******
*********************************************************/
Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y))
{
		return ;
}

/*****
****** ACCESSORS
******
*********************************************************/
Fixed const	Point::getX(void) const
{
	return this->_x;
}

Fixed const	Point::getY(void) const
{
	return this->_y;
}