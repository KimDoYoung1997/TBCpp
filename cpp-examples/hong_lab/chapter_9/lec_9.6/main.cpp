// 첨자 연산자 [] 없이 유사 배열 클래스 만들어 보기.
#include <cstdint>
#include <iostream>
using namespace std;

class IntList
{
private:
    int m_list[10];
public:
    IntList()
    :m_list{1,2,3,4,5,6,7,8,9,10}
    {}
    void setItem(int index, int value)
    {
        m_list[index]=value;
    }
    int getItem(int index) const
    {
        return m_list[index];
    }

    int *getList()
    {
        //cout << (uintptr_t)m_list << endl;
        return m_list;
    }

};


int main()
{
    IntList arr;
    arr.setItem(3, -5); // 배열의 인덱스에 접근하여 값을 할당하는것과 유사하다.
    cout << arr.getItem(3) << endl; // 5  m_list{1,2,3,-5,5,6,7,8,9,10}
    arr.getList(); // m_list 배열의 주소값을 return한다.
    cout << arr.getList()[6] << endl; //배열의 이름이 포인터 주소임을 이용하여, [] 을 이용한 역참조
    arr.getList()[6]=-100; // m_list{1,2,3,-5,5,6,-100,8,9,10}
    cout << *(arr.getList()+1) << endl; // 포배열의 이름이 포인터 주소임을 이용하여, * 역참조 또한 가능하다.
    const IntList c_arr; // 상수 객체를 선언. 이때 클래스 내의 멤버변수또한 상수화 되므로, 멤버변수는 반드시 초기화 되어있어야 한다.
    cout << c_arr.getItem(3) << endl;

    return 0;
}