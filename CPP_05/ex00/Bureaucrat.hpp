/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 11:16:21 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/04 17:40:30 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAR_CLASS_HPP
# define BUREAUCRAR_CLASS_HPP

# include <iostream>

class Bureaucrat
{
	public:
				Bureaucrat(void); 									// default
				Bureaucrat(Bureaucrat const & src);					// copy
				~Bureaucrat(void);									// destructor
				Bureaucrat &	operator=(Bureaucrat const & rhs);	// affectation

				/* Parametric constructors */
				Bureaucrat(unsigned int grade, std::string const name);
				
				/* Accessors */
				// void				setName(std::string str);
				std::string const	getName(void) const;

				void				setGrade(unsigned int rank);
				unsigned int		getGrade(void) const;
				
				/* Other function members */
				void				riseGrade(void);
				void				lowerGrade(void);

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
				unsigned int 		_grade; // goes from 1 to 150
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & i);

#endif