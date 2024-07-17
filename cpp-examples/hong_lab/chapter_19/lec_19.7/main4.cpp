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


int main()
{
    CustomVector my_vec(3,7);
    std::cout<<"===== my_vec ====="<<std::endl;
    my_vec.getData();

    std::cout<<"=========================="<<std::endl;

    CustomVector temp(my_vec);
    std::cout<<"===== temp ====="<<std::endl;
    temp.getData();

    std::cout<<"========= std::move *my_vec* to *moved_obj* ========="<<std::endl;
    CustomVector moved_obj(std::move(my_vec));
    moved_obj.getData();

    std::cout<<"===== my_vec ====="<<std::endl;
    my_vec.getData();
    std::cout<<"===== temp ====="<<std::endl;
    temp.getData();
    std::cout<<"===== moved_obj ====="<<std::endl;
    moved_obj.getData();

    return 0;
}