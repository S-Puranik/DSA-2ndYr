#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *getNode(int key)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
        cout << "Memory not alloted.";
    else
    {
        newNode -> data = key;
        newNode -> left = newNode -> right = NULL;
    }
    return newNode;
}

struct Node *insert(struct Node *root, int key)
{
    struct Node *newNode = getNode(key);
    if(root == NULL)
    {
        root = newNode;
        return root;
    }

    struct Node *current = root, *parent;
    while(current != NULL)
    {
        parent = current;
        if(key > current -> data)
            current = current -> right;

        else 
            current = current -> left;
    }
    if(key > parent -> data)
        parent -> right = newNode;
    else
        parent -> left = newNode;
        
    return root;
}

struct Node *search(struct Node *root, int key)
{
    struct Node *current = root;
    if(current == NULL || root -> data == key)
        return root;
    
    while(current != NULL)
    {
        if(current == NULL || current -> data == key)
            break;
        if(key > current -> data)
            current = current -> right;
        else
            current = current -> left;
    }
    return current;
}

struct Node * delete_0_child_leaf(struct Node *root, int key)
{
    if(root == NULL || root-> data == key)
        return NULL;
    
    struct Node *current = root, *parent;
    
    while(current -> data != key)
    {
        parent = current;
        if(key > current -> data)
            current = current -> right;
        else 
            current = current -> left;
    }
    if (key > parent -> data)
        parent -> right = NULL;
    else
        parent -> left = NULL;
    
    return root;
}

struct Node * delete_1_child_leaf(struct Node *root, int key)
{
    if(root == NULL)
        return NULL;
    if(root-> data == key)
        if(root -> left != NULL)
            return root -> left;
        else
            return root -> right;
    
    struct Node *current = root, *parent;

    while(current -> data != key)
    {
        parent = current;
        if(key > current -> data)
            current = current -> right;
        else
            current = current -> left;
    }
    
    if(key > parent -> data && current -> left != NULL)
        parent -> right = current -> left;
    else if(key > parent -> data && current -> right != NULL)
        parent -> right = current -> right;
    else if(key < parent -> data && current -> left != NULL)
        parent -> left = current -> left;
    else if(key < parent -> data && current -> right != NULL)
        parent -> left = current -> right;

    free(current);
    return root;
}

void inorder(struct Node *root)
{
    if(root == NULL)
        return;

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void preorder(struct Node *root)
{
    if(root == NULL)
        return;
    
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(struct Node *root)
{
    if(root == NULL)
        return;
    
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}
int main()
{
    struct Node *root = NULL, *temp;
    int choice, key;

    cout << "Choices: \n1. Insert a node. \n2. Search a node using a key. \n3. Delete a leaf node with no child nodes. \n4. Delete a leaf node with one child node. \n5. Delete a leaf node with two child nodes. \n6. Inorder traversal \n7. Preorder Traversal \n8. Postorder traversal.";
    do
    {
        cout << "\nEnter a choice: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "\nEnter the key to be inserted: ";
            cin >> key;
            root = insert(root, key);
            break;
        case 2:
            cout << "\nEnter a key to be searched: ";
            cin >> key;
            temp = search(root, key);
            if(temp == NULL)
                cout << "\nElement not found in the Binary Search tree.";
            else
                cout << "Element found in the BST.";
            break;
        case 3:
            cout << "Enter key of the node to be deleted: ";
            cin >> key;
            root = delete_0_child_leaf(root, key);
            break;
        case 4:
            cout << "Enter key of the node to be deleted: ";
            cin >> key;
            root = delete_1_child_leaf(root, key);
            break;
        case 5:
            int data;
            cout << "Enter the data of the node to be deleted: ";
            cin >> data;
            break;
        case 6:
            inorder(root);
            break;
        case 7:
            preorder(root);
            break;
        case 8:
            postorder(root);
            break;
        default:
            break;
        }
    }while(choice != 0);
}