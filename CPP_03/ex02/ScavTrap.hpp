/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:25:21 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/31 12:30:33 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_CLASS_HPP
# define ScavTrap_CLASS_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
{
	public:
				ScavTrap(void); 							// default
				ScavTrap(ScavTrap const & src);				// copy
				~ScavTrap(void);							// destructor
				ScavTrap &	operator=(ScavTrap const & rhs); // affectation

				/* Parametric constructors */
				ScavTrap(std::string str);
			
				/* Other member functions */
				void	attack(const std::string & target);
				void	guardGate(void);
	
};

#endif
