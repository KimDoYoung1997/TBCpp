#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int findFirstChar(const char* string, char ch) // string 은 배열
{
    for (std::size_t index = 0; index < strlen(string); ++index)
    {
        if (string[index]==ch)
            return index;
    }

    return -1;  //이러한 경우 no match
}

double divide(int x , int y , bool &success)
{
    if (y==0)
    {
        success = false;
        return 0.0;
    }
    
    success = true;
    return static_cast<double>(x)/y;
}

int main()
{
    bool success;
    double result = divide(5, 3,success);

    if(!success)
        std::cerr << "An error occured!" << std::endl;
    else
        std::cout <<"Result is " << result << std::endl;

    std::ifstream input_file("temp.txt");
    if(!input_file)
        std::cerr << "Cannot open file" << endl;

    return 0;
}