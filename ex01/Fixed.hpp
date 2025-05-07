/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 03:06:43 by aberenge          #+#    #+#             */
/*   Updated: 2025/05/07 16:12:15 by aberenge         ###   ########.fr       */
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

			int		getRawBits(void) const;
			void	setRawBits(int const raw);
			float	toFloat(void) const;
			int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif
