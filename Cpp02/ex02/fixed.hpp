    #ifndef FIXED_HPP
#define FIXED_HPP

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
        
        bool operator>(const Fixed& copy) const;  
        bool operator<(const Fixed& copy) const;  
        bool operator>=(const Fixed& copy) const;  
        bool operator<=(const Fixed& copy) const;  
        bool operator==(const Fixed& copy) const;  
        bool operator!=(const Fixed& copy) const;  
        Fixed operator+(const Fixed& copy);  
        Fixed operator-(const Fixed& copy);  
        Fixed operator*(const Fixed& copy);  
        Fixed operator/(const Fixed& copy);  
        Fixed operator++(int);
	    Fixed operator--(int);
	    Fixed& operator++();
    	Fixed& operator--();
        static Fixed& min(Fixed& a, Fixed& b);
	    static Fixed& max(Fixed& a, Fixed& b);
	    static const Fixed& min(const Fixed& a, const Fixed& b);
	    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif