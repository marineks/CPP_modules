/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:22:47 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/13 00:16:05 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_HPP
# define SPAN_HPP

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"

# include <string>
# include <iostream>
# include <algorithm> 
# include <cstdlib>
# include <vector>

class Span 
{
		public :
				Span(void);								// default
				Span(Span const &src);					// copy
				~Span(void);							// destructor
				Span		&operator=(Span const &rhs); // affectation

				/* Parametric constructor */
				Span(unsigned int n);
				
				/* Other member functions */
				void	addNumber(long int	number);
				void	addRange(long int n, long int range); // plage itérative
				unsigned int		shortestSpan(void);
				unsigned int		longestSpan(void);

				/* Custom exceptions*/
				class FullSpanException : public std::exception
				{
					public:
						virtual const char *what() const throw();
				};

				class ImpossibleDistanceException : public std::exception
				{
					public:
						virtual const char *what() const throw();
				};
	
		private :
					unsigned int		_N;
					std::vector<int>	_stack;
};

#endif