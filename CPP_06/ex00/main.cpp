/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:31:14 by marine            #+#    #+#             */
/*   Updated: 2022/10/10 11:43:14 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Convert.hpp"

int main(int argc, char** argv) 
{
	if (argc == 2)
	{
		Convert input(argv[1]);

		input.displayConversions();

		return 0;
	}
	else
	{
		std::cerr << "Correct usage is ./convert <litteral>" << std::endl;
		return 1;
	}
}