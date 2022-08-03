/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 15:44:12 by msanjuan          #+#    #+#             */
/*   Updated: 2022/08/03 11:55:38 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_CLASS_HPP
# define AAnimal_CLASS_HPP

# include <iostream>

class AAnimal
{
	public:
				AAnimal(void); 							// default
				AAnimal(AAnimal const & src);				// copy
				virtual ~AAnimal(void) = 0;							// destructor
				AAnimal &	operator=(AAnimal const & rhs); // affectation
				
				/* Accessors */
				virtual std::string	getType(void) const;
				virtual void		setType(std::string str);
				
				/* Other member functions */
				virtual void	makeSound(void) const = 0; // Pure virtual function makes this class an Abstract class.
	
	protected:	
				std::string	_type;
};

#endif