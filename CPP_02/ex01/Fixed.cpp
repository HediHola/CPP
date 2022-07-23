/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:50:48 by htizi             #+#    #+#             */
/*   Updated: 2022/03/13 22:07:50 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _RawBits(0)
{
	std::cout << "Default constructor called\n";
	return ;
}

Fixed::Fixed(Fixed const & src) : _RawBits(0)
{
	std::cout << "Copy constructor called\n";
	*this = src;
	return ;
}

Fixed::Fixed(const int raw)
{
	std::cout << "Int constructor called\n";
	this->_RawBits =  raw << this->_FractBits;
	// this->_RawBits = raw * 256;
	// this->_RawBits = raw * pow(2, this->_FractBits);
	return ;
}

Fixed::Fixed(const float raw)
{
	std::cout << "Float constructor called\n";
	this->_RawBits = roundf(raw * (1 << this->_FractBits));
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
	return ;
}

int	Fixed::getRawBits(void) const
{
	return (this->_RawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
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
	std::cout << "Copy assignment operator called\n";
	if (this != &rhs)
		this->_RawBits = rhs.getRawBits();
	return (*this);
}

std::ostream &		operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
