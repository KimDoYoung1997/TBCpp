#include <iostream>
#include <vector>
#include <utility>  // std::forward
#include <cstdio>

using namespace std;

class CustomVector
{
public:
    unsigned n_data = 0;
    int *ptr = nullptr;
    CustomVector(const unsigned& _n_data, const int& _init=0)
    {
        std::cout <<"Constructor"<<std::endl;
        init(_n_data,_init);
    }
    CustomVector(CustomVector & l_input)
    {
        std::cout<<"Copy Constructor"<<std::endl;
        init(l_input.n_data);
        for(unsigned i=0; i<n_data;++i)
        {
            ptr[i]=l_input.ptr[i];
        }
    }
    CustomVector(CustomVector && r_input)
    {
        std::cout<<"Move Constructor"<<std::endl;
        n_data = r_input.n_data;
        ptr = r_input.ptr;
        
        r_input.n_data=0;
        r_input.ptr=nullptr;
    }


    void init(const unsigned& _n_data, const int& _init=0)
    {
        n_data=_n_data;
        ptr = new int[n_data];
        for(unsigned i=0;i<n_data;i++)
        {
            ptr[i]=_init;
        }
    }
    void getData()
    {
        for(unsigned i=0;i<n_data;i++)
        {
            std::cout<<ptr[i]<<std::endl;
        }
    }

    ~CustomVector()
    {
        delete[] ptr;
        std::cout<<"Memory deallocation"<<std::endl;
    }
};

void doSomething(CustomVector &vec)
{
    std::cout<<"Pass by L-reference"<<std::endl;
    CustomVector new_vec(vec);
}
void doSomething(CustomVector &&vec)
{
    std::cout<<"Pass by R-reference"<<std::endl;
    // CustomVector new_vec(vec);
    CustomVector new_vec(std::move(vec));   // Note! : vec itself is L-value!

}

int main()
{
    CustomVector my_vec(10,1024);
    CustomVector my_vec2(10,2048);

    doSomething(my_vec);                // L-value 전달
    // my_vec.getData();
    doSomething(std::move(my_vec2));    // R-value 전달
    // my_vec2.getData();
    doSomething(CustomVector(10,512));  // R-value 전달

    return 0;
}