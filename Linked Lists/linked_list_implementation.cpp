// Name: Siddhant Puranik
// Roll: A-327
// Prog: BTech CE - A.
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

struct Node * createlist(int n)
{
    struct Node *newNode, *start, *temp;
    if(n <= 0) return NULL;

    start = getNode();
    temp = start;

    for(int i = 1; i<n; i++)
    {
        newNode = getNode();
        temp -> next = newNode;
        temp = newNode;
    }
    return start;
}

void traverse(struct Node *start)
{
    struct Node *temp = start;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

struct Node * insert_at_beg(struct Node *start)
{
    struct Node *newNode;
    newNode = getNode();
    if (start == NULL)
    {
        start = newNode;
    }
    else
    {
        newNode -> next = start;
        start = newNode;
    }
    return start;
};

void insert_at_end(struct Node *start)
{
    struct Node *temp = start, *newNode;
    newNode = getNode();
    if(start == NULL)
    {
        start = newNode;
    }
    else
    {
        while(temp ->next != nullptr)
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}

void insert_after_data(int d, struct Node *start)
{
    struct Node *temp = start, *newNode;
    newNode = getNode();
    bool inserted = false;
    while (temp != NULL)
    {
        if(d == temp -> data)
        {
            newNode -> next = temp -> next;
            temp -> next = newNode;
            inserted = true;
            break;
        }
        else {temp = temp -> next;}
    }
    if(inserted) cout << "\ndata inserted successfully.";
    else {cout << "\nData was not inserted.";}
}

void insert_b4_data(int d, struct Node *start)
{
    struct Node *temp = start, *temp2 = temp, *newNode;
    newNode = getNode();
    bool inserted = false;
    while(temp != NULL)
    {
        if(temp -> data == d)
        {
            temp2 -> next = newNode;
            newNode -> next = temp;
            inserted = true;
            break;
        }
        else
        {
            temp2 = temp;
            temp = temp -> next;
        }
    }
    if(inserted) cout << "\ndata inserted successfully.";
    else {cout << "\nData was not inserted.";}
}

struct Node * delete_first_node(struct Node *start)
{
    struct Node *temp = start;
    if(temp == NULL)
    {
        cout << "\nNo elements int he list.";
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

void delete_last_node(struct Node *start)
{
    struct Node *temp = start, *temp2 = temp;
    if(temp == NULL)
    {
        cout << "\nNo elements in the list.";
    }
    else
    {
        while(temp -> next != nullptr)
        {
            temp2 = temp;
            temp = temp -> next;
        }
        temp2 -> next = nullptr;
        cout << "Deleted " << temp -> data << " from the end.";
        free(temp);
    }
}

void delete_at_data(int d, struct Node *start)
{
    struct Node *temp = start, *temp2 = temp;
    bool deleted = false;
    if(temp == NULL)
    {
        cout << "No elements in the list.";
    }
    else
    {
        while(temp -> next != nullptr)
        {
            if(temp -> data == d)
            {
                temp2 -> next = temp -> next;
                free(temp);
                deleted = true;
                break;
            }
            else
            {
                temp2 = temp;
                temp = temp -> next;
            }
        }
    }
    if(deleted) cout << "\nsuccessfully deleted the node.";
    else {cout << "node could not be deleted.";}
}

void delete_after_data(int d, struct Node *start)
{
    struct Node *temp = start, *temp2 = temp;
    bool deleted = false;
    if(temp == NULL)
    {
        cout << "No elements in the list.";
    }
    else
    {
        while(temp -> next != nullptr)
        {
            if(temp -> data == d && temp2 != NULL)
            {
                temp -> next = temp2 -> next;
                deleted = true;
                break;
            }
            else
            {
                temp = temp -> next;
                temp2 = temp -> next;
            }
        }
    }
    if(deleted) cout << "\nsuccessfully deleted the node.";
    else {cout << "node could not be deleted.";}
}

int main()
{
    struct Node *start;
    int n;
    cout << "Enter size of the link list to create: ";
    cin >> n;
    start = createlist(n);


    int choice =1;
    cout << "\nChoices:";
    cout<< "\n 0. Exit.\n 1. Traverse through the linked list.\n 2. Insert a new node at the beginning.\n 3. Insert a new node at the end. \n 4. Insert a new node after a node with data NUM. \n 5. Insert a new node before a node with data NUM. \n 6. Delete the first node of the lsit. \n 7. Delete the last node from the list. \n 8. Delete the node with data NUM \n 9. Delete the node after a node with data NUM ";
    while(choice != 0)
    {
        cout<< "\n Enter a valid choice: ";
        cin >> choice;
        switch(choice)
        {
        case 0:
            break;
        case 1:
            cout << "\nData in the linked list: ";
            traverse(start);
            break;
        case 2:
            start = insert_at_beg(start);
            break;
        case 3:
            insert_at_end(start);
            break;
        case 4:
            int data;
            cout << "Enter the data of the node to insert after: ";
            cin >> data;
            insert_after_data(data, start);
            break;
        case 5:
            int d;
            cout << "Enter the data of the node to insert before: ";
            cin >> d;
            insert_b4_data(d, start);
            break;
        case 6:
            start = delete_first_node(start);
            break;
        case 7:
            delete_last_node(start);
            break;
        case 8:
            int da;
            cout << "Enter the data of the node to be deleted: ";
            cin >> da;
            delete_at_data(da, start);
            break;
        case 9:
            int za;
            cout << "Enter the data of the node: ";
            cin >> za;
            delete_after_data(za, start);
            break;
        default:
            cout<< "\nEnter a valid choice and try again.";
            break;
        }
    }
}
