/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:31:40 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 18:33:49 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP

# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat : public WrongAnimal
{
	public:
				WrongCat(void); 							// default
				WrongCat(WrongCat const & src);				// copy
				~WrongCat(void);							// destructor
				WrongCat &	operator=(WrongCat const & rhs); // affectation
			
				// /* Accessors */
				// std::string	getType(void) const;
				// void		setType(std::string str);
				
				/* Other member functions */
				void	makeSound(void) const;
	
	// private:
	// 			std::string	_type;
};

#endif