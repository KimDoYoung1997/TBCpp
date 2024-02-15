#include <iostream>
using namespace std;

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    {
        cout <<"New Object : "<<(uintptr_t)this <<endl; 
    }
    SoSimple(SoSimple& copy): num(copy.num)
    {
        cout <<"New Copy obj : " << this << endl;
    }
    ~SoSimple()
    {
        cout <<"Destroy obj : " << (uintptr_t)this << endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob)     // SoSimple ob = obj; // CopyConstructor
{
    cout <<"Param ADR: " << &ob << endl;
    return ob;
}

int main()
{
    SoSimple obj(7);
    SimpleFuncObj(obj);

    cout << endl;
    SoSimple tempRef = SimpleFuncObj(obj);
    cout <<"Return Obj" << &tempRef<<endl;
    return 0;
}