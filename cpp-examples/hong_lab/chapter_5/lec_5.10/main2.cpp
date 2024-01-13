#include <iostream>


using namespace std;





int getInt()
{
    int x ;

    wormhole :
    cout << "Enter a integer number : ";
    cin >> x;

        
    if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            cout << "Invalid number. Too big!" << endl;
            goto wormhole ;
        }
        
        else
        {
            std::cin.ignore(32767, '\n');
        }
    return x;

}













/* 
int getInt()
{
    int x ;

    while (true)
    {
        cout << "Enter a integer number : ";
    cin >> x;

        
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            cout << "Invalid number. Too big!" << endl;
        }
        
        else
        {
            break;

        }
    }
    return x;
}

 */


/* 
int getInt()
{
    int x ;

    while (true)
    {
        cout << "Enter a integer number : ";
        cin >> x;

        
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            cout << "Invalid number. Too big!" << endl;
        }
        
        else
        {
           return x;
        }
    }
}

 */


char getOperator()
{
    while(true)
    {
        cout << "Enter an operator (+,-) : ";
        char op;
        cin >> op;
        std::cin.ignore(32767, '\n');

        if (op == '+' || op == '-')
            return op;
        else 
            cout<<"Invalid operator"<<endl;

    }
    
}


void printResult(int x, char op, int y)
{
    if (op =='+') cout << x+y <<endl;
    else if (op == '-') cout << x-y <<endl;
    else
    {
        cout << "Invalid operator Please try again" << endl;
    }

}




int main()
{

    int x = getInt();
    char op = getOperator();
    int y = getInt();

    printResult(x,op,y);




    return 0;
}