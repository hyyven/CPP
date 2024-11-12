/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:46:13 by afont             #+#    #+#             */
/*   Updated: 2024/04/18 11:56:07 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					_value;
		static const int	_bits = 8;
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &other);
		~Fixed();
		int				getRawBits(void) const;
		int				toInt(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		bool			operator>(const Fixed &other) const;
		bool			operator<(const Fixed &other) const;
		bool			operator>=(const Fixed &other) const;
		bool			operator<=(const Fixed &other) const;
		bool			operator==(const Fixed &other) const;
		bool			operator!=(const Fixed &other) const;
		Fixed			&operator=(const Fixed &other);
		Fixed			operator+(const Fixed &other) const;
		Fixed			operator-(const Fixed &other) const;
		Fixed			operator*(const Fixed &other) const;
		Fixed			operator/(const Fixed &other) const;
		Fixed			operator++(int);
		Fixed			operator++(void);
		static Fixed	min(const Fixed &n1, const Fixed &n2);
		static Fixed	min(Fixed &n1, Fixed &n2);
		static Fixed	max(const Fixed &n1, const Fixed &n2);
		static Fixed	max(Fixed &n1, Fixed &n2);
};

std::ostream&	operator<<(std::ostream &ouput, Fixed const &other);

#endif