/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:44:23 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/31 15:52:00 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include "Animal.hpp"
# include <iostream>

class Dog : public Animal
{
	public:
				Dog(void); 							// default
				Dog(Dog const & src);				// copy
				~Dog(void);							// destructor
				Dog &	operator=(Dog const & rhs); // affectation
			
				/* Other member functions */
				void	makeSound(void);
	
	private:
				std::string	_type;
};

#endif