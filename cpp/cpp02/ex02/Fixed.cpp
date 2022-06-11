#include "Fixed.hpp"
#include <iostream>
#include <math.h>

int const	Fixed::_nbBitsFracPart = 8;

// --- constructor ---
Fixed::Fixed(void) {
	this->_bits = 0;
}

Fixed::Fixed(int const x) {
	this->_bits = x << this->_nbBitsFracPart;
}

Fixed::Fixed(float const f) {
	this->_bits = roundf(f * (1 << this->_nbBitsFracPart));
}

Fixed::Fixed(Fixed const & src) {
	*this = src;
}

// --- destructor ---
Fixed::~Fixed(void) {}

// --- operator ---
Fixed &	Fixed::operator=(Fixed const & ros) {
	this->_bits = ros.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const & ros) {
	Fixed	res;

	res.setRawBits(this->_bits + ros.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(Fixed const & ros) {
	Fixed	res;

	res.setRawBits(this->_bits - ros.getRawBits());
	return (res);
}

// to implement faster mult and div (but with a loss of precision) => https://www.youtube.com/watch?v=npQF28g6s_k
Fixed	Fixed::operator*(Fixed const & ros) {
	Fixed	res;

	res.setRawBits(((long long int)this->_bits * ros.getRawBits()) >> this->_nbBitsFracPart);
	return (res);
}

Fixed	Fixed::operator/(Fixed const & ros) {
	Fixed	res;

	res.setRawBits(((long long int)this->_bits << this->_nbBitsFracPart) / ros.getRawBits());
	return (res);
}

Fixed &	Fixed::operator++(void) {
	this->_bits++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	operator++();
	return (tmp);
}

Fixed &	Fixed::operator--(void) {
	this->_bits--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	operator--();
	return (tmp);
}

bool	Fixed::operator!=(Fixed const & ros) {
	return (this->_bits != ros.getRawBits() ? true : false);
}

bool	Fixed::operator==(Fixed const & ros) {
	return (this->_bits == ros.getRawBits() ? true : false);
}

bool	Fixed::operator<(Fixed const & ros) {
	return (this->_bits < ros.getRawBits() ? true : false);
}

bool	Fixed::operator<=(Fixed const & ros) {
	return (this->_bits <= ros.getRawBits() ? true : false);
}

bool	Fixed::operator>(Fixed const & ros) {
	return (this->_bits > ros.getRawBits() ? true : false);
}

bool	Fixed::operator>=(Fixed const & ros) {
	return (this->_bits >= ros.getRawBits() ? true : false);
}

std::ostream &	operator<<(std::ostream &ostrm, Fixed const & ros) {
	ostrm << ros.toFloat();
	return (ostrm);
}

// --- member functions ---

int	Fixed::getRawBits(void) const {
	return (this->_bits);
}

void	Fixed::setRawBits(int const raw) {
	this->_bits = raw;
}

float 	Fixed::toFloat(void) const {
	return ((float)this->_bits / (1 << this->_nbBitsFracPart));
}

int 	Fixed::toInt(void) const {
	return (this->_bits >> this->_nbBitsFracPart);
}

void	Fixed::showRange(void) const {
	int	nbBitsIntPart = 32 - this->_nbBitsFracPart;
	int min = -(1 << (nbBitsIntPart - 1));
	int max = (1 << (nbBitsIntPart - 1)) - 1;
	std::cout << "Fixed Numbers range is [" << min << " ; " << max << "]\n";
}

Fixed	Fixed::min(Fixed & x1, Fixed & x2) {
	return ((x1 <= x2) ? Fixed(x1) : Fixed(x2));
}

Fixed	Fixed::min(Fixed const & x1, Fixed const & x2) {
	return (((Fixed)x1 <= x2) ? Fixed(x1) : Fixed(x2));
}

Fixed	Fixed::max(Fixed & x1, Fixed & x2) {
	return ((x1 >= x2) ? Fixed(x1) : Fixed(x2));
}

Fixed	Fixed::max(Fixed const & x1, Fixed const & x2) {
	return (((Fixed)x1 >= x2) ? Fixed(x1) : Fixed(x2));
}
