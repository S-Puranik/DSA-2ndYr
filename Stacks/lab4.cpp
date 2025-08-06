#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;

class Stack
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
    bool isop(char x)
    {
        if(x == '+' || x == '-' || x == '*' || x == '%' || x == '/' || x == '^'){return true;}
        else{ return false;}
    }
    int checkP(char x)
    {
        if(x == '^'){return 3;}
        else if(x == '*' || x == '/' || x == '%'){return 2;}
        else if(x == '+' || x == '-'){return 1;}
        else{return 0;}
    }
};



int main()
{
    Stack s1;
    string infix;
    cout << "Enter an operator: ";
    getline(cin, infix);
    int n = infix.length();

    for(int i=0; i<n; i++)
    {
        while(!s1.isop(infix[i+1]))
        {
            cout << infix[i];
        }
    }
}
