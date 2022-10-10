/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:00:02 by marine            #+#    #+#             */
/*   Updated: 2022/10/10 11:42:13 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"


/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
Convert::Convert(void) {}

Convert::Convert(const Convert& copy) { 
	*this = copy;
}

Convert::~Convert() {
	return ;
}

Convert& Convert::operator=(const Convert& rhs) {
	if ( this != &rhs )
	{
		this->_int = rhs._int;
		this->_char = rhs._char;
		this->_double = rhs._double;
		this->_float = rhs._float;
		this->_isConvertibleChar = rhs._isConvertibleChar;
		this->_isConvertibleInt = rhs._isConvertibleInt;
		this->_isPrintableChar = rhs._isPrintableChar;
	}
	return *this;
}

/*****
****** PARAMETRIC CONSTRUCTOR
******
*********************************************************/
Convert::Convert(std::string const user_input) 
{
	this->_isConvertibleInt = true;
	this->_isConvertibleChar = true;
	this->_isPrintableChar = true;

	// Identify the user's input type
	if (isChar(user_input) == false
		&& isInt(user_input) == false
		&& isFloat(user_input) == false
		&& isDouble(user_input) == false)
		this->_type = UNSUPPORTED;
	
	// Convert
	convertToOtherTypes();	
}

/*****
****** IDENTIFYING FUNCTIONS
******
*********************************************************/

bool	Convert::isInt(std::string const input)
{
	int base = 10;
	char *nonNumericalVal = NULL;
	
	long converted = strtol(input.c_str(), &nonNumericalVal, base);

	if (*nonNumericalVal || converted > INT_MAX || converted < INT_MIN)
		return (false);
		
	this->_type = INT;
	this->_int = static_cast<int>(converted);
	return (true);
}

bool	Convert::isChar(std::string const input)
{
	char converted = input[0];
	
	if (input[1] != 0 || std::isprint(input[0]))
		return (false);
		
	this->_type = CHAR;
	this->_char = converted;
	return (true);
}

bool	Convert::isFloat(std::string const input)
{
	char *nonNumericalVal = NULL;
	
	float converted = strtof(input.c_str(), &nonNumericalVal);
	
	if (*nonNumericalVal != 'f' || *(nonNumericalVal + 1) != 0)
		return (false);
		
	this->_type = FLOAT;
	this->_float = converted;
	return (true);
}

bool	Convert::isDouble(std::string const input)
{
	char *nonNumericalVal= NULL;
	
	double converted = strtod(input.c_str(), &nonNumericalVal);
	
	if (*nonNumericalVal)
		return (false);
	this->_type = DOUBLE;
	this->_double = converted;
	return (true);
}


/*****
****** CONVERTING FUNCTIONS
******
*********************************************************/

void	Convert::convertToOtherTypes(void)
{
	switch (this->_type)
	{
	case (CHAR):
		this->_int = static_cast<int>(this->_char);
		this->_float = static_cast<float>(this->_char);
		this->_double = static_cast<double>(this->_char);
		break;
	case (INT):
		this->_char = static_cast<char>(this->_int);
		this->_float = static_cast<float>(this->_int);
		this->_double = static_cast<double>(this->_int);
		break;
	case (FLOAT):
		this->_char = static_cast<char>(this->_float);
		this->_int = static_cast<int>(this->_float);
		this->_double = static_cast<double>(this->_float);
		break;
	case (DOUBLE):
		this->_char = static_cast<char>(this->_double);
		this->_float = static_cast<float>(this->_double);
		this->_int = static_cast<int>(this->_double);
		break;
	default:
		this->_isConvertibleChar = false;
		this->_isConvertibleInt = false;
		this->_float = NAN;
		this->_double = NAN;
		break;
	}
}

void	Convert::setDisplayFlags(void)
{
	if (this->_double < INT_MIN 
		|| this->_double > INT_MAX
		|| std::isnan(this->_double)
		|| std::isinf(this->_double))
	{
		this->_isConvertibleChar = false;
		this->_isConvertibleInt = false;
	}
	else if (this->_double < CHAR_MIN || this->_double > CHAR_MAX)
	{
		this->_isConvertibleChar = false;
	}
	else if (std::isprint(this->_char) == false)
	{
		this->_isPrintableChar = false;
	}
}


void	Convert::displayConversions(void) 
{
	setDisplayFlags();

	std::cout << std::fixed << std::setprecision(1);
	/* CHAR */
	if (this->_isConvertibleChar == false)
		std::cout << "char: impossible" << std::endl;
	else if (this->_isPrintableChar == false)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << this->_char << "'" << std::endl;

	/* INT */
	if (this->_isConvertibleInt == false)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << this->_int << std::endl;

	/* FLOAT */
	std::cout << "float: " << this->_float << "f" << std::endl;
	
	/* DOUBLE */
	std::cout << "double: " << this->_double << std::endl;
}