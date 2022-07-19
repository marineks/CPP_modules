/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:37:00 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/19 18:01:23 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H

class	Contact {

	public :
				Contact(void); // constructeur
				~Contact(void); // destructeur
				
				void setFirstName(std::string str);
				void setLastName(std::string str);
				void setNickname(std::string str);
				void setPhoneNumber(int number);
				void setDarkestSecret(std::string str);

				std::string	getFirstName(void) const;
				std::string	getLastName(void) const;
				std::string	getNickname(void) const;
				int		getPhoneNumber(void) const;
				std::string	getDarkestSecret(void) const;
				
				static int	getContactNb(void);
				
	private :
				std::string	_firstName;
				std::string	_lastName;
				std::string	_nickname;
				int			_phoneNumber;
				std::string	_darkestSecret;
				static int	_contactNb; // nb d'instances de contact
	
};

#endif