/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 03:06:43 by aberenge          #+#    #+#             */
/*   Updated: 2025/05/07 16:20:48 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;

		public:
			Fixed(void);
			Fixed(int const value);
			Fixed(float const value);
			Fixed(Fixed const &src);
			~Fixed(void);

			Fixed	&operator=(Fixed const &rhs);
			Fixed	&operator+(Fixed const &rhs);
			Fixed	&operator-(Fixed const &rhs);
			Fixed	&operator*(Fixed const &rhs);
			Fixed	&operator/(Fixed const &rhs);

			bool	operator>(Fixed const &rhs) const;
			bool	operator<(Fixed const &rhs) const;
			bool	operator>=(Fixed const &rhs) const;
			bool	operator<=(Fixed const &rhs) const;
			bool	operator==(Fixed const &rhs) const;
			bool	operator!=(Fixed const &rhs) const;

			Fixed	&operator++(void);
			Fixed	operator++(int);
			Fixed	&operator--(void);
			Fixed	operator--(int);

			static Fixed &max(Fixed &a, Fixed &b);
			static Fixed const &max(Fixed const &a, Fixed const &b);
			static Fixed &min(Fixed &a, Fixed &b);
			static Fixed const &min(Fixed const &a, Fixed const &b);

			int		getRawBits(void) const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif
