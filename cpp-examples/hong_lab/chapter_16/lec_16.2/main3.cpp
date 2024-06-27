#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

int main()
{
    std::set<int> container;
    for(int i=0;i<10;++i)
    {
        container.insert(i);
    }
    std::set<int>::const_iterator itr;
    itr = container.begin();
    while(itr != container.end())
    {
        std::cout <<*itr <<" ";
        ++itr;
    }
    std::cout <<std::endl;

    for(auto &e : container)
    {
        std::cout<<e<<" ";
    }std::cout<<std::endl;

    for(auto itr = container.begin(); itr!=container.end();++itr)
    {
        std::cout <<*itr <<" ";
    }std::cout<<std::endl;


    return 0;
}