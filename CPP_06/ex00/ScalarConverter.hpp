/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 08:35:03 by afont             #+#    #+#             */
/*   Updated: 2024/09/04 08:25:44 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	private:
		std::string	_input;
		char		_char;
		int			_int;
		float		_float;
		double		_double;
		ScalarConverter(std::string input);
	public:
		~ScalarConverter(void);
		static ScalarConverter	create(std::string input);
		void					convert(void);
		int						impossible(void);
		bool					isInt(void);
		bool					isFloat(void);
		bool					isDouble(void);
		bool					isChar(void);
};

#endif