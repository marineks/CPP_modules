/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:59:38 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/04 17:59:40 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <cstdlib>

// note a soi meme: classe abstraite Form en public ou privee ? pas oublier attributs en protected
class PresidentialPardonForm : public Form
{
	public:
				PresidentialPardonForm(void); 							// default
				PresidentialPardonForm(Form const & src);					// copy
				~PresidentialPardonForm(void);							// destructor
				PresidentialPardonForm &	operator=(PresidentialPardonForm const & rhs);	// affectation

				/* Parametric constructors */
				PresidentialPardonForm(std::string const target);
	
};

std::ostream &	operator<<(std::ostream & o, Form const & ppf);

#endif