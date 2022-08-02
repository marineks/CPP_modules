/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:44:12 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/02 11:04:26 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

# include <iostream>

class Animal
{
	public:
				Animal(void); 							// default
				Animal(Animal const & src);				// copy
				~Animal(void);							// destructor
				Animal &	operator=(Animal const & rhs); // affectation

				/* Parametric constructors */
				Animal(std::string type);
			
				/* Other member functions */
				virtual void	makeSound(void);
	
	protected:	
				std::string	_type;
};

#endif