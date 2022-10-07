/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:16:21 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/07 14:48:36 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

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
// # include "Form.hpp"
class Form;

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
				void				signForm(Form &form);
				void				executeForm(Form const & form);

				/* Custom exceptions */
				class GradeTooHighException : public std::exception
				{
					public : 
							const char * 	what (void) const throw() {
								return "The grade is too high.";
							}
				};

				class GradeTooLowException : public std::exception
				{
					public : 
							const char * 	what (void) const throw() {
								return "The grade is too low.";
							}
				};
				
	private:
				std::string const 	_name;
				int 				_grade; // goes from 1 to 150
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & i);

#endif