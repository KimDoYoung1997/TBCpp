#include <iostream>
#include <cstring>
using namespace std;
template <class T, int size>
class StaticArray_BASE
{
private:
    T m_array[size];
public:
    T * getArray()
    {
        return m_array ;  // 배열은 포인터므로 return 타입도 * 이 붙은 포인터 타입임
    }

    T& operator[](int index) // 대입 연산자 오버로딩
    {
        return m_array[index];
    }

    // 함수 템플릿 이것도 가능
    
    // void print(StaticArray<T,size> & array)
    // {
    //     cout<<"hello"<<endl;
    //     for(int count=0;count<size;count++)
    //     {
    //         cout << array[count] <<" ";
    //     }cout << endl;

    void print()
    {
        cout<<"hello"<<endl;
        for(int count=0;count<size;count++)
        {
            cout << (*this)[count] <<" ";
        }cout << endl;

    }

};

// 상속
template <class T, int size>
class StaticArray : public StaticArray_BASE< T,size>
{
};

//상속후 특수화 하여 오버라이딩
template<int size>
class StaticArray<char,size> : public StaticArray_BASE< char,size>
{
public:
    void print()
    {
        cout<<"hello"<<endl;
        for(int count=0;count<size;count++)
        {
            cout << (*this)[count];
        }cout << endl;

    }
};


// // 함수 템플릿
// template<int size>
// void print(StaticArray<char,size> & array)
// {
//     cout<<"hello char"<<endl;
//     for(int count=0;count<size;count++)
//     {
//         cout << array[count];
//     }cout << endl;
// }


int main()
{
    StaticArray<int, 5> s_array;
    
    for(int i=0;i<5;i++)
    {
        s_array[i] = i*10;
    }
    
    s_array.print();

    StaticArray<char,14> char14;
    const char* str = "Hello, World";
    strncpy(char14.getArray(), str, 13); // 13 문자 복사 (널 종단 문자 고려)

    char14.print(); //이 경우 특수화 됨

    return 0;
}