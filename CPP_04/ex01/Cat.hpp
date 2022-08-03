/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:44:19 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 12:15:46 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public Animal
{
	public:
				Cat(void); 							// default
				Cat(Cat const & src);				// copy
				~Cat(void);							// destructor
				Cat &	operator=(Cat const & rhs); // affectation
			
				/* Accessors */
				std::string	getType(void) const;
				void		setType(std::string str);
				
				/* Other member functions */
				void	makeSound(void) const;
	
	private:
				std::string	_type;
				Brain		*_brain;
};

#endif