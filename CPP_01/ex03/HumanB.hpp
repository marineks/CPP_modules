/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:10:00 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/26 16:42:59 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

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

class	HumanB {

	public :
				HumanB(std::string str); // constructeur
				~HumanB(void); // destructeur

				void		setName(std::string str);
				std::string	getName(void) const;
				void		attack(void);
				void		setWeapon(Weapon newWeapon);

	private : 	
				std::string _name;
				Weapon		*_weapon;
};

#endif