// Find height of Binary Tree.cpp

#include<iostream>
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



int FindHeight(BSTNode *root)
{
    if(root == NULL)
        return -1;
    else
    {
        int leftHeight = FindHeight(root->left);
        int rightHeight = FindHeight(root->right);

        return 1 + max(leftHeight, rightHeight);
    }
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
    }

    cout << "Height of the Binary Tree = " << FindHeight(rootPtr) << endl;

    return 0;
}

/*
8
100 10 42 35 50 45 62 70
Height of the Binary Tree = 5
*/
