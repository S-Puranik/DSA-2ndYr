//WAP to insert an element at the beginning in an array.

#include <iostream>
using namespace std;

int main()
{
    int Array[] = {1,2,3,4,5};
    int add;
    cout << "Enter an element to add at the beginning of the array: ";
    cin >> add;
    int n = sizeof(Array)/sizeof(Array[0]);
    for(int i=n; i>=1; i--)
    {
        Array[i] = Array[i-1];
    }
    Array[0] = add;
    for(int i =0; i<n+1; i++)
    {
        cout << Array[i] << " ";
    }
}
