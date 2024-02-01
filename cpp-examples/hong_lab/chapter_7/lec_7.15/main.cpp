//Command Line Arguments
#include <iostream>
#include <string>
using namespace std;








int main(int argc, char* argv[]) //argc : number of arguments , argv : contents of arguments
{

    for (int count =0; count < argc ; ++ count)
    {
        cout << count << endl;
        //cout << argv[count] << endl;

        std::string argv_single = argv[count] ;

        if (count == 1)
        {
            int input_number = std::stoi(argv_single);
            cout << input_number << endl;
        }
        else
            cout << argv_single << endl;


    }



    return 0;
}