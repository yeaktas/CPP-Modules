#include "Fixed.hpp"

//constructors
Fixed::Fixed(){

    this->_raw = 0;
    //std::cout << "Default constucter called" << std::endl;
}
Fixed::~Fixed(){

    //std::cout << "Destructor called." << std::endl;
}
Fixed::Fixed(const int value) {

    //std::cout << "Int constructor called" << std::endl;
    this->setRawBits(value << this->raw_bits);
}
Fixed::Fixed(const float value){

    //std::cout << "Float constructor called" << std::endl;
    this->setRawBits(roundf(value * (1 << raw_bits)));

}

//copy constructor
Fixed::Fixed(const Fixed& copy) {

    //std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

//copy assigment operator 
Fixed& Fixed::operator=(const Fixed& old_raw){

    //std::cout << "Copy assignment operator called" << std::endl;
    setRawBits(old_raw.getRawBits());
    return *this;
}

//toint tofloat
int Fixed::toInt(void) const {

    return(getRawBits() >> raw_bits);
}
float Fixed::toFloat(void) const {

    return ((float)_raw / (1 << raw_bits));
}

//set get
int Fixed::getRawBits(void) const {

    //std::cout << "getRawBits member function called" << std::endl;
    return this->_raw;
}
void Fixed::setRawBits(int const raw){

    this->_raw = raw;
}

//Output overload
std::ostream &operator<<(std::ostream &os, const Fixed &value)
{
	os << value.toFloat();
	return (os);
}

//comparison operator
bool Fixed::operator>(const Fixed &n) const {

    return (this->_raw > n.getRawBits());
}
bool Fixed::operator<(const Fixed &n) const {

    return (this->_raw < n.getRawBits());
}
bool Fixed::operator>=(const Fixed &n) const {

    return (this->_raw >= n.getRawBits());
}
bool Fixed::operator<=(const Fixed &n) const {

    return (this->_raw <= n.getRawBits());
}
bool Fixed::operator==(const Fixed &n) const {

    return (this->_raw == n.getRawBits());
}
bool Fixed::operator!=(const Fixed &n) const {

    return (this->_raw != n.getRawBits());
}

//aritmethic operators
Fixed Fixed::operator+(const Fixed &n)  const {

    return(Fixed(this->toFloat() + n.toFloat()));
}
Fixed Fixed::operator-(const Fixed &n) const {

    return(Fixed(this->toFloat() - n.toFloat()));
}
Fixed Fixed::operator*(const Fixed &n) const {

    return(Fixed(this->toFloat() * n.toFloat()));
}
Fixed Fixed::operator/(const Fixed &n) const {

    return(Fixed(this->toFloat() / n.toFloat()));
}

//Increment - Decrament
Fixed& Fixed::operator++() {
	//++a
	_raw++;
	return *this;
}
Fixed Fixed::operator++(int) {
	//increment after copy
	//a++
	Fixed pos(*this);// copy
	_raw++;
	return pos;
}
Fixed& Fixed::operator--() {
	//--a
	_raw--;
	return *this;
}
Fixed Fixed::operator--(int) {
	//a--
	Fixed neg(*this);
	_raw--;
	return neg;
}

//Max-Min value func
Fixed& Fixed::min(Fixed &s1, Fixed &s2) {
	if(s1.getRawBits() < s2.getRawBits())
		return s1;
	return s2;
}
const Fixed& Fixed::min(const Fixed &s1, const Fixed &s2){
	if(s1.getRawBits() < s2.getRawBits())
		return s1;
	return s2;
}
Fixed &Fixed::max(Fixed &s1, Fixed &s2){
	if(s1.getRawBits() > s2.getRawBits())
		return s1;
	return s2;
}
const Fixed& Fixed::max(const Fixed &s1, const Fixed &s2) {
	if(s1.getRawBits() > s2.getRawBits())
		return s1;
	return s2;
}