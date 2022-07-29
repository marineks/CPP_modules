/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:47:44 by marine            #+#    #+#             */
/*   Updated: 2022/07/29 14:47:46 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
Fixed::Fixed(void) : _rawBits(0)
{
	// std::cout << "Default Constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src)
{
	// std::cout << "Copy Constructor called" << std::endl;
	*this = src; 
	return ;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &		Fixed::operator=(Fixed const & rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return *this;
}


/* ------------- PARAMETRIC CONSTRUCTORS  --------------*/

/**
 * @brief Convertit n en virgule fixe (_rawBits).
 * 
 * 		Exemple de la logique: "Par exemple, pour un nombre stocké sur un octet, 
 * 		soit huit bits, si on définit arbitrairement la position de la virgule 
 * 		juste avant après le quatrième bit, alors on sait que 0110 1001 = 0110,1001"
 * 		=> Donc pour "deplacer la virgule", et ainsi determiner notre fixed point,
 * 		   on shift l'entier donne.
 * @param n (entier constant)
 */
Fixed::Fixed(int const n)
{
	this->_rawBits = n << _fractionalBits;
	return ;
}

/**
 * @brief Convertit f en virgule fixe (_rawBits)
 * 			
 * 		  LOGIC: 
 * 			1) Multiply f by 2^_fractonalBits
 * 			2) Round the value to the nearest integer
 * 		
 * @param f (flottant constant)
 */
Fixed::Fixed(float const f)
{
	this->_rawBits = roundf(f * (1 << _fractionalBits));
	return ;
}

/*****
****** COMPARISON OPERATOR OVERLOADS
******
*********************************************************/
bool Fixed::operator>(Fixed const & rhs) const
{
	return (this->_rawBits > rhs.getRawBits() ? true : false);
}

bool Fixed::operator<(Fixed const & rhs) const
{
	return (this->_rawBits < rhs.getRawBits() ? true : false);
}

bool Fixed::operator>=(Fixed const & rhs) const
{
	return (this->_rawBits >= rhs.getRawBits() ? true : false);
}

bool Fixed::operator<=(Fixed const & rhs) const
{
	return (this->_rawBits <= rhs.getRawBits() ? true : false);
}

bool Fixed::operator==(Fixed const & rhs) const
{
	return (this->_rawBits == rhs.getRawBits() ? true : false);
}

bool Fixed::operator!=(Fixed const & rhs) const
{
	return (this->_rawBits != rhs.getRawBits() ? true : false);
}


/*****
****** ARITHMETIC OPERATOR OVERLOADS
******
*********************************************************/
Fixed Fixed::operator+(Fixed const & rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}

/*****
****** INCREMENT OPERATOR OVERLOADS
******
*********************************************************/

Fixed &Fixed::operator++(void) // pre
{
	(this->_rawBits)++;
	return *this;
}

Fixed &Fixed::operator--(void)
{
	(this->_rawBits)--;
	return *this;
}

Fixed Fixed::operator++(int) // post
{
	Fixed tmp;
	tmp.setRawBits(this->_rawBits);
	this->_rawBits++;
	return tmp;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp;
	tmp.setRawBits(this->_rawBits);
	this->_rawBits--;
	return tmp;
}
/*****
****** OVERLOAD ON OPERATOR <<
******
*********************************************************/
std::ostream &	operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	
	return o;
}


/*****
****** ACCESSORS
******
*********************************************************/
void		Fixed::setRawBits(int const raw) 
{
	this->_rawBits = raw;
	return ;
}

int			Fixed::getRawBits(void) const 
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_rawBits;
}

int	const	Fixed::getFractionalBits(void) const 
{
	return this->_fractionalBits;
}


/*****
****** CONVERTERS from fixed-point to floating-point
******
*********************************************************/

// LOGIC : We take _rawBits and divide it by (2^fractional_bits)
float		Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (float)(1 << _fractionalBits));
}

// LOGIC : we shift in the other direction (was << in the parametric constructor)
int			Fixed::toInt(void) const
{
	return (this->_rawBits >> _fractionalBits);
}


/*****
****** MIN AND MAX PUBLIC MEMBER FUNCTIONS
******
*********************************************************/
Fixed 	Fixed::min(Fixed & a, Fixed & b)
{
	return (a <= b) ? a : b;
}

Fixed	Fixed::min(Fixed const & a, Fixed const & b)
{
	return (a <= b) ? a : b;
}

Fixed	Fixed::max(Fixed & a, Fixed & b)
{
	return (a >= b) ? a : b;
}

Fixed	Fixed::max(Fixed const & a, Fixed const & b)
{
	return (a >= b) ? a : b;
}

const int	Fixed::_fractionalBits = 8;