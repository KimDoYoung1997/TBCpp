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


    print(jj.name,jj.address,jj.age,jj.height,jj.weight);

    vector<string> name_vec;
    vector<string> addr_vec;
    vector<int> age_vec;
    vector<double> height_vec;
    vector<double> weight_vec;

    print(name_vec[0],addr_vec[0],age_vec[0],height_vec[0],weight_vec[0]);





    return 0;
}