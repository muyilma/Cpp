#ifndef FIXED
#define FIXED
#include <iostream>
class Fixed
{
    private:
        int number; 
        static const int bitNumber=8; 
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &obj);//const koymadım referans değilde pointer yapabilir miydim?
        Fixed(const int number);
        Fixed(const float number);
        
        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed& operator=(const Fixed& copy);  
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif