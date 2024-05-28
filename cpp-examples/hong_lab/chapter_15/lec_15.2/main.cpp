#include <iostream>
using namespace std;

int getResult()
{
    return 0;
}
int &getRefResult()
{
    int x(0);

    return x ;
}

void doSomething(int &lref)
{
    cout <<"L-value ref" << endl;
}
void doSomething(const int &lref)
{
    cout <<"L-value const ref" << endl;
}
// void doSomething(int &&lref)
// {
//     cout <<"R-value ref" << endl;
// }

int main()
{
    int x = 5;  // x 는 메모리상에서 주소를 갖는 반면, 5 는 해당 라인이 지나가면 사라진다.
    int y = getResult();
    const int cx = 6;
    const int cy = getResult();

    // L-value references

    int &lr1 = x;               // Modifiable l-values
    // int &lr2 = cx;           // Non-modifiable l-values
    // int &lr3 = 5;            // R-value 
    // int &lll = getResult();     // getResult() 의 리턴값은 R-value이기때문에 참조할 수 없음
    int &llll = getRefResult(); // getRefResult() 의 리턴값은 l-value이기때문에 참조할 수 있음
    const int &lr4 = x;         // Modifiable l-values
    const int &lr5 = cx;        // Non-modifiable l-values
    const int &lr6 = 5;         // R-value
    
    // R-value references : R-value만 참조로 받을 수 있다. 다시 말해, 곧 사라질 값들만 담을 수 있다. 곧 사라질 놈들은 move를 사용해서 다른 곳으로 값을 옮겨도, 아무 문제가 없을 것이다.

    // int &&rr1 = x;           // Modifiable l-values
    // int &&rr2 = cx;          // Non-modifiable l-values
    int &&rr3 = 5;              // R-value
    int &&rrr = getResult();    // getResult 함수의 리턴값은 R-value이기때문에 참조할 수 있음
    // int &&rrrr = getRefResult();    // getRefResult 함수의 리턴값은 l-value이기때문에 참조할 수 없음
    // const int &&rr4 = x;     // Modifiable l-values
    // const int &&rr5 = cx;    // Non-modifiable l-values
    const int &&rr6 = 5;        // R-value


    doSomething(x);             // L-value ref
    doSomething(cx);            // L-value const ref
    doSomething(5);             // L-value const ref
    doSomething(getRefResult());// L-value ref
    doSomething(getResult());   // L-value const ref

    return 0;
}