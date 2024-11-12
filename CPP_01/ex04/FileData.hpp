/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileData.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:15:11 by afont             #+#    #+#             */
/*   Updated: 2024/04/12 09:51:34 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>

class	file
{
	private:
		std::string	fileName;
		std::string	s1;
		std::string	s2;
	public:
		file(std::string _fileName, std::string _s1, std::string _s2);
		~file();
		void	debugFile();
		void	replace();
};

#endif