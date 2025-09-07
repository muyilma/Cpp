#include <iostream>
#include <string>
#include <fstream>

std::string replace_content(std::string line,std::string s1,std::string s2)
{
    int i=0;

    while ((i=line.find(s1,i))!= std::string::npos)
    {
        line=line.substr(0,i)+s2+line.substr(i+s1.length(),line.length());
        i+=s1.length();
    }
    return line;
}

int main(int argc, char const *argv[])
{
    if (argc!=4)
    {
        std::cout << "Wrong argumant count!!!" << std::endl;
        return 0;
    }
    std::ifstream infile(argv[1]);
    std::string replace=argv[1];
    replace+=".replace";
    std::ofstream outfile(replace.c_str());
    std::string s1=argv[2];
    std::string s2=argv[3];
    std::string line="";
    if (!infile)
        return 1;
    if (s2.empty() || s1.empty())
        return 1;
    while(std::getline(infile,line))
    {
        line=replace_content(line,s1,s2);
        outfile << line + "\n";
    }
}
