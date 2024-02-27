// 첨자 연산자 [] 를 사용한 커스텀 배열 클래스 만들어 보기.
#include <cstdint>
#include <iostream>
#include <ostream>
using namespace std;

class IntList
{
private:
    int m_list[10];
public:
    IntList()
    :m_list{1,2,3,4,5,6,7,8,9,10}
    {}

    int& operator[](int index) // 반환형에 & 참조기호가 있어야만 배열의 값에 접근 및 수정이 가능하다.
    {
        return m_list[index];
    }

    const int& operator[](int index) const// const를 이용한 함수 오버로딩. , 여기선 어차피 원소값을 보기만 할거니까 & 가 굳이 필요는 없을듯?
    {
        return m_list[index];
    }


    void showArray() const
    {
        for(int i=0;i<10;i++)
        {
            cout <<m_list[i]<<" "; // 1 2 -10 4 5 6 7 8 9 10 
        }cout << endl;
    }

    friend std::ostream& operator << (std::ostream &out, const IntList &arr) // 멤버함수로는 <<연산자를 오버로딩 못함. 그 이유는 다음 링크에 설명됨 https://chat.openai.com/share/7c1e0ab8-7ed5-42ba-8aeb-4ad68fdddd13
    {
        out << arr.m_list ;

        return out;
    }

};



int main()
{
    IntList arr;
    cout << arr[2] << endl;
    arr[2] = -10;

    arr.showArray();

    const IntList c_arr;
    cout << c_arr[5] <<endl;
    c_arr.showArray();

    cout << c_arr << endl;
    return 0;
}