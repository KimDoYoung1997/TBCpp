#include <iostream>

using namespace std;


class Fraction
{

    private:
        int m_numerator;
        int m_denominator;


    public:
        //Constructor 
        Fraction() // There is no return type. only the same name with Class
        {
            m_numerator =0 ;
            m_denominator =1 ;
            cout << "Fraction() constructor" << endl;
        }


        void print()
        {
            cout << m_numerator <<" / " << m_denominator << endl;
        }

};




int main()
{

    Fraction frac;
    frac.print();

    return 0;
}