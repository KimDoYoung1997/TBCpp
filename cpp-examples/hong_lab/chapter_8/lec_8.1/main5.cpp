#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Object = data + function
    // data : Friend : m_name, m_address, m_age, m_height, m_weight ...
    // function : print()

class Friend
{
    public: //access specifier (public,private,protected)
        string m_name;
        string m_address;
        int m_age;
        double m_height;
        double m_weight;
        // function overloading  : void print
        void print()
        {
            cout << m_name << " " << m_address << " " << m_age << " " << m_height <<" " << m_weight << endl;
        }



};




// function overloading  : void print
void print(const string& m_name,const string& m_address, const int&m_age , const double&m_height, const double& m_weight)
{
    cout << m_name << " " << m_address << " " << m_age << " " << m_height <<" " << m_weight << endl;
}


int main()
{

    Friend jj{"Jack_Jack","Uptown",2,30.0,10.0}; //by Instanciation, stack memory is allocated
    jj.print();

    vector<Friend> my_friends ;
    my_friends.resize(2);

    for (auto &element : my_friends)
    {
        element.print();
        //my_friends[0].print();
        //my_friends[1].print();
        //my_friends[2].print();
    }




    // jj.m_name = "Jack_Jack";
    // jj.m_address = "Uptown";
    // jj.m_age = 2;
    // jj.m_height =30.0;
    // jj.m_weight = 10.0;


    // print(jj.m_name,jj.m_address,jj.m_age,jj.m_height,jj.m_weight);
    //print(jj);

    // vector<string> name_vec;
    // vector<string> addr_vec;
    // vector<int> age_vec;
    // vector<double> height_vec;
    // vector<double> weight_vec;






    return 0;
}