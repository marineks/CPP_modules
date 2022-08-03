/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:33:14 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 11:47:52 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGAAnimal_CLASS_HPP
# define WRONGAAnimal_CLASS_HPP

# include <iostream>

class WrongAAnimal
{
	public:
				WrongAAnimal(void); 									// default
				WrongAAnimal(WrongAAnimal const & src);				// copy
				~WrongAAnimal(void);									// destructor
				WrongAAnimal &	operator=(WrongAAnimal const & rhs); // affectation
				
				/* Accessors */
				std::string	getType(void) const;
				void		setType(std::string str);
				
				/* Other member functions */
				void	makeSound(void) const;
	
	protected:	
				std::string	_type;
};

#endif