/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:41:03 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/31 12:41:39 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap
{
	public:
				FragTrap(void); 							// default
				FragTrap(FragTrap const & src);				// copy
				~FragTrap(void);							// destructor
				FragTrap &	operator=(FragTrap const & rhs); // affectation

				/* Parametric constructors */
				FragTrap(std::string str);
			
				/* Other member functions */
				void	attack(const std::string & target);
				void	guardGate(void);
	
};

#endif
