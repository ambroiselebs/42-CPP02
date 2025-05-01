/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 03:06:43 by aberenge          #+#    #+#             */
/*   Updated: 2025/05/01 03:08:35 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;

		public:
			Fixed(void);
			Fixed(Fixed const &src);
			~Fixed(void);

			Fixed	&operator=(Fixed const &rhs);

			int		getRawBits(void) const;
			void	setRawBits(int const raw);
};

#endif
