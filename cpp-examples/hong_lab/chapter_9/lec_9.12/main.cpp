#include <iostream>
#include <cassert>
#include <initializer_list> // 이번 시간에 배울 내용
#include <ostream>

using namespace std;

class IntArray
{
private:
    unsigned m_length=0;
    int* m_data = nullptr;
public:
    // 단일 길이를 인자로 받는 생성자
    IntArray(unsigned length):m_length(length)
    {
        m_data = new int[length];
    }
    // initializer_list를 이용한 생성자
    IntArray(const std::initializer_list<int> &list)
    : IntArray(list.size()) // 기존 생성자를 재사용하여 길이를 초기화
    {
        // 이니셜라이저 리스트를 이용하여 클래스 인스턴스를 초기화하면 다음과 같은 이점이 있습니다:
        // 1. 깔끔한 문법을 통해 여러 값을 초기화할 수 있습니다.
        // 2. 배열과 같이 고정된 숫자의 데이터를 초기화하는 코드를 간결하게 작성할 수 있습니다.
        // 3. std::initializer_list를 사용함으로써 컴파일러가 타입과 크기를 추론할 수 있어, 사용자 코드의 실수를 줄여줍니다.
        // 4. 다양한 길이의 데이터를 유연하게 처리할 수 있어, 코드의 재사용성과 확장성을 높여줍니다.
        int count = 0;
        for (auto &element : list)
        {
            m_data[count] = element;
            ++count;
        }
    }

    ~IntArray()
    {
        delete[] m_data;
    }

    // 출력 연산자 오버로드
    friend std::ostream & operator << (std::ostream& out, IntArray& int_arr)
    {
        // IntArray 객체의 모든 요소를 출력합니다.
        for(unsigned int i=0; i<int_arr.m_length; i++)
        {
            out << int_arr.m_data[i] << " ";
        }
        out << endl; // 요소 출력 후 줄바꿈
        return out;
    }
};

int main()
{
    int my_arr1[5] = {1, 2, 3, 4, 5}; // 기본 자료형 배열 초기화
    int *my_arr2 = new int[5] {1, 2, 3, 4, 5}; // 동적 할당 배열 초기화

    // IntArray 클래스 인스턴스를 이니셜라이저 리스트를 사용하여 초기화합니다.
    // 이니셜라이저 리스트를 사용함으로써 코드의 가독성과 간결성이 크게 향상됩니다.
    IntArray int_array{1, 2, 3, 4, 5};
    cout << int_array << endl; // IntArray 객체 출력

    return 0;
}
