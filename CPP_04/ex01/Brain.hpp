/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:08:31 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 15:03:30 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

# include <iostream>

class Brain
{
	public:
				Brain(void); 							// default
				Brain(Brain const & src);				// copy
				~Brain(void);							// destructor
				Brain &	operator=(Brain const & rhs);   // affectation
			
	private:
				std::string	_ideas[100];
};

#endif