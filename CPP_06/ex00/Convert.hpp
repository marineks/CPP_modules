/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:41:38 by marine            #+#    #+#             */
/*   Updated: 2022/09/25 20:03:01 by marine           ###   ########.fr       */
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

class Convert 
{
	public:
			Convert(void);								// default
			Convert(Convert const & copy);			// copy
			~Convert(void);								// destructor
			Convert& operator=(Convert const& rhs); // affectation

			/* Parametric constructor */
			Convert(std::string const & input);
			
			/* Other member functions - l stands for literal */
			char	ltoChar(void);
			int		ltoInt(void);
			float	ltoFloat(void);
			double	ltoDouble(void);

			/* Exceptions */
			class NonsensicalConversionException : public std::exception {
				const char* what(void) const throw();
			};

			class UnprintableException : public std::exception {
				const char* what(void) const throw();
			};

			class FormatException : public std::exception {
				const char* what(void) const throw();
			};

	private:
			bool	_isNbCorrectlyFormatted(const std::string& input) const;
			double	_input;
};

#endif