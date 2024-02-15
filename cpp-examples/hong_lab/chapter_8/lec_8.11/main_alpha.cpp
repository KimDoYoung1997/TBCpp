#include <iostream>
using namespace std;

class SoSimple
{
public:
    static int simObjCnt;
public:
    SoSimple()
    {
        simObjCnt++;
    }
};
int SoSimple::simObjCnt=0;


int main()
{
    cout << SoSimple::simObjCnt<<"'st SoSimple object" <<endl;
    SoSimple sim1; //1
    SoSimple sim2; //2 
    cout << SoSimple::simObjCnt<<"'st SoSimple object" <<endl; //2
    cout <<sim1.simObjCnt <<"'st SoSimple object" <<endl; //2
    cout <<sim2.simObjCnt <<"'st SoSimple object" <<endl; //2 



    return 0;
}