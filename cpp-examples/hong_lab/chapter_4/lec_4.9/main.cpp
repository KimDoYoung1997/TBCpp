#include <iostream>
#include <vector>
#include <cstdint>

int main()
{
/*  typedef double distance_t;

    double      my_distance;
    distance_t  home2work;
    distance_t  home2shool;

    #std::int8_t i(97);

 */

    using namespace std;
/*     
    std::vector<std::pair<std::string,int> > pairlist1;
    vector<pair<string,int>> pairlist2; 
*/

/* 
    typedef vector<pair<string,int>> pairlist_t;
    pairlist_t pairlist1;
    pairlist_t pairlist2; 

 */


    using pairlist_t = vector<pair<string,int> > ;
    pairlist_t pairlist1;
    pairlist_t pairlist2; 
    cout<<"build success"<<endl;


    return 0;
}