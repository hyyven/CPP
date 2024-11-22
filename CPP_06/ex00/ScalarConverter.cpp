/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 08:35:04 by afont             #+#    #+#             */
/*   Updated: 2024/11/21 11:53:21 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}

static bool	isInt(std::string input)
{
	int	i = -1;
	int	cpt = 0;

	while (input[++i])
		if (input[i] == '-')
			cpt++;
	if (cpt > 1 || (cpt == 1 && input[0] != '-'))
		return (false);
	i = -1;
	while (input[++i])
		if (!isdigit(input[i]) && input[i] != '-')
			return (false);
	if (strtold(input.c_str(), 0) > INT_MAX || strtold(input.c_str(), 0) < INT_MIN)
		return (false);
	return (true);
}

static bool	isChar(std::string input)
{
	if (input.length() == 1 && !isdigit(input[0]) && isprint(input[0]))
		return (true);
	return (false);
}

static bool	isDouble(std::string input)
{
	int	i = -1;
	int	cpt1 = 0, cpt2 = 0;

	while (input[++i])
	{
		if (input[i] == '-')
			cpt1++;
		else if (input[i] == '.')
			cpt2++;
	}
	if (cpt1 > 1 || (cpt1 == 1 && input[0] != '-')) //check '-'
		return (false);
	if (cpt2 != 1 || (cpt1 == 1 && input[1] == '.')  || input[0] == '.' || input[input.length() - 1] == '.') //check '.'
		return (false);
	i = -1;
	while (input[++i])
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != '-')
			return (false);
	if (strtold(input.c_str(), 0) > DBL_MAX || strtold(input.c_str(), 0) < DBL_MIN)
		return (false);
	return (true);
}

static bool	isFloat(std::string input)
{
	int	i = -1, j = 0;
	int	cpt1 = 0, cpt2 = 0, cpt3 = 0;

	while (input[++i])
	{
		if (input[i] == '-')
			cpt1++;
		else if (input[i] == '.')
		{
			j = i;
			cpt2++;
		}
		else if (input[i] == 'f')
			cpt3++;
	}
	if (cpt1 > 1 || (cpt1 == 1 && input[0] != '-')) //check '-'
		return (false);
	if (cpt2 != 1 || j == 0 || j == (int)input.length() || !isdigit(input[j - 1]) || !isdigit(input[j + 1])) //check '.'
		return (false);
	if (cpt3 != 1 || input[input.length() - 1] != 'f') // chekc 'f'
		return (false);
	i = -1;
	while (input[++i])
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != '-' && input[i] != 'f')
			return (false);
	if (strtold(input.c_str(), 0) > FLT_MAX || strtold(input.c_str(), 0) < FLT_MIN)
		return (false);
	return (true);
}

static int	impossible(std::string input)
{
	if (!input.length()) //empty
	{
		std::cout << "?";
		return (0);
	}
	if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff") //nan or inf
		return (1);
	if (isChar(input))
		return (2);
	if (isInt(input))
		return (3);
	if (isDouble(input))
		return (4);
	if(isFloat(input))
		return (5);
	return (0);
}

static void	display(char c, std::string i, std::string f, std::string d)
{
	// char
	if (c && isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else if (c && !isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	// int
	if (!i.empty())
		std::cout << "int: " << atoi(i.c_str()) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	// float
	if (!f.empty())
		std::cout << "float: " << std::fixed << std::setprecision(1) << atof(f.c_str()) << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	// double
	if (!d.empty())
		std::cout << "double: " << atof(d.c_str()) << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}

void	ScalarConverter::convert(std::string input)
{
	int	type = impossible(input);
	if (!type)
		std::cout << "impossible" << std::endl;
	if (type == 1)
		display(0, "", input, input);
	if (type == 2)
	{
		std::stringstream ss;
		ss << (int)(input[0]);
		display(input[0], ss.str(), ss.str(), ss.str());
	}
	if (type == 3 || type == 4 || type == 5)
		display(atoi(input.c_str()), input, input, input);
}
