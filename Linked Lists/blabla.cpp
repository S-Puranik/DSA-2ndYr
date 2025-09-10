#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node* getNode()
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        cout << "Memory not alloted.";
        return NULL;
    }
    else
    {
        cout << "Enter data: ";
        cin >> newNode -> data;
        newNode -> next = NULL;
    }
    return newNode;
}

int Size(struct Node *head)
{

}

int main()
{
    cout<< "Lets create a linked list first, \nenter the size of the linked list to continue: ";
    int n;
    cin >> n;
    struct Node *newNode, *temp, *start;
    start = NULL;
    for(int i=0; i<n; i++)
    {
        newNode = getNode();
        if(start == NULL)
        {
            start = newNode;
        }
        else
        {
            temp = start;
            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }
    temp = start;
    while(temp != NULL)
    {
        cout << temp -> data;
        temp = temp -> next;
    }

    struct Node *nn;
    nn = getNode();
    newNode -> next = start;
    start = newNode;
    return start;

}

