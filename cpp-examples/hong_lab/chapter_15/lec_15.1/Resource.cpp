#include <iostream>
#include "include/Resource.h"
using namespace std;


Resource::Resource()
{
    std::cout <<"Resource constructed" << std::endl;
}

Resource::~Resource()
{
    std::cout <<"Resource destructed" << std::endl;
}