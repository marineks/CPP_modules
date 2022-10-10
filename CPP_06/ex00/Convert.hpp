/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:41:38 by marine            #+#    #+#             */
/*   Updated: 2022/10/10 11:43:25 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <string>
#include <iostream>
#include <cmath>

#include <cstdlib>
#include <stdexcept>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <stdlib.h>

typedef enum e_types
{
	CHAR = 0,
	INT,
	FLOAT,
	DOUBLE,
	UNSUPPORTED
}	t_types;

class Convert 
{
	public:
			Convert(void);								// default
			Convert(Convert const & copy);			// copy
			~Convert(void);								// destructor
			Convert& operator=(Convert const& rhs); // affectation

			/* Parametric constructor */
			Convert(std::string const input);
			
			/* Conversion functions */
			bool	isChar(std::string const input);
			bool	isInt(std::string const input);
			bool	isFloat(std::string const input);
			bool	isDouble(std::string const input);

			void	displayConversions(void);
			void	setDisplayFlags(void);
			void	convertToOtherTypes(void);

	private:
			int		_int;
			float	_float;
			double	_double;
			char	_char;
			t_types	_type;
			bool	_isConvertibleInt;
			bool	_isConvertibleChar;
			bool	_isPrintableChar;
};

#endif