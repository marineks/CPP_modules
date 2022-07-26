/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:43:09 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/26 11:45:17 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_CLASS_H

# include <string>
# include <iostream>
# define RESET "\033[0m"
# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

class	Zombie {

	public :
				Zombie(void); // constructeur
				~Zombie(void); // destructeur

				void		setName(std::string str); // accesseurs
				std::string	getName(void) const;

				void		announce(void); // <name> : BraiiiiiiinnnzzzZ..
	
	private : 	
				std::string	_name;
};

#endif