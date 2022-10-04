/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:59:06 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/04 17:59:27 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <cstdlib>

// note a soi meme: classe abstraite Form en public ou privee ? pas oublier attributs en protected
class RobotomyRequestForm : public Form
{
	public:
				RobotomyRequestForm(void); 							// default
				RobotomyRequestForm(Form const & src);					// copy
				~RobotomyRequestForm(void);							// destructor
				RobotomyRequestForm &	operator=(RobotomyRequestForm const & rhs);	// affectation

				/* Parametric constructors */
				RobotomyRequestForm(std::string const target);
	
};

std::ostream &	operator<<(std::ostream & o, Form const & ppf);

#endif