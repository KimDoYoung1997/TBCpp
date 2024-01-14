//Dynamic Memory Allocation
// https://chat.openai.com/share/79a665ad-5aa2-4353-9207-16196d8dd036
#include <iostream>
#include <ostream>

using namespace std;

int main()
{

    // memory leak
    while (true)
    {
        int * ptr = new int ;
        cout << ptr << endl;

        delete ptr;
    }

    return 0;
}