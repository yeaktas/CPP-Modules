#include "Fixed.hpp"


Fixed::Fixed(){

    this->_raw = 0;
    std::cout << "Default constucter called" << std::endl;
}

Fixed::~Fixed(){

    std::cout << "Destructor called." << std::endl;
}

int Fixed::getRawBits(void) const {

    std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}

void Fixed::setRawBits(int const raw){

    this->_raw = raw;
}

Fixed::Fixed(const Fixed& old_raw) {

    std::cout << "Copy constructor called" << std::endl;
    *this = old_raw;
}

Fixed& Fixed::operator=(const Fixed& old_raw){

    std::cout << "Copy assignment operator called" << std::endl;
    setRawBits(old_raw.getRawBits());
    return *this;
}

