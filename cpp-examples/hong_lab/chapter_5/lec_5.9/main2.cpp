#include <iostream>
#include <cstdlib> // std::rand() , std::srand()
#include <ctime> // std::time()
using namespace std;


int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0)

}



int main()
{

    //std::srand(5323); //seed
    cout <<"Time : " <<static_cast<unsigned int>(std::time(0)) << endl;
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int count = 1; count <=10 ; ++count)
    {
        cout << std::rand() << "\t";

        if (count % 5 ==0) cout <<endl;



    }




    return 0;
}