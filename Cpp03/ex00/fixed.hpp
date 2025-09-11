#ifndef FIXED
#define FIXED

class Fixed
{
    private:
        int number; 
        static const int bitNumber=8; 
    public:
        Fixed();
        Fixed(Fixed &obj);//const koymadım referans değilde pointer yapabilir miydim?
        Fixed& operator=(Fixed& copy);

        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif