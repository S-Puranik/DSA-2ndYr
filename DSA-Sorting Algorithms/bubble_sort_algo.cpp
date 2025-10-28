#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int Arr[] = {11,13,9,4,7,10,6,4,2,15};
    int n = sizeof(Arr)/sizeof(Arr[0]);

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                swap(Arr[j], Arr[j+1]);
            }
        }
    }

    cout << "Sorted array is: ";
    for(int i=0; i<n; i++)
    {
        cout << Arr[i] << " ";
    }

return 0;
}
