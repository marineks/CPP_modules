/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:51:03 by marine            #+#    #+#             */
/*   Updated: 2022/10/07 22:17:23 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <cstdlib>

class Intern
{
	public:
				Intern(void); 								// default
				Intern(Intern const & src);					// copy
				~Intern(void);								// destructor
				Intern &	operator=(Intern const & rhs);	// affectation
				
				/* Other function members */
				Form	*makeForm(std::string formName, std::string target);

				class UnknownFormException : public std::exception
				{
					public : 
							const char * 	what (void) const throw();
				};
};

std::ostream &	operator<<(std::ostream & o, Intern const & i);

#endif