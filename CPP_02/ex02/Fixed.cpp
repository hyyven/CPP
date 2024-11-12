/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afont <afont@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:42:09 by afont             #+#    #+#             */
/*   Updated: 2024/04/18 11:54:38 by afont            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_value = 0;
}

Fixed::Fixed(const int value)
{
	this->_value = value << _bits;
}

Fixed::Fixed(const float value)
{
	this->_value = roundf(value * (1 << _bits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed(void)
{
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int	Fixed::toInt(void) const
{
	return (this->_value >> this->_bits);
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << _bits));
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_value = other.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &other) const
{
	if (this->_value > other._value)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &other) const
{
	if (this->_value < other._value)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	if (this->_value >= other._value)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &other) const
{
	if (this->_value <= other._value)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &other) const
{
	if (this->_value == other._value)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &other) const
{
	if (this->_value != other._value)
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed result(this->toFloat() + other.toFloat());
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed result(this->toFloat() - other.toFloat());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed result(this->toFloat() * other.toFloat());
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed result(this->toFloat() / other.toFloat());
	return (result);
}

Fixed	Fixed::operator++(void)
{
	++this->_value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed result(*this);
	result._value = this->_value++;
	return (result);
}

Fixed	Fixed::min(const Fixed &n1, const Fixed &n2)
{
	if (n1._value < n2._value)
		return (n1);
	return (n2);
}

Fixed	Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1._value < n2._value)
		return (n1);
	return (n2);
}

Fixed	Fixed::max(const Fixed &n1, const Fixed &n2)
{
	if (n1._value > n2._value)
		return (n1);
	return (n2);
}

Fixed	Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1._value > n2._value)
		return (n1);
	return (n2);
}

std::ostream& operator<<(std::ostream &output, Fixed const &other)
{
	output << other.toFloat();
	return (output);
}