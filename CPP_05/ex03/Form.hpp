/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:05:32 by marine            #+#    #+#             */
/*   Updated: 2022/10/07 23:49:48 by marine           ###   ########.fr       */
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
				virtual void 		execute(Bureaucrat const & executor) const = 0;
				
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

				class UnsignedFormException : public std::exception
				{
					public : 
							const char * 	what (void) const throw();
				};
				

	private:
				std::string const 	_name;
				int 				_signGrade;
				int					_execGrade;
				bool				_isSigned;
};

std::ostream &	operator<<(std::ostream & o, Form const & f);

#endif
