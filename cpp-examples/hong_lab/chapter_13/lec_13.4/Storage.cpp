#include "Storage2.h"
//double 타입에 대한 템플릿 멤버함수의 특수화
template<>
void Storage<double>::print()
{
    std::cout <<"헤더와 cpp파일 분리" << std::endl;
    std::cout <<"Double Type "<<std::endl;
    std::cout <<std::scientific << m_value<<'\n';
}