#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main()
{
    std::string my_string("my_string");     // Default construct
    // const char* my_string("my_string");  // C-style도 마찬가지로 작동
    std::string string_1(my_string);   // Copy construct
    std::string string_2(my_string,3);   // Copy construct , option1 
    std::string string_3(my_string,3,2);   // Copy construct ,option1 , option2

    std::cout << my_string<<std::endl;
    std::cout << string_1<<std::endl;
    std::cout << string_2<<std::endl;
    std::cout << string_3<<std::endl;

    std::cout <<"============================"<<std::endl;

    std::string second_string(10,'A');
    std::cout <<second_string<<std::endl;

    std::cout <<"============================"<<std::endl;

    std::vector<char> vec;
    for(auto e :"Today is a good day.")
    {
        vec.push_back(e);
    }
    std::string third_string(vec.begin(),vec.end());
    std::cout << third_string<<std::endl;
    
    std::cout <<"============================"<<std::endl;

    std::vector<char> vec2;
    for(auto e :"Today is a bad day.")
    {
        vec2.push_back(e);
    }
    std::string fourth_string(vec2.begin(),std::find(vec2.begin(),vec2.end(),'d'));
    std::cout << fourth_string<<std::endl;

    std::cout <<"============================"<<std::endl;

    std::string fifth_string(std::to_string(1004));
    std::cout <<"STRING "<< fifth_string<<std::endl;
    int i = std::stoi(fifth_string);
    std::cout <<"INT "<<i<<std::endl;

    float f = std::stof(fifth_string);
    std::cout <<"FLOAT "<<f<<std::endl;

    double d = std::stod(fifth_string);
    std::cout <<"DOUBLE "<<d<<std::endl;

    std::cout <<"============================"<<std::endl;

    return 0;
}