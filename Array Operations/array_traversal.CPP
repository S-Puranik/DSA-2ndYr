//Wap to print or traverse all the elements of an array.

#include<iostream>
using namespace std;

int main()
{
    int Arr[5] = {1,2,3,4,5};
    for(int i=0; i<5; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << "\nSuccessfully traversed through the array.";
}
