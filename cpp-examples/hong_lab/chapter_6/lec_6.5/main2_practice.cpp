#include <iostream>
#include <cstdint>
using namespace std;


int main()
{


    const int num_rows = 3;
    const int num_colums = 5;

    for (int row =0; row < num_rows; row++)
    {
        for (int col=0; col < num_colums ;col++ )
        {
            cout <<'['<<row<<']' << '['<<col<<']' << '\t';
        }
        cout <<endl;
    }

    cout <<"----------------------------------------------------------" << endl;

    int array[num_rows][num_colums]=
    {
    {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}        
    };

    cout <<"value of array is below" << endl;
    for (int i=0;i<num_rows;i++)
    {
        for (int j=0;j<num_colums;j++)
        {
            cout << "["<<array[i][j] <<"]"<< '\t';
        }
        cout <<endl;
    }

    cout <<"----------------------------------------------------------" << endl;


    cout <<"memory address of array is below" << endl;
    for (int i=0;i<num_rows;i++)
    {
        for (int j=0;j<num_colums;j++)
        {
            cout << "["<<(long)&array[i][j] <<"]"<< '\t';
        }
        cout <<endl;
    }

    cout <<"----------------------------------------------------------" << endl;


    cout <<"both memory address of array and value are below" << endl;
    for (int i=0;i<num_rows;i++)
    {
        for (int j=0;j<num_colums;j++)
        {
            cout << "["<<(long)&array[i][j] <<"]" <<"["<< array[i][j] <<"]" << '\t';
        }
        cout <<endl;
    }


    return 0;
}
