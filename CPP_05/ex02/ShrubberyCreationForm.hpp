/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:59:44 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/04 18:00:19 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <cstdlib>

// note a soi meme: classe abstraite Form en public ou privee ? pas oublier attributs en protected
class ShrubberyCreationForm : public Form
{
	public:
				ShrubberyCreationForm(void); 							// default
				ShrubberyCreationForm(Form const & src);					// copy
				~ShrubberyCreationForm(void);							// destructor
				ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & rhs);	// affectation

				/* Parametric constructors */
				ShrubberyCreationForm(std::string const target);
	
};

std::ostream &	operator<<(std::ostream & o, Form const & ppf);

#endif