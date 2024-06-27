#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>  //string stream의 약어

template <typename T>
std::string ToString(T x)   // 무슨 타입이 들어오건(템플릿 인자), string 을 return 해줌
{
    std::ostringstream osstream;
    osstream  <<x ;
    return osstream.str();
}

template <typename T>
bool FromString(const std::string& str, T&x) 
{
    std::istringstream isstream(str);
    return (isstream >> x) ? true : false;
}
int main()
{
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
    std::cout <<"============================"<<std::endl;

    std::string sixth_string(ToString(1004));
    std::cout <<"ToString "<< sixth_string<<std::endl;
    std::cout <<"============================"<<std::endl;

    std::cout <<"============================"<<std::endl;

    std::string seventh_string(ToString(1004));
    int ii = 2004;
    std::cout << ii << std::endl;
    if (FromString(seventh_string,ii))
    {
        std::cout << ii << std::endl;
    }
    else
        std::cout <<"Can't convert string to num"<<std::endl;

    std::cout <<"============================"<<std::endl;
    std::cout <<"============================"<<std::endl;

    std::string eigth_string("HELLO");
    int iii = 3004;
    std::cout << iii << std::endl;
    if (FromString(eigth_string,iii))
    {
        std::cout << iii << std::endl;
    }
    else
        std::cout <<"Can't convert string to num"<<std::endl;

    std::cout <<"============================"<<std::endl;
    return 0;
}