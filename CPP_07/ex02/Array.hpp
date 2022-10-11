/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 00:39:58 by marine            #+#    #+#             */
/*   Updated: 2022/10/11 21:36:42 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

#include <string>
#include <iostream>

template<typename T>
class Array
{
	public:
			Array<T>(void);					// default
			Array<T>(Array<T> const &src);	// copy
			~Array<T>(void);				// destructor
			Array<T>		&operator=(Array<T> const &rhs);

			/* Parametric constructor */
			Array<T>(unsigned int n);
			
			/* Accessors */
			unsigned int	 size(void) const;
			T				*getContent(void) const;
			
			/* Operator overload */
			T				&operator[](unsigned int index);
			
			
	private:
			unsigned int	_n; // nombre d'éléments du tableau
			T			   *_content;
};


class InvalidIndexException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("The index is not correct");
		};
};



/*****
****** CONSTRUCTORS AND DESTRUCTORS
******
*********************************************************/

/* ---------------- CANONICAL -----------------*/
template<typename T>
Array<T>::Array(void) : _n(0), _content(0) {
	std::cout << "[DEFAULT CONSTRUCTOR] " << CYAN << "An empty array was created" << RESET << std::endl;
}

template<typename T>
Array<T>::Array(Array<T> const &src) : _n(0)
{
	*this = src;
	std::cout << "[COPY CONSTRUCTOR] " << PURPLE << "A copy of an array was created" << RESET << std::endl;
}

template<typename T>
Array<T>::~Array<T>(void)
{
	delete [] this->_content;
	std::cout << "[DESTRUCTOR] " << BLUE << "An instance of an array was destroyed" << RESET << std::endl;
}


template<typename T>
Array<T>	&Array<T>::operator=(Array<T> const &rhs)
{
	std::cout << "[ASSIGNATION OVERLOAD] " << YELLOW << " An array is being assigned to another" << RESET << std::endl;
	
	/* Avant de "remplir", vider ce qu'il y a déjà */
	if (this->_n > 0)
		delete [] this->_content;
	
	/* Allouer espace pour array */
	T *copyOfContent = new T[rhs.size()];
	
	/* Y "ranger" le content de rhs */
	for (unsigned int i = 0; i < rhs.size(); i++)
		copyOfContent[i] = rhs._content[i];
	
	/* attribuer aux éléments de l'array actuel ceux "copiés" plus haut */
	this->_n = rhs.size();
	this->_content = copyOfContent;
	
	return (*this);
}


/*****
****** PARAMETRIC CONSTRUCTOR
******
*********************************************************/
template<typename T>
Array<T>::Array(unsigned int n) : _n(n), _content(new T[n]) {
	// this->_n = n;
	// this->_content = new T[n];
	std::cout << "[PARAMETRIC CONSTRUCTOR] " << GREEN << "An array of size n: " << n << " was created" << RESET << std::endl;
}


/*****
****** ACCESSORS
******
*********************************************************/
template<typename T>
unsigned int	 Array<T>::size(void) const { return (this->_n); }

template<typename T>
T				*Array<T>::getContent(void) const { return (this->_content); }


/*****
****** OTHER OPERATOR OVERLOADS
******
*********************************************************/

template<typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= this->_n || index < 0)
		throw InvalidIndexException();
	return (this->_content[index]);
}

template<typename T>
std::ostream	&operator<<(std::ostream &stream, Array<T> const &array)
{
	for (size_t i = 0; i < array.size(); i++)
		stream << "Index [" << CYAN << i << RESET << "] = " << array.getContent()[i] << std::endl;

	return (stream);
}

#endif
