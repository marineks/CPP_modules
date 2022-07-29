/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:48:02 by marine            #+#    #+#             */
/*   Updated: 2022/07/29 14:48:04 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <string>
# include <iostream>
# include <cmath>

class	Fixed {

	public :
				Fixed(void); 						  // Constructeur par defaut
				Fixed(Fixed const & src);			  // Constructeur par copie
				Fixed & operator=(Fixed const & rhs); // Operateur d'assignation

				Fixed(int const n);					  // Constructeur parametrique
				Fixed(float const f);				  // Constructeur parametrique
				
				~Fixed(void); 						  // Destructeur
				
				bool operator>(Fixed const & rhs) const;
				bool operator<(Fixed const & rhs) const;
				bool operator>=(Fixed const & rhs) const;
				bool operator<=(Fixed const & rhs) const;
				bool operator==(Fixed const & rhs) const;
				bool operator!=(Fixed const & rhs) const;

				Fixed operator+(Fixed const & rhs) const;
				Fixed operator-(Fixed const & rhs) const;
				Fixed operator*(Fixed const & rhs) const;
				Fixed operator/(Fixed const & rhs) const;

				Fixed & operator++(void); // ++i
				Fixed & operator--(void); //--i
				Fixed operator++(int); // i++
				Fixed operator--(int); //i--
				
				int					getRawBits(void) const;
				void				setRawBits(int const raw);

				const int			getFractionalBits(void) const;

				float				toFloat(void) const;
				int					toInt(void) const;

				static Fixed		min(Fixed & a, Fixed & b);
				static Fixed		min(Fixed const & a, Fixed const & b);
				static Fixed		max(Fixed & a, Fixed & b);
				static Fixed 		max(Fixed const & a, Fixed const & b);

	private : 
				int					_rawBits; // = valeur du nombre en virgule fixe
				static const int	_fractionalBits;	
			
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif