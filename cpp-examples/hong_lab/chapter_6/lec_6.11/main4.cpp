//Dynamic Memory Allocation
// https://chat.openai.com/share/79a665ad-5aa2-4353-9207-16196d8dd036
#include <iostream>

using namespace std;

int main()
{

    // memory leak
    while (true)
    {
        int * ptr = new int ;
        cout << ptr << endl;

        //delete ptr;
        //cout << " hi " << endl;
    }

    return 0;
}