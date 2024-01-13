#include <iostream>
#include <cmath>
int main()
{

    using namespace std;

    // int x,y ;
    // while (true)
    // {    
    //     cin >> x >> y ;
    //     cout <<"Your input values are:  " << x  << " " << y << endl;
    // }

    double d1 (100 - 99.99); // expectation : 0.001
    double d2 (10 - 9.99); // expectation : 0.001

    cout << d1 << endl ;
    cout << d2 << endl ; //0.01
    cout << std::abs(d1 - d2) << endl; //5.32907e-15

    const double epsilon = 1e-10;
    if ((std::abs(d1 - d2)) < (epsilon))
        cout << "Approximately equal" << endl;
    else cout << "Not eqaul" << endl;




    if (d1 == d2)
        cout << "equal" << endl;
    else
    {
        cout <<"Not equal" << endl;
        
        if (d1 > d2 ) cout << "d1 > d2" << endl;
        else cout << "d1 < d2" << endl;



    } 
    



    return 0;
}