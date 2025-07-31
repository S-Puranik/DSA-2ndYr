//WAP To delete an element for an array- Anywhere in the array.

#include <iostream>
using namespace std;

int main()
{
    int Array[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(Array) / sizeof(Array[0]);
    int idx;
    cout << "Enter the index of the element to be deleted: ";
    cin >> idx;

    for(int i=0; i<n; i++)
    {
        if(i < idx)
        {
            continue;
        }
        else
        {
            Array[i] = Array[i+1];
        }
    }
    for(int i=0; i<n-1; i++)
    {
        cout << Array[i] << " ";
    }
}
