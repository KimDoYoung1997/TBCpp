#include <iostream>
#include "include/AutoPtr.h"
#include "include/Resource.h"
#include "include/MySwap.h"

int main()
{
    using namespace std;
    AutoPtr<Resource> res1(new Resource(3));
    res1->setAll(3);        //AutoPtr클래스에서 ->연산자 오버로딩 했기때문에 setAll함수에 -> 를 이용해서 접근이 가능함

    AutoPtr<Resource> res2(new Resource(5));
    res2->setAll(5);
    res1->print();    res2->print();

    MySwap(res1,res2);
    res1->print();    res2->print();

    return 0;
}
