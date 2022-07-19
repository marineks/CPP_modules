/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:39:18 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/19 15:37:40 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H

# include "Contact.hpp"
 
class	PhoneBook {

	public :
				Contact contacts[8];

				PhoneBook(void); // constructeur
				~PhoneBook(void); // destructeur
};

#endif