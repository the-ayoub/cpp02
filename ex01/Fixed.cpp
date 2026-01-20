#include "Fixed.hpp"

Fixed::Fixed():_value(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}
Fixed::Fixed(const Fixed& other)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = other;
}
Fixed &Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
        this->_value = other._value;
	return *this;
}

Fixed::Fixed( const int value )
{
	std::cout<<"Int constructor called"<<std::endl;
	this->_value = value << _fractionalBits;
}

Fixed::Fixed( const float value )
{
	std::cout<<"Float constructor called"<<std::endl;
	this->_value = roundf(value * 256);
}
Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
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

int Fixed::getRawBits()const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return this->_value;
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}