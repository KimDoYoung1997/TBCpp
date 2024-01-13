#include <iostream>


int pow(int base,int exponent)
{
    int result = 1;

/* 
    for (int count=1;count<=exponent;count++)
    {
        result *= base;
    }

 */

/* 
    for (int count=0;count <exponent ; ++count)
    {
        result *= base;

    }

 */




    return result ;
}





int main()
{
    using namespace std;


//    cout<<pow(2,5)<<endl;


/* 
    for (int i=0,j=0;i<10;++i,--j)
    {
        cout <<i<<" " << j << endl;
    }

 */

    int result = 1 ;
    for (int j=1;j<10;++j)
        for (int i=1;i<10;++i)
            { 
                result = i * j ;
                cout << j << " x " << i <<" = "  << result <<endl;
            }


//    int count = 0;




/* 
    for(; count <10;++count)
    {
        cout << count << endl;
    }

    cout << count << endl;

 */

/* 
    for(; count <10;count++)
    {
        cout << count << endl;
    }

    cout << count << endl;

 */

/* 
    for (; ;++count)
    {
        cout <<count<<endl;
    }


 */

/* 
    for (int count=0; count < 10 ; ++count)
    {
        cout << count << endl;
         
        for (int count2=0 ; count2 <=count ; ++count2)
            {
                cout <<count2 <<"*" ;
            }
        cout <<endl;


        cout << count << endl;

    }

 */




    return 0;

}