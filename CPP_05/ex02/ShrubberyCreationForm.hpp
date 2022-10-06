/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:59:44 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/06 18:46:32 by msanjuan         ###   ########.fr       */
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
				ShrubberyCreationForm(ShrubberyCreationForm const & src);					// copy
				~ShrubberyCreationForm(void);							// destructor
				ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & rhs);	// affectation

				/* Parametric constructors */
				ShrubberyCreationForm(std::string const & target);

				/* Accessors */
				std::string const	getTarget(void) const;
				
				/* Other function members */
				void execute(Bureaucrat const & executor) const;
	
	private:
				std::string const _target;
};

std::ostream &	operator<<(std::ostream & o, ShrubberyCreationForm const & f);

#endif