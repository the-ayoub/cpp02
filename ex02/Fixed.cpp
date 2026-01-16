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
	this->_value = value << 8;
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
	result._value = temp >> 8;
	return result;
}
Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	long long temp = (long long)this->_value << 8;
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
	return (_value >> 8);
} 
float Fixed::toFloat( void ) const
{
	return (_value / 256.0f);
}
std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
	return (o << i.toFloat());
}
