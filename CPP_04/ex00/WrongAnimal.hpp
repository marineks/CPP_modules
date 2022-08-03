/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:33:14 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 11:47:52 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_CLASS_HPP
# define WRONGANIMAL_CLASS_HPP

# include <iostream>

class WrongAnimal
{
	public:
				WrongAnimal(void); 									// default
				WrongAnimal(WrongAnimal const & src);				// copy
				~WrongAnimal(void);									// destructor
				WrongAnimal &	operator=(WrongAnimal const & rhs); // affectation
				
				/* Accessors */
				std::string	getType(void) const;
				void		setType(std::string str);
				
				/* Other member functions */
				void	makeSound(void) const;
	
	protected:	
				std::string	_type;
};

#endif