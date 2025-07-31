//WAP to insert an element at the end of an array.

#include <iostream>
using namespace std;

int main()
{
    int Array[] = {1,2,3,4,5};
    int add;
    cout << "Enter an element to add at the end of the array: ";
    cin >> add;
    int n = sizeof(Array)/sizeof(Array[0]);
    Array[n] = add;
    for(int i=0; i<n+1; i++)
    {
        cout << Array[i] << " ";
    }
}
