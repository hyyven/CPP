/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 08:35:04 by afont             #+#    #+#             */
/*   Updated: 2024/09/04 16:17:54 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string input) : _input(input)
{
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter ScalarConverter::create(std::string input)
{
	return (ScalarConverter(input));
}

bool	ScalarConverter::isInt(void)
{
	int	i = -1;
	int	cpt = 0;

	while (_input[++i])
		if (_input[i] == '-')
			cpt++;
	if (cpt > 1 || (cpt == 1 && _input[0] != '-'))
		return (false);
	i = -1;
	while (_input[++i])
		if (!isdigit(_input[i]) && _input[i] != '-')
			return (false);
	std::cout << "int" << std::endl;
	return (true);
}

bool	ScalarConverter::isChar(void)
{
	if (_input.length() == 1 && !isdigit(_input[0]) && isprint(_input[0]))
	{
		std::cout << "char" << std::endl;
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isDouble(void)
{
	int	i = -1;
	int	cpt1 = 0, cpt2 = 0;

	while (_input[++i])
	{
		if (_input[i] == '-')
			cpt1++;
		else if (_input[i] == '.')
			cpt2++;
	}
	if (cpt1 > 1 || (cpt1 == 1 && _input[0] != '-')) //check '-'
		return (false);
	if (cpt2 != 1 || (cpt1 == 1 && _input[1] == '.')  || _input[0] == '.' || _input[_input.length() - 1] == '.') //check '.'
		return (false);
	i = -1;
	while (_input[++i])
		if (!isdigit(_input[i]) && _input[i] != '.' && _input[i] != '-')
			return (false);
	std::cout << "double" << std::endl;
	return (true);
}

bool	ScalarConverter::isFloat(void)
{
	int	i = -1, j = 0;
	int	cpt1 = 0, cpt2 = 0, cpt3 = 0;

	while (_input[++i])
	{
		if (_input[i] == '-')
			cpt1++;
		else if (_input[i] == '.')
		{
			j = i;
			cpt2++;
		}
		else if (_input[i] == 'f')
			cpt3++;
	}
	if (cpt1 > 1 || (cpt1 == 1 && _input[0] != '-')) //check '-'
		return (false);
	if (cpt2 != 1 || j == 0 || j == (int)_input.length() || !isdigit(_input[j - 1]) || !isdigit(_input[j + 1])) //check '.'
		return (false);
	if (cpt3 != 1 || _input[_input.length() - 1] != 'f') // chekc 'f'
		return (false);
	i = -1;
	while (_input[++i])
		if (!isdigit(_input[i]) && _input[i] != '.' && _input[i] != '-' && _input[i] != 'f')
			return (false);
	std::cout << "float" << std::endl;
	return (true);
}

int	ScalarConverter::impossible(void)
{
	if (!_input.length()) //empty
	{
		std::cout << "?";
		return (0);
	}
	if (_input == "nan" || _input == "nanf" || _input == "+inf" || _input == "+inff" || _input == "-inf" || _input == "-inff") //nan or inf
		return (1);
	if (isChar())
		return (2);
	if (isInt())
		return (3);
	if (isDouble())
		return (4);
	if(isFloat())
		return (5);
	std::cout << ".";
	return (0);
}

void	ScalarConverter::convert(void)
{
	if (impossible() == 0)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << "!" << std::endl;
}