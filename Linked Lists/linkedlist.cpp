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

int Size(struct Node *start)
{
    struct Node *temp = start;
    int ctr = 0;
    while(temp != NULL)
    {
        ctr++;
        temp = temp -> next;
    }
    return ctr;
}
struct Node * insert_at_beg(struct Node *start)
{
    struct Node *newNode;
    newNode = getNode();
    newNode -> next = start;
    start = newNode;
    return start;
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
    int choice =1;
    cout << "\nChoices:";
    cout<< "\n 0. Exit.\n 1.Size of the linked list.\n 2. Insert a new node at the beginning.\n 3. Insert a new node at the end. \n 4. Insert a new node after a node with data NUM. \n 5. Insert a new node before a node with data NUM. \n 6. Delete the first node of the lsit. \n 7. Delete the last node from the list. \n 8. Delete the node after the node with data NUM";
    while(choice != 0)
    {
        cout<< "\n Enter a valid choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            cout << "Size of the linked list: " << Size(start);
            break;
        case 2:
            insert_at_beg(start);
            break;
        default:
            cout<< "Enter a valid choice and try again.";
            break;
        }
    }

}

