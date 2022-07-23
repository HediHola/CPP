/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:32:51 by htizi             #+#    #+#             */
/*   Updated: 2022/03/15 19:48:46 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class	Fixed
{
	public :
		Fixed(void);
		Fixed(Fixed const &);
		Fixed(const int);
		Fixed(const float);
		~Fixed(void);
		
		Fixed &		operator=(Fixed const & rhs);
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;

		bool		operator>(Fixed const &rhs) const;
		bool		operator<(Fixed const & rhs) const;
		bool		operator>=(Fixed const & rhs) const;
		bool		operator<=(Fixed const & rhs) const;
		bool		operator==(Fixed const & rhs) const;
		bool		operator!=(Fixed const & rhs) const;

		Fixed		operator+(Fixed const & rhs) const;
		Fixed		operator-(Fixed const & rhs) const;
		Fixed		operator*(Fixed const & rhs) const;
		Fixed		operator/(Fixed const & rhs) const;

		Fixed &		operator++(void);
		Fixed &		operator--(void);
		Fixed		operator++(int);
		Fixed		operator--(int);

		static Fixed const &	min(Fixed const & a, Fixed const & b);
		static Fixed const &	max(Fixed const & a, Fixed const & b);
		static Fixed &			min(Fixed & a, Fixed & b);
		static Fixed &			max(Fixed & a, Fixed & b);


	private :
		int					_RawBits;
		static int const	_FractBits = 8;
};

std::ostream &		operator<<(std::ostream & o, Fixed const & rhs);

#endif
