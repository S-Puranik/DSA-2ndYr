//WAP To insert an element at a given index in an array.

#include <iostream>
using namespace std;

int main()
{
    int Array[] = {1,2,3,4,5,6,7,8,9,10};
    int index, elem;
    cout << "Enter the index to insert the element: ";
    cin >> index;
    cout << "Now enter the element to insert: ";
    cin >> elem;
    int n = sizeof(Array)/sizeof(Array[0]);

    for(int i=n; i>=0; i--)
    {
        if(i == index)
        {
            Array[i] = elem;
            break;
        }
        else
        {
            Array[i] = Array[i-1];
        }
    }
    for(int i=0; i<=n; i++)
    {
        cout << Array[i] << " ";
    }
}
