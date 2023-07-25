#pragma once

#include <iostream>
#include <cmath>

class Fixed {

    private:
        int _raw;
        static const int raw_bits = 8;

    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed& copy);
        ~Fixed();

        //assigment oporator
        Fixed& operator=(const Fixed& copy);

        //comparison operators
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        //aritmethic operators
        Fixed operator+(const Fixed &other) const;
	    Fixed operator-(const Fixed &other) const;
	    Fixed operator*(const Fixed &other) const;
	    Fixed operator/(const Fixed &other) const;

        Fixed& operator++();
	    Fixed operator++(int);
	    Fixed& operator--();
	    Fixed operator--(int);

        //Max-Min function
	    static Fixed& min(Fixed &s1, Fixed &s2);
	    static Fixed& max(Fixed &s1, Fixed &s2);
	    static const Fixed& min(const Fixed &s1, const Fixed &s2);
	    static const Fixed& max(const Fixed &s1, const Fixed &s2);

        float toFloat(void) const;
        int toInt(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
        
};

std::ostream &operator<<(std::ostream &os, const Fixed &other);