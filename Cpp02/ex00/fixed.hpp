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
        Fixed(Fixed &obj);//const koymadım referans değilde pointer yapabilir miydim?evet yapabilirim *  const koyunca klasik iste sadece objemi koyalamak için kullanabiliyor başka bir şey yapamıyor. referans koymassan loopa girer
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        void operator=(Fixed &copy);
};

#endif
