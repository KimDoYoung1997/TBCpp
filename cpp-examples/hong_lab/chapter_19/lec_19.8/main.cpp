#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>

class Examples
{
public:
    void ex1()
    {
        std::vector<int> vect{1,2,3,4,5};
        for(std::vector<int>::iterator itr=vect.begin();itr!=vect.end();++itr)
        {
            std::cout<<*itr<<" ";
        }
        std::cout<<std::endl;
        for(auto itr = vect.begin();itr!=vect.end();++itr)
        {
            std::cout<<*itr<<" ";
        }
        std::cout<<std::endl;
        for(auto itr:vect)
        {
            std::cout<<itr<<" ";
        }
        std::cout<<std::endl;
    }

    void ex2()
    {
        int x = int();
        auto auto_x = x;                        // auto : int
        const int &crx = x;             
        auto auto_crx1 = crx;                   // auto : int
        const auto& auto_crx2 = crx;    // auto : int
        auto &auto_crx3 = crx;          // auto : const int
        volatile int vx=1024;                        
        auto avx = vx;                          // auto : int
    }

    // template<class T>
    // void func_ex3(T arg)
    // {
    //     std::cout<<"void func_ex3(T arg) "<<arg<<std::endl;
    // }

    template<class T>
    void func_ex3(const T& arg)
    {
        std::cout<<"void func_ex3(const T& arg) "<<arg<<std::endl;
    }
    void ex3()
    {
        const int &crx = 123;
        func_ex3(crx);
    }
    void ex4()
    {
        const int c = 0;
        auto &rc = c;                   // auto : const int
        //rc = 123;                                  //error occured
    }
    void ex5()      // amendment
    {
        int i = 42;
        auto && ri_i = i;                     // l-value , auto : int &
        auto && ri_2 = 42;                   // r-value , auto : int &&
    }
    void ex6()
    {
        int x = 42;
        const int* p1 = &x;
        auto p2 = p1;
        // *p2 = 43;        // error occured
        // int* p3 = p1;    // error occured    : const int* 을 int*으로 묵시적 형 변환하는 것은 허용 안 됨
        // *p3 = 44;        // error occured    

        const int cx = 3;
        int lx=cx;
    }

    // lhs 와 rhs에 각각 실수 또는 정수가 들어올 수 있다. func_ex7는 두 인자를 곱하는데, 곱한 결과값의 type을 템플릿 함수 인자를 받기 전까지는 모르므로, delctype으로 유추? 할 수 밖에 없다.
    template<typename T,typename S>
    void func_ex7(T lhs,S rhs)
    {
        auto prod1 = lhs*rhs;
        std::cout << "prod1 Type: " << typeid(prod1).name() << std::endl;

        typedef decltype(lhs*rhs) product_type;
        product_type prod2 = lhs*rhs;
        std::cout << "prod2 Type: " << typeid(prod2).name() << std::endl;

        decltype(lhs * rhs) prod3 = lhs*rhs;
        std::cout << "prod3 Type: " << typeid(prod3).name() << std::endl;

    }


    template<typename T,typename S>                 // decltype 은 auto로 생긴 모호한 return type을 정의하는 곳에서도 사용 가능하다. 
    // decltype(lhs*rhs) func_ex8(T lhs, S rhs) -> decltype(lhs*rhs)    // 이렇게 하는 방법도 있지 않나 싶은데 결과적으로 안 된다고 함.
    auto func_ex8(T lhs, S rhs) ->decltype(lhs*rhs)
    {
        return lhs*rhs;
    }    

    struct S
    {
        int m_x;
        S()
        {
            m_x = 42;
        }
    };

    void ex9()
    {
        int x;
        const int cx =42;
        const int& crx = x;
        const S *p = new S();

        auto a = x;
        auto b = cx;
        b+=1;
        auto c = crx;
        c=c+1;
        auto d = p;
        std::cout<<"d->m_x "<<d->m_x<<std::endl;
        auto e = p->m_x;
        e=e+1;
        delete p;

        typedef decltype(x) x_type;
        typedef decltype(cx) cx_type;
        typedef decltype(crx) crx_type;
        typedef decltype(p->m_x) m_x_type;
        typedef decltype((x)) x_with_parents_type;
        typedef decltype((cx)) cx_type;
        typedef decltype((crx)) crx_type;
        typedef decltype((p->m_x)) m_x_type;

        std::cout<<typeid(x_type).name()<<std::endl;
        std::cout<<typeid(cx_type).name()<<std::endl;
        std::cout<<typeid(crx_type).name()<<std::endl;
        std::cout<<typeid(m_x_type).name()<<std::endl;
        std::cout<<typeid(x_with_parents_type).name()<<std::endl;
        // std::cout<<typeid(x_type).name()<<std::endl;


    }
};


int main()
{
    Examples example1;
    example1.ex1();
    // example1.func_ex3(int(3));
    example1.ex3();
    example1.func_ex7(8,8.0);
    std::cout<<example1.func_ex8(8, 8)<<" "<<typeid(decltype(example1.func_ex8(8, 8))).name()<<std::endl;;
    std::cout<<example1.func_ex8(8, 8.0)<<" "<<typeid(decltype(example1.func_ex8(8, 8.0))).name()<<std::endl;;

    Examples::S s_instance;
    std::cout << "S instance m_x: " << s_instance.m_x << std::endl;

    example1.ex9();
    return 0;
}