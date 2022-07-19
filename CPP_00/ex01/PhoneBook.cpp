/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:39:20 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/19 16:53:12 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook (void)
{
	std::cout << "☎️ PhoneBook Constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook (void)
{
	std::cout << "💥 PhoneBook Destructor called" << std::endl;
	return ;
}