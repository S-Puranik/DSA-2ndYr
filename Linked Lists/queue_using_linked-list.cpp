//name: Siddhant Puranik
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

void Enqueue(struct Node **start)
{
    struct Node *newNode, *temp = *start;
    newNode = getNode();

    if(temp == NULL)
    {
        *start = newNode;
    }
    else
    {
        while(temp -> next != nullptr)
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}

struct Node * Dequeue(struct Node *start)
{
    struct Node *temp = start;
    if(temp == NULL)
    {
        cout << "\nNo elements in the list.";
        return NULL;
    }
    else
    {
        start = temp -> next;
        cout << "\nDeleted " << temp -> data << " from the start";
        free(temp);
        return start;
    }
};


void display(struct Node *start)
{
    struct Node *temp = start;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main()
{
    struct Node *start = NULL;
    int choice = -1;
    cout << "\n Choices: \n 0. Exit \n 1. Enqueue \n 2. Dequeue \n 3. Display";
    while(choice != 0)
    {
        cout << "\n Enter a valid choice: ";
        cin >> choice;
        switch(choice)
        {
        case 0:
            break;
        case 1:
            Enqueue(&start);
            break;
        case 2:
            start = Dequeue(start);
            break;
        case 3:
            cout << "\n Queue is: ";
            display(start);
            break;
        default:
            cout << "\nEnter a valid choice and try again.";
            break;
        }
    }
}
