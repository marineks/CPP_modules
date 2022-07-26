/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:10:02 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/26 16:25:51 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"
# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

class	HumanA {

	public :
				// HumanA (void);
				HumanA(std::string name, Weapon &weapon); // constructeur
				~HumanA(void); // destructeur

				void		setName(std::string str);
				std::string	getName(void) const;
				void	attack(void);
				// void	setWeapon(Weapon & newWeapon);

	private : 	
				std::string _name;
				Weapon		&_weapon;
};

#endif