//Selection sort withot using swap.
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int Array[10] = {9,14,7,8,2,5,1,10,11,3};
    int n = sizeof(Array)/sizeof(Array[0]);
    for(int i=0; i<n; i++)
    {
        int lowest_index = i;
        for(int j=i+1; j<n; j++)
        {
            if(Array[j] < Array[lowest_index])
            {
                lowest_index = j;
            }
        }
        swap(Array[i], Array[lowest_index]);
    }
    for(int i=0; i<n; i++)
    {
        cout << Array[i] << " ";
    }

    return 0;
}
