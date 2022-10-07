/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:59:38 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/07 14:50:47 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <cstdlib>

class PresidentialPardonForm : public Form
{
	public:
				PresidentialPardonForm(void); 												// default
				PresidentialPardonForm(PresidentialPardonForm const & src);					// copy
				~PresidentialPardonForm(void);												// destructor
				PresidentialPardonForm &	operator=(PresidentialPardonForm const & rhs);	// affectation

				/* Parametric constructors */
				PresidentialPardonForm(std::string const & target);

				/* Accessors */
				std::string const	getTarget(void) const;
				
				/* Other function members */
				bool				execute(Bureaucrat const & executor) const;
	
	private:
				std::string const	_target;
	
};


std::ostream &	operator<<(std::ostream & o, PresidentialPardonForm const & f);

#endif