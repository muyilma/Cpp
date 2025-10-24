#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
    private:
        int number; 
        static const int bitNumber=8; 
    public:
        Fixed();
        ~Fixed();
        Fixed(Fixed &obj);//const koymadım referans değilde pointer yapabilir miydim?
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed& operator=(Fixed& copy);
};

#endif