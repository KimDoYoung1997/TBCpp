#include <iostream>
void my_function(int i=1)
{
    std::cout<<"hello"<<std::endl;
    
}

int main()
{
    //void my_void;
    int i = 123;
    float f = 123.456f;
    my_function(1);
    //void *my_void;
    //my_void = (void*)&i; // Integer variable address
    //my_void = (void*)&f; // float variable address
}