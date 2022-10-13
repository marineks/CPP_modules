/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:22:15 by msanjuan          #+#    #+#             */
/*   Updated: 2022/10/13 11:03:11 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <algorithm> 
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public :
			MutantStack() {}								
			MutantStack(MutantStack const &src) { *this = src; }						
			MutantStack		&operator=(MutantStack const &rhs) {
				this->c = rhs.c;
				return (*this);
			} 
			~MutantStack() {};	
			
			typedef typename std::stack<T>::container_type::iterator iterator;
			typedef typename std::stack<T>::container_type::const_iterator const_iterator;
			
			iterator begin(void) {
				return (this->c.begin());
			}

			iterator end(void) {
				return (this->c.end());
			}

			const_iterator begin(void) const {
				return (this->c.begin());
			}

			const_iterator end(void) const {
				return (this->c.end());
			}
};

#endif