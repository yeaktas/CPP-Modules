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
        Fixed& operator=(const Fixed& copy);
        ~Fixed();

        float toFloat(void) const;
        int toInt(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);
        
};

std::ostream &operator<<(std::ostream &os, const Fixed &other);