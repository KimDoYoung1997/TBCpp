#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
int main()
{
    std::list<int> container;
    for(int i=0;i<10;++i)
    {
        container.push_back(i);
    }
    std::list<int>::const_iterator itr; 

std::cout<<"====== min_element ======"<<std::endl;
    itr = std::min_element(container.begin(),container.end());
    std::cout <<*itr<<std::endl;

std::cout<<"====== max_element ======"<<std::endl;
    itr = std::max_element(container.begin(),container.end());
    std::cout <<*itr<<std::endl;

std::cout<<"====== find and insert ======"<<std::endl;
    itr = std::find(container.begin(),container.end(),3);
    std::cout <<*itr<<std::endl;
    container.insert(itr,128);
    for (auto &e: container)
    {
        std::cout<<e<<" ";
    }std::cout<<std::endl;

std::cout<<"====== sort ======"<<std::endl;
    container.sort();
    for (auto &e: container)
    {
        std::cout<<e<<" ";
    }std::cout<<std::endl;
    
std::cout<<"====== reverse ======"<<std::endl;
    container.reverse();
    for (auto &e: container)
    {
        std::cout<<e<<" ";
    }std::cout<<std::endl;


}