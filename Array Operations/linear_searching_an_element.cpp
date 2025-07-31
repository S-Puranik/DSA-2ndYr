//WAP to search an element in an array

#include <iostream>
using namespace std;

int main()
{
    int Array[10] = {1,2,3,4,5,6,7,8,9,10};
    int elem;
    cout << "Enter an element to search in the array: ";
    cin >> elem;
    bool Found = false;
    for(int i=0; i<10; i++)
    {
        if(elem == Array[i]){
            Found = true;
            cout << "Element found at index: " << i;
            break;
        }
    }
    if(Found == false)
    {
        cout << "The element was not found in the array.";
    }
}
