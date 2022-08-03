/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:44:23 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 19:12:02 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>

class Dog : public AAnimal
{
	public:
				Dog(void); 							// default
				Dog(Dog const & src);				// copy
				~Dog(void);							// destructor
				Dog &	operator=(Dog const & rhs); // affectation
			
				/* Other member functions */
				void	makeSound(void) const; // override de la fonction 
	
	private:
				Brain		*_brain;
};

#endif