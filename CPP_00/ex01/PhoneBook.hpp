/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:39:18 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/15 16:28:48 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H

class	Contact {

	public :
				Contact(void); // constructeur
				~Contact(void); // destructeur
				
				void setFirstName(char *str);
				void setLastName(char *str);
				void setNickname(char *str);
				void setPhoneNumber(int number);
				void setDarkestSecret(char *str);

				int	getFirstName(void) const;
				int	getLastName(void) const;
				int	getNickname(void) const;
				int	getPhoneNumber(void) const;
				int	getDarkestSecret(void) const;
				
				static int	getContactNb(void);
				
	private :
				char		*_firstName;
				char		*_lastName;
				char		*_nickname;
				int			_phoneNumber;
				char		*_darkestSecret;
				static int	_contactNb; // nb d'instances de contact
	
};

class	PhoneBook {

	public :
				Contact *contacts; // [8]

				PhoneBook(void); // constructeur
				~PhoneBook(void); // destructeur
};

#endif