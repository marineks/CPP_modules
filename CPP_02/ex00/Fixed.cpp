/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:39:08 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/28 23:05:09 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

/*****
****** CANONICAL MEMBER FUNCTIONS
******
*********************************************************/

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy Constructor called" << std::endl;
	//this->_rawBits = src.getRawBits();
	*this = src; 
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &		Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return *this;
}


/*****
****** ACCESSORS
******
*********************************************************/
void	Fixed::setRawBits(int const raw) 
{
	this->_rawBits = raw;
	return ;
}

int	Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

int	const	Fixed::getFractBitsCount(void) const 
{
	return this->_fractBitsCount;
}

/*****
****** OVERLOAD ON OPERATOR <<
******
*********************************************************/
std::ostream &	operator<<(std::ostream & o, Fixed const & i)
{
	o << "The value of rawBits is : " << i.getRawBits();
	
	return o;
}

const int	Fixed::_fractBitsCount = 8;