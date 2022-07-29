/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:48:18 by marine            #+#    #+#             */
/*   Updated: 2022/07/29 18:42:42 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_CLASS_HPP
# define POINT_CLASS_HPP

# include <iostream>
# include "Fixed.hpp"


class Point
{
	public:
				Point(void); // default
				Point(Point const & src); // copy
				~Point(void); // destructor
				Point &	operator=(Point const & rhs); // affectation

				/* Parametric constructors */
				Point(float const x, float const y);
				
				/* Accessors */
				Fixed const	getX(void) const;
				Fixed const	getY(void) const;
				
	
	private:
				Fixed const	_x;
				Fixed const	_y;
};

#endif
