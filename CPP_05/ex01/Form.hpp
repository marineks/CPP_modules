/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:05:32 by marine            #+#    #+#             */
/*   Updated: 2022/10/07 23:21:16 by marine           ###   ########.fr       */
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
				void				beSigned(Bureaucrat & bureaucrat);
				
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
				int 				_signGrade;
				int					_execGrade;
				bool				_isSigned;
};

std::ostream &	operator<<(std::ostream & o, Form const & f);

#endif
