/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marine <marine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:22:16 by marine            #+#    #+#             */
/*   Updated: 2022/09/26 19:50:26 by marine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <cstdlib>
#include <iostream>
#include <ctime>

class Base {

	public:
			virtual ~Base(void);
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif