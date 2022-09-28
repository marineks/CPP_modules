/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:05:44 by marine            #+#    #+#             */
/*   Updated: 2022/09/26 22:10:41 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <string>
#include <iostream>

# define RESET "\033[0m"
# define YELLOW "\033[0;33m"

template <typename T>
void swap(T &a, T &b) 
{
	T tmp_a = a;
	a = b;
	b = tmp_a;
}

template <typename T>
T min(T const &a, T const &b) 
{
	return (a < b) ? a : b;
}

template <typename T>
T max(T const &a, T const &b) 
{
	return (a > b) ? a : b;
}


#endif