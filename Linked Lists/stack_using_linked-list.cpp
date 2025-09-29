// Name: Siddhant Puranik
// Roll: A-327
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node * getNode()
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        cout << "Memory not alloted.";
    }
    else
    {
        cout << "Enter data: ";
        cin >> newNode -> data;
        newNode -> next = NULL;
    }
    return newNode;
};

struct Node * push(struct Node *top)
{
    struct Node *newNode;
    newNode = getNode();
    if(top == NULL)
        top = newNode;
    else
    {
        newNode -> next = top;
        top = newNode;
    }
    return top;
}

struct Node * pop(struct Node *top)
{
    struct Node *temp = top;
    if(top == NULL)
    {
        cout << "\nStack underflow";
        return 0;
    }
    else
    {
        top = top -> next;
        cout << "\nPopped: " << temp -> data;
        free(temp);
    }
    return top;
}

int peek(struct  Node *top)
{
    if(top == nullptr) return -1;
    else{return top -> data;}
}

void display(struct Node *top)
{
    struct Node *temp = top;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main()
{
    struct Node *top = NULL;
    int choice;
    cout << "\n Choices: \n 0. Exit \n 1. Push \n 2. Pop \n 3. Display \n 4. Peek top";
    do
    {
        cout << "\n Enter a valid choice: ";
        cin >> choice;
        switch(choice)
        {
        case 0:
            break;
        case 1:
            top = push(top);
            break;
        case 2:
            top = pop(top);
            break;
        case 3:
            cout << "\n Stack is: ";
            display(top);
            break;
        case 4:
            {
                int x = peek(top);
                if(x== -1)
                {
                    cout << "\nNo elements at the top.";
                }
                else
                {
                    cout << "\n Topmost element is: " << x;
                }
                break;
            }
        default:
            cout << "\nEnter a valid choice and try again.";
            break;
        }
    }while(choice != 0);
}
