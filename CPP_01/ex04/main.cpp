/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:25:29 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/26 17:50:40 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

#define SUCCESS 0
#define MSG_USAGE "Correct usage is ./sed <filename> <s1> <s2>"
int main(int argc, char **argv)
{
	if (argc == 4)
	{
		// open the file <filename>
		std::ifstream retrievedFile(argv[1]);

		// stock the contents into a string
		std::string contents;
		retrievedFile >> contents;
		std::cout << contents << std::endl;
		
		// creates a replace file
		std::string newFilename = argv[1];
		newFilename.append(".replace");
		std::cout << "new filename: " << newFilename << std::endl;
		
		// replaces every occurences of s1 in <filename> with s2.
		std::cout << "s1 is " << argv[2] << std::endl;
		std::cout << "s2 is " << argv[3] << std::endl;
		
		while (contents.find(s1) != std::string::npos) // while you find occurences of s1 in contents
		{
			
		}
		// copies the contents of <filename> into a new file
		
		
		retrievedFile.close();
	}
	else
		std::cout << MSG_USAGE << std::endl;
	return (SUCCESS);
}