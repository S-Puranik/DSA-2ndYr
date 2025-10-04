#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * createNode(int arr[], int i, int n)
{
    if(i >= n || arr[i] == -1)
        return NULL;

    struct Node *root;
    root = (struct Node*)malloc(sizeof(struct Node));

    root -> data = arr[i];
    root -> left = createNode(arr, (2*i)+1, n);
    root -> right = createNode(arr, (2*i)+2, n);

    return root;
};


void inorder(struct Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    int arr[] = {1,3,7,5,-1,8,9,4,6,-1,-1,-1,-1,-1,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,11,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i = 0;

    struct Node * root;
    root = createNode(arr, i, n);

    int choice;
    cout << "Created an array with elements: {1,3,7,5,-1,8,9,4,6,-1,-1,-1,-1,-1,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,11,12}";
    cout << "\nChoices: \n0. Exit. \n1. Preorder Traversal. \n2. Postorder traversal. \n3. Inorder Traversal.";
    do
    {
        cout << "\nEnter a choice: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "\n Preorder Traversal: ";
            preorder(root);
            break;
        case 2:
            cout << "\n Postorder Traversal: ";
            postorder(root);
            break;
        case 3:
        cout << "\n Inorder Traversal: ";
            inorder(root);
            break;
        default:
            cout << "\nInvalid choice.";
            break;
        }
    } while (choice != 0);

}
