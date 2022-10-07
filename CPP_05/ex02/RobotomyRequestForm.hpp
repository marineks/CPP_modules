/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:59:06 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/07 23:44:51 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>
# include <cstdlib>

class RobotomyRequestForm : public Form
{
	public:
				RobotomyRequestForm(void);											// default
				RobotomyRequestForm(RobotomyRequestForm const & src);				// copy
				~RobotomyRequestForm(void);											// destructor
				RobotomyRequestForm &	operator=(RobotomyRequestForm const & rhs);	// affectation

				/* Parametric constructors */
				RobotomyRequestForm(std::string const target);
				
				/* Accessors */
				std::string const	getTarget(void) const;
				
				/* Other function members */
				void				execute(Bureaucrat const & executor) const;

	private:
				std::string const	_target;
	
};

std::ostream &	operator<<(std::ostream & o, RobotomyRequestForm const & f);

#endif