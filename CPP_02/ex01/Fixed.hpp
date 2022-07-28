/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:07:58 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/29 00:26:56 by msanjuan         ###   ########.fr       */
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

				int					getRawBits(void) const;
				void				setRawBits(int const raw);

				const int			getFractBitsCount(void) const;

				float				toFloat(void) const;
				int					toInt(void) const;

	private : 
				int					_rawBits; // = valeur du nombre en virgule fixe
				static const int	_fractionalBits;	
			
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif