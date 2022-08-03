/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:44:12 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 11:55:38 by msanjuan         ###   ########.fr       */
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
				virtual ~Animal(void);							// destructor
				Animal &	operator=(Animal const & rhs); // affectation
				
				/* Accessors */
				virtual std::string	getType(void) const;
				virtual void		setType(std::string str);
				
				/* Other member functions */
				virtual void	makeSound(void) const;
	
	protected:	
				std::string	_type;
};

#endif