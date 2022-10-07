/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:16:21 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/07 23:22:19 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAR_CLASS_HPP
# define BUREAUCRAR_CLASS_HPP

# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

# include <iostream>
# include <cstdlib>

class Bureaucrat
{
	public:
				Bureaucrat(void); 									// default
				Bureaucrat(Bureaucrat const & src);					// copy
				~Bureaucrat(void);									// destructor
				Bureaucrat &	operator=(Bureaucrat const & rhs);	// affectation

				/* Parametric constructors */
				Bureaucrat(int grade, std::string const name);
				
				/* Accessors */
				// void				setName(std::string str);
				std::string const	getName(void) const;

				void				setGrade(int rank);
				int					getGrade(void) const;
				
				/* Other function members */
				void				riseGrade(void);
				void				lowerGrade(void);

				/* Custom exceptions */
				class GradeTooHighException : public std::exception
				{
					public : 
							const char * 	what (void) const throw();
				};

				class GradeTooLowException : public std::exception
				{
					public : 
							const char * 	what (void) const throw();
				};
				

	private:
				std::string const 	_name;
				int 				_grade; // goes from 1 to 150
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & i);

#endif