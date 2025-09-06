#include <fstream>
#include <iostream>

int comparison_func(int i,std::string line,std::string s1)
{
    int count=0;
    while (s1[count]==line[i])
    {
        count++;
        i++;
    }
    if (s1.length()==count)
        return 1;
    return 0;
}

std::string replace_content(std::string line,std::string s1,std::string s2)
{
    std::string newline;

    for (int i=0;line[i];i++)
    {
        if (s1[0]==line[i] && comparison_func(i,line,s1))
        {
            for (int j = 0; s2[j]; j++)
                newline+=s2[j];
            i+=s1.length();
            continue;
        }
        newline+=line[i];
    }
    return newline;
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
    std::ofstream outfile("n.replace");
    std::string s1=argv[2];
    std::string s2=argv[3];
    std::string str="";
    std::string line="";

    while(std::getline(infile,line))
    {
        line=replace_content(line,s1,s2);
        str+=line + "\n";
    }
    outfile << str;
}
