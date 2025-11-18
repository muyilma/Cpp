#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int number; 
        static const int bitNumber = 8; 
    public:     
        Fixed();
        ~Fixed();
        Fixed(const Fixed &obj);
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed& operator=(const Fixed &copy);
};

#endif
