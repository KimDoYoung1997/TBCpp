//Encapsulation, Access Specifiers, Access Functions

#include <iostream>

using namespace std;

class Date
{



private:         //access specifier 
    int m_year;
    int m_month;
    int m_day;


public:
    void setDate(const int& year_input, const int& month_input, const int& day_input)
    {
            m_year = year_input;
            m_month = month_input;
            m_day = day_input;
    }

    const int& get_year()
    {
        return m_year;
    }
    const int& get_month()
    {
        return m_month;
    }
    const int& get_day()
    {
        return m_day;
    }

};


int main()
{
    //Date today{2024,2,3};
    Date today;
    today.setDate(2024,3,3);

    Date copy;
    copy.setDate(today.get_year(), today.get_month(),today.get_day());

    return 0;
}