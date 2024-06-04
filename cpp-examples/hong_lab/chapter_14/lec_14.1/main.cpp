#include <bits/c++config.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int findFirstChar(const char* string, char ch)
{
    for(std::size_t index =0; index < strlen(string); ++index)
    {
        if(string[index]==ch)
        {
            std::cout <<"find! : "<<ch <<std::endl;
            return index;
        }
    }

    return -1;
}

double divide(int x , int y , bool &success)
{
    if (y == 0)
    {
        success = false;
        return 0.0;
    }
    success = true;
    return static_cast<double>(x) / y ;
}

int main()
{
    std::cout << findFirstChar("const char *string", 'x') <<std::endl;
    std::cout << findFirstChar("const char *string x", 'x') <<std::endl;
    
    std::cout <<"=========================================" <<std::endl;
    bool flag = false;
    double divide_return=divide(3, 2, flag);
    if (flag == true) std::cout <<divide_return << std::endl;
    if (flag != true) std::cerr <<"An error occured!" << std::endl;

    std::cout <<"=========================================" <<std::endl;
    flag = false;
    divide_return=divide(3, 0, flag);
    if (flag == true) std::cout <<divide_return << std::endl;
    else  std::cerr <<"An error occured!" << std::endl;

    std::ifstream input_file("temp.txt");
    if(!input_file)
        std::cerr << "Cannot open file" << endl;



    return 0;
}