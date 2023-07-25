#include "Fixed.hpp"


Fixed::Fixed(){

    this->_raw = 0;
    std::cout << "Default constucter called" << std::endl;
}

Fixed::~Fixed(){

    std::cout << "Destructor called." << std::endl;
}

Fixed::Fixed(const int value) {

    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(value << this->raw_bits);
}

Fixed::Fixed(const float value){

    std::cout << "Float constructor called" << std::endl;
    this->setRawBits(roundf(value * (1 << raw_bits)));

}

int Fixed::toInt(void) const {

    return(getRawBits() >> raw_bits);
}

float Fixed::toFloat(void) const {

    return ((float)_raw / (1 << raw_bits));
}

int Fixed::getRawBits(void) const {

    //std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}

void Fixed::setRawBits(int const raw){

    this->_raw = raw;
}

Fixed::Fixed(const Fixed& copy) {

    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed& old_raw){

    std::cout << "Copy assignment operator called" << std::endl;
    setRawBits(old_raw.getRawBits());
    return *this;
}

//Output overload
std::ostream &operator<<(std::ostream &os, const Fixed &value)
{
	os << value.toFloat();
	return (os);
}