/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:18:54 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/30 22:06:38 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP

# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

# include <iostream>

class ClapTrap
{
	public:
				ClapTrap(void); 							// default
				ClapTrap(ClapTrap const & src);				// copy
				~ClapTrap(void);							// destructor
				ClapTrap &	operator=(ClapTrap const & rhs); // affectation

				/* Parametric constructors */
				ClapTrap(std::string str);
				
				/* Accessors */
				std::string	getName(void) const;
				void		setName(std::string str);

				int			getHitPoints(void) const;
				void		setHitPoints(int hp);
				
				int			getEnergyPoints(void) const;
				void		setEnergyPoints(int mana);

				int			getAttackDamage(void) const;
				void		setAttackDamage(int dmg);

				/* Other member functions */
				void	attack(const std::string & target);
				void	takeDamage(unsigned int amount);
				void	beRepaired(unsigned int amount);
	
	protected:
				std::string	_name;
				int			_hitPoints;
				int			_energyPoints;
				int			_attackDamage;
};

#endif
