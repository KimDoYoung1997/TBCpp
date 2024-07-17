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
    // CustomVector new_vec(vec);           // Note! : vec itself is L-value! , L-value called. unintentional result occured. 
    CustomVector new_vec(std::move(vec));   // Note! : vec itself is L-value!
}

template<typename T>
void doSomethingTemplate(T &&vec)
{
    std::cout<<"doSomethingTemplate"<<std::endl;
    // doSomething(vec);   // unintentional result occured!
    doSomething(std::forward<T>(vec));

}

int main()
{
    CustomVector my_vec(10,1024);
    std::cout<<"============= doSomethingTemplate ============="<<std::endl;
    doSomethingTemplate(CustomVector(10,1024));
    doSomethingTemplate(my_vec);

    my_vec; // my_vec 을 다시 사용할 의지가 있다고 상정. 이 경우 R-value전달하면 안 됨. 값을 빼앗겨버림. 
    return 0;
}