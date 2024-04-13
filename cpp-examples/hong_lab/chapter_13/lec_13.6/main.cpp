#include <iostream>
#include <cstring>
using namespace std;
template <class T, int size>
class StaticArray
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
};


// 함수 템플릿
template<class T,int size>
void print(StaticArray<T,size> & array)
{
    cout<<"hello"<<endl;
    for(int count=0;count<size;count++)
    {
        cout << array[count] <<" ";
    }cout << endl;
}

// 함수 템플릿
template<int size>
void print(StaticArray<char,size> & array)
{
    cout<<"hello char"<<endl;
    for(int count=0;count<size;count++)
    {
        cout << array[count];
    }cout << endl;
}


int main()
{
    StaticArray<int, 5> s_array;
    
    for(int i=0;i<5;i++)
    {
        s_array[i] = i*10;
    }
    
    print<int,5>(s_array);

    StaticArray<char,14> char14;
    const char* str = "Hello, World";
    strncpy(char14.getArray(), str, 13); // 13 문자 복사 (널 종단 문자 고려)

    // print<char,14>(char14); 이 경우 특수화 안 됨
    // print<14>(char14); 이 경우 특수화 됨
    // print(char14); //이 경우 특수화 됨
    print<>(char14); //이 경우 특수화 됨

    return 0;
}