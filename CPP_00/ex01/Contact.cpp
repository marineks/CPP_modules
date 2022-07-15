/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:47:27 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/15 16:15:30 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

Contact::Contact (void)
{
	std::cout << "Contact Constructor called" << std::endl;
	Contact::_contactNb += 1;
	return ;
}

Contact::~Contact (void)
{
	std::cout << "Contact Destructor called" << std::endl;
	Contact::_contactNb -= 1;
	return ;
}

int	Contact::getContactNb(void)
{
	return (Contact::_contactNb);
}

int Contact::_contactNb = 0;