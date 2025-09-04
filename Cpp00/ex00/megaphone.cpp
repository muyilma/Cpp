#include <iostream> 

int main(int arg, char *argv[])
{
    int i = 0;
    int j ;

    if (arg > 1)
    {
        while (argv[++i])
        {
            j=-1;
            while (argv[i][++j])
                std::cout << (char)std::toupper(argv[i][j]);
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
}
