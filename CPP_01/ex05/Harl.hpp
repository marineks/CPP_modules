/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:42:58 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/26 20:45:01 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CLASS_HPP
# define HARL_CLASS_HPP

# include <string>
# include <iostream>

class	Harl {

	public :
				Harl(void); // constructeur
				~Harl(void); // destructeur

				void	complain(std::string level);			

	private : 	
				void	_debug(void);
				void	_info(void);
				void	_warning(void);
				void	_error(void);

};				

#endif