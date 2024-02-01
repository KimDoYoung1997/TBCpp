#include <iostream>
#include <string>
#include <vector>

using namespace std;
// Friend : name, address, age, height, weight ...


struct Friend
{

    string name;
    string address;
    int age;
    double height;
    double weight;

};



// function overloading  : void print
void print(const Friend& fr)
{
    cout << fr.name << " " << fr.address << " " << fr.age << " " << fr.height <<" " << fr.weight << endl;
}

// function overloading  : void print
void print(const string& name,const string& address, const int&age , const double&height, const double& weight)
{
    cout << name << " " << address << " " << age << " " << height <<" " << weight << endl;
}


int main()
{

    Friend jj;
    jj.name = "Jack_Jack";
    jj.address = "Uptown";
    jj.age = 2;
    jj.height =30.0;
    jj.weight = 5.0;


    // print(jj.name,jj.address,jj.age,jj.height,jj.weight);
    print(jj);

    vector<string> name_vec;
    vector<string> addr_vec;
    vector<int> age_vec;
    vector<double> height_vec;
    vector<double> weight_vec;






    return 0;
}