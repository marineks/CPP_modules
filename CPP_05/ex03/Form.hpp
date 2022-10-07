/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:05:32 by marine            #+#    #+#             */
/*   Updated: 2022/10/07 15:00:57 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <cstdlib>

class Form
{
	public:
				Form(void); 							// default
				Form(Form const & src);					// copy
				virtual ~Form(void) = 0;				// destructor
				Form &	operator=(Form const & rhs);	// affectation

				/* Parametric constructors */
				Form(std::string const name, int signGrade, int execGrade, bool state);
				
				/* Accessors */
				std::string const	getName(void) const;

				void				setSignGrade(int grade);
				int					getSignGrade(void) const;

				void				setExecGrade(int grade);
				int					getExecGrade(void) const;

				bool				getIsSigned(void) const;
				
				/* Other function members */
				void				beSigned(Bureaucrat & bureaucrat);
				virtual bool 		execute(Bureaucrat const & executor) const = 0;
				
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

				class InvalidExecutionGradeException : public std::exception
				{
					public : 
							const char * 	what (void) const throw() {
								return "The grade is too low or the form is not signed.";
							}
				};
				

	private:
				std::string const 	_name;
				int 				_signGrade;
				int					_execGrade;
				bool				_isSigned;
};

std::ostream &	operator<<(std::ostream & o, Form const & f);

#endif