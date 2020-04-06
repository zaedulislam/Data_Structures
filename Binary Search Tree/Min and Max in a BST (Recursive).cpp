// Find Min and Max element in a BST (Recursive).cpp

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



int FindMini(BSTNode *root)
{
    //if(root == NULL)
        //cout << "Tree is Empty" << endl;
    if(root->left == NULL)
        return root->data;
    else
        return FindMini(root->left);
}



int FindMaxi(BSTNode *root)
{
    //if(root == NULL)
      //cout << "Tree is Empty" << endl;
    if(root->right == NULL)
       return root->data;
    else
        return FindMaxi(root->right);
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

    cout << "Minimum = " << FindMini(rootPtr) << endl;
    cout << "Maximum = " << FindMaxi(rootPtr) << endl;

    return 0;
}

/*
8
100 10 42 35 50 45 62 70

Minimum = 10
Maximum = 70
*/
