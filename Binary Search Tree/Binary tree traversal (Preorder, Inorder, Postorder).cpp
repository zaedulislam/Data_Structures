// Binary tree traversal (Preorder, Inorder, Postorder).cpp

#include<iostream>
#include<cstdio>
using namespace std;




struct BSTNode
{
    int data;
    BSTNode *left, *right;
};



BSTNode *CreateNewNode(int data)
{
    BSTNode *newNode = new BSTNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}



BSTNode *Insert(BSTNode *root, int data)
{
    if(root == NULL)
        root = CreateNewNode(data);
    else
    {
        if(data <= root->data)
            root->left = Insert(root->left, data);
        else
            root->right = Insert(root->right, data);
    }

    return root;
}


void PreOrder(BSTNode *root)
{
    if(root == NULL)
        return;

    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}



void InOrder(BSTNode *root)
{
    if(root == NULL)
        return;

    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}



void PostOrder(BSTNode *root)
{
    if(root == NULL)
        return;

    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
}



int main()
{
    int I, n, x;

    BSTNode *rootPtr = NULL;

    cin >> n;
    for(I = 0; I < n; I++)
    {
        cin >> x;
        rootPtr = Insert(rootPtr, x);
        //cout << "rootPtr = " << rootPtr << ", data = " << rootPtr->data << ", left = " << rootPtr->left << ", right = " << rootPtr->right << endl;
    }

    printf("Pre-order Traversal: ");
    PreOrder(rootPtr);

    printf("\nIn-order Traversal: ");
    InOrder(rootPtr);

    printf("\nPost-order Traversal: ");
    PostOrder(rootPtr);

    return 0;
}

/*
12
50 45 70 21 62 91 10 35 86 98 42 88
*/
