#pragma once


#include <iostream>


class Fixed {

    private:
        int _raw;
        static const int raw_bits = 8;

    public:
        Fixed();
        Fixed(const Fixed& old_raw);
        Fixed& operator=(const Fixed& old_raw);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);

        
};