/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:05:32 by marine            #+#    #+#             */
/*   Updated: 2022/08/16 12:59:16 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <cstdlib>

class Form
{
	public:
				Form(void); 							// default
				Form(Form const & src);					// copy
				~Form(void);							// destructor
				Form &	operator=(Form const & rhs);	// affectation

				/* Parametric constructors */
				Form(std::string const name, int signGrade, int execGrade, bool state);
				
				/* Accessors */
				// void				setName(std::string str);
				std::string const	getName(void) const;

				void				setSignGrade(int grade);
				int					getSignGrade(void) const;

				void				setExecGrade(int grade);
				int					getExecGrade(void) const;

				// void				setIsSigned(bool state);
				bool				getIsSigned(void) const;
				
				/* Other function members */
				void				beSigned(Bureaucrat bureaucrat);
				
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
				int 				_signGrade;
				int					_execGrade;
				bool				_isSigned;
};

std::ostream &	operator<<(std::ostream & o, Form const & i);

#endif
