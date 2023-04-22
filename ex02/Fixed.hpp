/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgeslin <fgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:22:03 by fgeslin           #+#    #+#             */
/*   Updated: 2023/04/22 16:38:23 by fgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
private:
	int					_n;
	static int const	_frac = 8;

public:
	Fixed( void );									// Canonical		Constructor Default
	Fixed( int const n );
	Fixed( float const f );
	Fixed( Fixed const & src );						// Canonical		Contructor Copy
	~Fixed( void );									// Canonical		Destructor

	Fixed &		operator=( Fixed const & rhs );		// Canonical		Surcharche operator =
	Fixed &		operator+( Fixed const & rhs );
	Fixed &		operator-( Fixed const & rhs );
	Fixed &		operator*( Fixed const & rhs );
	Fixed &		operator/( Fixed const & rhs );

	Fixed &		operator>( Fixed const & rhs );
	Fixed &		operator<( Fixed const & rhs );
	Fixed &		operator>=( Fixed const & rhs );
	Fixed &		operator<=( Fixed const & rhs );
	Fixed &		operator==( Fixed const & rhs );
	Fixed &		operator!=( Fixed const & rhs );

	Fixed &		operator++( int n );	// post
	Fixed &		operator--( int n );	// post
	Fixed &		operator++();	// pre
	Fixed &		operator--();	// pre

	int			getRawBits( void ) const;
	void		setRawBits( int const raw );

	int			toInt( void ) const;
	float		toFloat( void ) const;

	static Fixed&	min( Fixed a, Fixed b );
	static Fixed&	min( Fixed const a, Fixed const b );
	static Fixed&	max( Fixed a, Fixed b );
	static Fixed&	max( Fixed const a, Fixed const b );

};

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs );
