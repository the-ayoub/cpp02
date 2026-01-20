#include "Fixed.hpp"

Fixed::Fixed():_value(0)
{
}
Fixed::Fixed(const Fixed& other)
{
	*this = other;
}
Fixed &Fixed::operator=(const Fixed& other)
{
	if (this != &other)
        this->_value = other._value;
	return *this;
}
Fixed::Fixed( const int value )
{
	this->_value = value << _fractionalBits;
}
Fixed::Fixed( const float value )
{
	this->_value = roundf(value * 256);
}
Fixed::~Fixed()
{
}
Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result._value =this->_value + other._value;
	return result;
}
Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result._value =this->_value - other._value;
	return result;
}
Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	long long temp = ((long long)this->_value * other._value);
	result._value = temp >> _fractionalBits;
	return result;
}
Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	long long temp = (long long)this->_value << _fractionalBits;
	result._value = temp / other._value;
	return result;
}
bool Fixed::operator>(const Fixed& other) const
{
	return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->_value < other._value);
}
bool Fixed::operator>=(const Fixed& other) const
{
	return (this->_value >= other._value);
}
bool Fixed::operator<=(const Fixed& other) const
{
	return (this->_value <= other._value);
}
bool Fixed::operator==(const Fixed& other) const
{
	return (this->_value == other._value);
}
bool Fixed::operator!=(const Fixed& other) const
{
		return (this->_value != other._value);
}
Fixed& Fixed::operator++()
{
	this->_value++;
	return *this;
}
Fixed& Fixed::operator--()
{
	this->_value--;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed temp;
	temp._value = this->_value;
	this->_value++;
	return temp;
}
Fixed Fixed::operator--(int)
{
	Fixed temp;
	temp._value = this->_value;
	this->_value--;
	return temp;
}
Fixed& Fixed::min( Fixed& a, Fixed& b )
{
	return (a < b) ? a : b;
}
const Fixed& Fixed::min( const Fixed& a, const Fixed& b )
{
	return (a < b) ? a : b;
}
Fixed& Fixed::max( Fixed& a, Fixed& b )
{
	return (a > b) ? a : b;
}
const Fixed& Fixed::max( const Fixed& a, const Fixed& b )
{
	return (a > b) ? a : b;
}
int Fixed::toInt( void ) const
{
	return (_value >> _fractionalBits);
} 
float Fixed::toFloat( void ) const
{
	return (_value / 256.0f);
}
std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
	return (o << i.toFloat());
}
