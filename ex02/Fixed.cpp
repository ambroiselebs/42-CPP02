/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberenge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 03:08:41 by aberenge          #+#    #+#             */
/*   Updated: 2025/05/07 16:21:55 by aberenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _value(value << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : _value(roundf(value * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}


Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

Fixed &Fixed::operator+(Fixed const &rhs)
{
	this->_value = (this->toFloat() + rhs.toFloat()) * (1 << _fractionalBits);
	return (*this);
}

Fixed &Fixed::operator-(Fixed const &rhs)
{
	this->_value = (this->toFloat() - rhs.toFloat()) * (1 << _fractionalBits);
	return (*this);
}

Fixed &Fixed::operator*(Fixed const &rhs)
{
	this->_value = (this->toFloat() * rhs.toFloat()) * (1 << _fractionalBits);
	return (*this);
}

Fixed &Fixed::operator/(Fixed const &rhs)
{
	this->_value = (this->toFloat() / rhs.toFloat()) * (1 << _fractionalBits);
	return (*this);
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	return (this->_value > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (this->_value < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (this->_value >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (this->_value <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (this->_value == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (this->_value != rhs.getRawBits());
}

Fixed &Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_value++;
	return (tmp);
}

Fixed &Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_value--;
	return (tmp);
}



Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b ? a : b);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}
