#include <iostream>

using namespace std;


class Fraction
{

    private:
        int m_numerator;
        int m_denominator;


    public:

        Fraction()
        {
            m_numerator = 1;
            m_denominator=77 ;
            cout << "Fraction() constructor 1" << endl;

        }


        //Constructor function
        Fraction(const int& num_in, const int& den_in=3) // There is no return type. only the same name with Class
        {
            m_numerator =num_in;
            m_denominator =den_in ;
            cout << "Fraction() constructor 2" << endl;
        }

        //Constructor function overloading is also possible
        Fraction(const int& num_in, const int& den_in, const int& extra_in=7) // There is no return type. only the same name with Class
        {
            m_numerator =num_in;
            m_denominator =den_in ;
            cout << "Fraction() constructor 3" << endl;
        }

        void print()
        {
            cout << m_numerator <<" / " << m_denominator << endl;
        }

};




int main()
{

    //Fraction frac();  Compile error in c++ , if there is no class constructor arguments, you should not use " () "  
    //frac.print();

    Fraction frac1;
    frac1.print();

    Fraction frac2(1);
    frac2.print();

    Fraction frac3(1,3,3);
    frac3.print();




    return 0;
}