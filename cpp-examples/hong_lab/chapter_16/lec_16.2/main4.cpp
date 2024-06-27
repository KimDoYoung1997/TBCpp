#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

int main()
{
    std::map<int,char> container;
    for(int i=0;i<10;++i)
    {
        container.insert(std::make_pair(i,char(i+65)));
    }
    std::map<int,char>::const_iterator _itr;
    _itr = container.begin();
    while(_itr != container.end())
    {
        std::cout <<_itr->first <<" "<<_itr->second<<" ";
        ++_itr;
    }
    std::cout <<std::endl;

    for(auto &e : container)
    {
        std::cout<<e.first<<" "<<e.second<<" ";
    }std::cout<<std::endl;

    for(auto itr = container.begin(); itr!=container.end();++itr)
    {
        std::cout <<itr->first <<" "<<itr->second<<" ";
    }std::cout<<std::endl;


    return 0;
}