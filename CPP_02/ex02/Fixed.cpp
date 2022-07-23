/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:50:48 by htizi             #+#    #+#             */
/*   Updated: 2022/03/15 20:05:06 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _RawBits(0)
{
	return ;
}

Fixed::Fixed(Fixed const & src) : _RawBits(0)
{
	*this = src;
	return ;
}

Fixed::Fixed(const int raw)
{
	this->_RawBits =  raw << this->_FractBits;
	// this->_RawBits = raw * 256;
	// this->_RawBits = raw * pow(2, this->_FractBits);
	return ;
}

Fixed::Fixed(const float raw)
{
	this->_RawBits = roundf(raw * (1 << this->_FractBits));
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

int	Fixed::getRawBits(void) const
{
	return (this->_RawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_RawBits = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	return (roundf(this->_RawBits) / (1 << this->_FractBits));
}

int		Fixed::toInt(void) const
{
	return (this->_RawBits >> this->_FractBits);
}

Fixed &		Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->_RawBits = rhs.getRawBits();
	return (*this);
}

std::ostream &		operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

bool		Fixed::operator>(Fixed const &rhs) const
{
	return (this->_RawBits > rhs._RawBits);
}

bool		Fixed::operator<(Fixed const &rhs) const
{
	return (this->_RawBits < rhs._RawBits);
}

bool		Fixed::operator>=(Fixed const &rhs) const
{
	return (this->_RawBits >= rhs._RawBits);
}

bool		Fixed::operator<=(Fixed const &rhs) const
{
	return (this->_RawBits <= rhs._RawBits);
}

bool		Fixed::operator==(Fixed const &rhs) const
{
	return (this->_RawBits == rhs._RawBits);
}

bool		Fixed::operator!=(Fixed const &rhs) const
{
	return (this->_RawBits != rhs._RawBits);
}

Fixed		Fixed::operator+(Fixed const & rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed		Fixed::operator-(Fixed const & rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed		Fixed::operator*(Fixed const & rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed		Fixed::operator/(Fixed const & rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed &		Fixed::operator++(void)
{
	this->_RawBits++;
	return (*this);
}

Fixed &		Fixed::operator--(void)
{
	this->_RawBits--;
	return (*this);
}

Fixed		Fixed::operator++(int)
{
	Fixed	tmp = *this;

	this->_RawBits++;
	return (tmp);
}

Fixed		Fixed::operator--(int)
{
	Fixed	tmp = *this;

	this->_RawBits--;
	return (tmp);
}

Fixed const &	Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed const &	Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed &			Fixed::min(Fixed & a, Fixed & b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed &			Fixed::max(Fixed & a, Fixed & b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
