#include <iostream>

using namespace std;




struct Rectangle
{
    int length ;
    int width;
};


int main()
{

    cout << sizeof(Rectangle) << endl; // 8 = 4* 2

    Rectangle rect_arr[10]; // 80 = 8*10 = 4*2*10
    cout << sizeof(rect_arr) << endl; 
    

    rect_arr[0].length = 10 ;
    rect_arr[0].width = 20 ;

    cout << rect_arr[0].length << endl;
    cout << rect_arr[0].width << endl;



    return 0;
}