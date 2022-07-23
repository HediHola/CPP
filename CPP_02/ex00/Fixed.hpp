/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:32:51 by htizi             #+#    #+#             */
/*   Updated: 2022/03/12 19:02:00 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

class	Fixed
{
	public :
		Fixed(void);
		Fixed(Fixed const &);
		~Fixed(void);
		Fixed &		operator=(Fixed const & rhs); //surcharge de l'operateur d'affection
		int			getRawBits(void) const;
		void		setRawBits(int const raw);

	private :
		int					_RawBits;
		static int const	_FractBits = 8;
};

#endif
