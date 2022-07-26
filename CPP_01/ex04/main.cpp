/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:25:29 by msanjuan          #+#    #+#             */
/*   Updated: 2022/07/26 20:36:17 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#define SUCCESS 0
#define MSG_USAGE "Correct usage is ./sed <filename> <s1> <s2>"

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		// open the file <filename>
		std::ifstream retrievedFile(argv[1]);

		// stock its contents into a string
		std::ostringstream buffer;
		buffer << retrievedFile.rdbuf();
		std::string contents = buffer.str();
		retrievedFile.close();
		
		// replaces every occurences of s1 in <filename> with s2.
		std::string s1 = argv[2];
		std::string s2 = argv[3];
		int pos;
		
		while (s1.empty() == false 
			&& ((pos = contents.find(s1)) != std::string::npos)) // while you find occurences of s1 in contents
		{
			contents.erase(pos, s1.length()); // erase length of occurence in string
			contents.insert(pos, s2); // insert s2 at pos
		}
		
		// creates a replace file to put the modified content into
		std::string newFilename = argv[1];
		newFilename.append(".replace");
		
		// copies the contents of <filename> into a new file
		std::ofstream newFile(newFilename);
		newFile << contents;
		newFile.close();
	}
	else
		std::cout << MSG_USAGE << std::endl;
	return (SUCCESS);
}