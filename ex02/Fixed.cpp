/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:22:09 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/22 16:44:38 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed( void ) : _n(0) {}
Fixed::Fixed( int const n ) : _n(n << _frac) {}
Fixed::Fixed( float const f ) : _n(roundf(f * (1 << _frac))) {}
Fixed::Fixed( Fixed const & src ) { *this = src; }
Fixed::~Fixed( void ) {}


int		Fixed::getRawBits( void ) const { return _n; }
void	Fixed::setRawBits( int const raw ) { _n = raw; }

int		Fixed::toInt( void ) const { return _n >> _frac; }
float	Fixed::toFloat( void ) const { return (float)_n / (1 << _frac); }

Fixed&	Fixed::min( Fixed a, Fixed b ) {}
Fixed&	Fixed::min( Fixed const a, Fixed const b ) {}
Fixed&	Fixed::max( Fixed a, Fixed b ) {}
Fixed&	Fixed::max( Fixed const a, Fixed const b ) {}


Fixed &			Fixed::operator=( Fixed const & rhs ) { return (this->_n = rhs.getRawBits(), *this); }
Fixed &			Fixed::operator+( Fixed const & rhs ) { return Fixed(this->toFloat() + rhs.toFloat()); }
Fixed &			Fixed::operator-( Fixed const & rhs ) { return Fixed(this->toFloat() - rhs.toFloat()); }
Fixed &			Fixed::operator*( Fixed const & rhs ) { return Fixed(this->toFloat() * rhs.toFloat()); }
Fixed &			Fixed::operator/( Fixed const & rhs ) { return Fixed(this->toFloat() / rhs.toFloat()); }

Fixed &			Fixed::operator>( Fixed const & rhs ) {}
Fixed &			Fixed::operator<( Fixed const & rhs ) {}
Fixed &			Fixed::operator>=( Fixed const & rhs ) {}
Fixed &			Fixed::operator<=( Fixed const & rhs ) {}
Fixed &			Fixed::operator==( Fixed const & rhs ) {}
Fixed &			Fixed::operator!=( Fixed const & rhs ) {}

Fixed &			Fixed::operator++( int n ) {}
Fixed &			Fixed::operator--( int n ) {}
Fixed &			Fixed::operator++() {}
Fixed &			Fixed::operator--() {}

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs ) { return (o << rhs.toFloat(), o); }
