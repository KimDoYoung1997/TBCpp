#include <iostream>
using namespace std;

int main() {
    // char 배열 사용
    char a[10] = "hello";
    cout << "Original a: " << a << endl;

    // char 배열의 특정 문자 변경
    a[1] = 'a'; // "hallo"로 변경
    cout << "Modified a: " << a << endl;

    // const char* 사용
    const char* b = "hello2";
    cout << "b points to: " << b << endl;

    // b[1] = 'a'; // 컴파일 에러: b가 가리키는 문자열은 변경 불가능

    // b 포인터를 다른 문자열 리터럴로 변경
    b = "world";
    cout << "b now points to: " << b << endl;

    // 새로운 char 배열과 const char* 선언
    char c[] = "modify";
    const char* d = c; // d는 c의 첫 번째 문자를 가리키는 포인터

    // c 배열의 문자 변경 가능
    c[0] = 'M';
    cout << "Modified c through c: " << c << endl;

    // d를 통해 c 배열의 문자에 접근
    cout << "Accessing c through d: " << d << endl;

    return 0;
}
