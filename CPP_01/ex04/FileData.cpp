/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileData.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:25:13 by afont             #+#    #+#             */
/*   Updated: 2024/08/06 14:50:54 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileData.hpp"

file::file(std::string _fileName, std::string _s1, std::string _s2)
{
	this->fileName = _fileName;
	this->s1 = _s1;
	this->s2 = _s2;
}

file::~file()
{
}

void	file::debugFile()
{
	std::cout << "fileName: " << this->fileName << std::endl;
	std::cout << "s1: " <<this->s1 << std::endl;
	std::cout << "s2: " << this->s2 << std::endl;
}

void	file::replace()
{
	std::ifstream	inputFile(this->fileName.c_str());
	std::string		line;
	std::string		 newLine;
	size_t 			pos = 0;
	
	if (inputFile.is_open())
	{
		if (getline(inputFile, line, '\0'))
		{
			while (!this->s1.empty() && (pos = line.find(this->s1, pos)) != std::string::npos)
			{
				newLine += line.substr(0, pos) + this->s2;
				line = line.substr(pos + this->s1.length());
				pos = 0;
			}
			newLine += line;
			std::ofstream outputFile((this->fileName + ".replace").c_str());
			if (outputFile.is_open())
				outputFile << newLine;
			else
				std::cout << "can't open output file" << std::endl;
		}
		else
			std::cout << "empty file" << std::endl;
	}
	else
		std::cout <<  "can't open input file" << std::endl;
}