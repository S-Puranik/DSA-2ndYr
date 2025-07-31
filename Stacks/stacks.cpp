#include <iostream>
using namespace std;

const int MAX = 5;

class stack
{
    int top = -1;
    int Array[MAX];

public:
    bool push(int element)
    {
        if(top >= MAX - 1)
        {
            return false;
        }
        else
        {
            Array[++top] = element;
            return true;
        }
    }

    int pop()
    {
        if(top < 0)
        {
            cout << "Stack underflow: Returned with code: ";
            return 0;
        }
        else
        {
            int item = Array[top];
            Array[--top];
            return item;
        }
    }

    int peek()
    {
        if(top < 0)
        {
            cout << "NaN, stack is empty, process Returned with code: ";
            return 0;
        }
        else
        {
            return Array[top];
        }
    }

    int isEmpty()
    {
        if (top < 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int isFull()
    {
        if (top >= MAX-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    stack s1;
    int ch = 1;
    while(ch == 1)
    {
        int choice;
        cout << "\n1. Push operation.\n2. Pop Operation. \n3. Peek Operation. \n4.Check if array is empty. \n5.Check if array is full. \nEnter a valid choice (1:5): ";
        cin >>choice;
        switch(choice)
        {
        case 1:{
            int elem;
            cout << "Enter an element to be pushed in the stack:";
            cin >> elem;
            bool push = s1.push(elem);
            if(push)
            {
                cout << "Element pushed successfully.";
                break;
            }
            else
            {
                cout << "Stack overflow.";
                break;
            }
        }
        case 2:
        {
                cout << s1.pop();
                break;
        }
        case 3:
            {
                cout << "Topmost element: " << s1.peek();
                break;
            }
        case 4:
            {
                bool isempty = s1.isEmpty();
                if (isempty)
                {
                    cout << "The stack is empty";
                    break;
                }
                else
                {
                    cout << "The stack is not empty.";
                    break;
                }
            }
        case 5:
            {
                bool isfull = s1.isFull();
                if(isfull)
                {
                    cout << "The stack is full";
                    break;
                }
                else
                {
                    cout << "The stack is not full.";
                    break;
                }
            }
        }
        cout << "\n\nEnter 1 if you wish to continue or enter any number to exit: ";
        cin >> ch;
    }
}
