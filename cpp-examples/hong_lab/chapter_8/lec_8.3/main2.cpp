#include <iostream>

using namespace std;


class Fraction
{

    private:
        int m_numerator;
        int m_denominator;


    public:
        //Constructor function
        Fraction(const int& num_in, const int& den_in) // There is no return type. only the same name with Class
        {
            m_numerator =num_in;
            m_denominator =den_in ;
            cout << "Fraction() constructor" << endl;
        }


        void print()
        {
            cout << m_numerator <<" / " << m_denominator << endl;
        }

};




int main()
{

    // Fraction frac;
    // frac.print();

    Fraction one_thirds(1,3);
    one_thirds.print();


    return 0;
}