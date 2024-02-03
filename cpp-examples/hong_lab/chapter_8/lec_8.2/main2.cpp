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

    void copyFrom(Date& origin_class)
    {
        m_year = origin_class.m_year;
        m_month = origin_class.m_month;
        m_day = origin_class.m_day;

        return  ;
    }

};


int main()
{
    //Date today{2024,2,3};
    Date today;
    today.setDate(2024,3,3);

    Date copy;
    copy.setDate(today.get_year()+1, today.get_month()+1,today.get_day()+1);
    cout <<copy.get_year() << " " << copy.get_month() << " " << copy.get_day() << endl;

    copy.copyFrom(today);
    cout <<copy.get_year() << " " << copy.get_month() << " " << copy.get_day() << endl;
    return 0;
}