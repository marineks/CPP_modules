/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:00:02 by marine            #+#    #+#             */
/*   Updated: 2022/09/25 20:50:03 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"


/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
Convert::Convert(void) : _input(0.0) {
	std::cout << "Default Constructor called" << std::endl;
	return ;
}

Convert::Convert(const Convert& copy) : _input(copy._input) { 
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
	return ;
}

Convert::~Convert() {
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Convert& Convert::operator=(const Convert& rhs) {
	if ( this != &rhs )
	{
		this->_input = rhs._input;
	}
	return *this;
}

/*****
****** PARAMETRIC CONSTRUCTOR
******
*********************************************************/
Convert::Convert(std::string const & user_input) 
{
	// char en double
	if (user_input.length() == 1 
		&& std::isprint(user_input[0])
		&& !std::isdigit(user_input[0])) 
		{ 
			_input = static_cast<double>(user_input[0]);
			return ;
		}
	if (_isNbCorrectlyFormatted(user_input) == false)
		throw FormatException();
	// reste (int, float, double) en double
	_input = std::strtod(user_input.c_str(), 0);
}

/*****
****** OTHER MEMBER FUNCTIONS
******
*********************************************************/

char Convert::ltoChar(void) {
	if (std::isnan(_input) || std::isinf(_input) || _input < 0 || _input > 128)
	{ 
		throw NonsensicalConversionException();
	}
	if (!std::isprint(_input))
	{ 
		throw UnprintableException(); 
	}
	return static_cast<char>(_input);
}

int Convert::ltoInt(void) {
	if (std::isnan(_input) || std::isinf(_input) || _input < INT_MIN || _input > INT_MAX) 
	{ 
		throw NonsensicalConversionException(); 
	}
	return static_cast<int>(_input);
}

float Convert::ltoFloat(void) {
	return static_cast<float>(_input);
}

double Convert::ltoDouble(void) {
	return _input; // pour rappel, déjà casté en double par défaut
}

bool Convert::_isNbCorrectlyFormatted(const std::string& input) const {
	
	const size_t	count = 8;
	bool			qualifier_reached = false;  // qualifier = '+' ou '-'
	bool			precision_reached = false;
	std::string		exceptions[count] = { "inf", "-inf", "+inf", "inff", "-inff", "+inff", "nan", "nanf" };

	// check si la string est une des expressions mathématiques spéciales
	for (size_t i = 0; i < count; i++)
		if (input == exceptions[i])
			return true;

	
	for (size_t i = 0; i < input.length(); i++) 
	{
		// si à un moment ce bool == true
		if (qualifier_reached)
			return false;

		// check s'il y a un char autre que - ou + devant le nombre
		if (i == 0 && std::isdigit(input[0]) == false) {
			if (!(input[0] == '-' || input[0] == '+'))
				return false;
			continue;
		}

		// check si on a un char plus loin dans la str autre qu'un "." ou "f"
		if (!std::isdigit(input[i])) {
			if (input[i] == '.' && !precision_reached)
				precision_reached = true;
			else if (input[i] == 'f' && !qualifier_reached) {
				qualifier_reached = true;
				precision_reached = true;
			} 
			else {
				return false;
			}
		}
	}
	return true;
}

const char* Convert::NonsensicalConversionException::what(void) const throw() {
	return "impossible";
}

const char* Convert::UnprintableException::what(void) const throw() {
	return "Non displayable";
}

const char* Convert::FormatException::what(void) const throw() {
	return "Incorrect format";
}