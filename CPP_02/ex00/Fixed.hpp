/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:39:11 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/28 22:21:24 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <string>
# include <iostream>

class	Fixed {

	public :
				Fixed(void); 						  // Constructeur par defaut
				Fixed(Fixed const & src);			  // Constructeur par copie
				Fixed & operator=(Fixed const & rhs); // Operateur d'assignation
				~Fixed(void); 						  // Destructeur

				int					getRawBits(void) const;
				void				setRawBits(int const raw);

				const int			getFractBitsCount(void) const;

	private : 
				int					_rawBits; // = valeur du nombre en virgule fixe
				static const int	_fractBitsCount;	
			
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif