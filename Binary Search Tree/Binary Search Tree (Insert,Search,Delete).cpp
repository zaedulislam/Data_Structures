// Binary Search Tree (Insert,Search,Delete).cpp

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



bool Search(BSTNode *root, int x)
{
    if(root == NULL)
        return false;
    else if(x == root->data)
        return true;
    else
    {
        if(x <= root->data)
            return Search(root->left, x);
        else
            return Search(root->right, x);
    }
}



void Delete(BSTNode *root, int x)
{
    
}



int main()
{
    int I, n, x, q;

    BSTNode *rootPtr = NULL;

    cin >> n >> q;
    for(I = 0; I < n; I++)
    {
        cin >> x;
        rootPtr = Insert(rootPtr, x);
        //cout << "rootPtr = " << rootPtr << ", data = " << rootPtr->data << ", left = " << rootPtr->left << ", right = " << rootPtr->right << endl;
    }


    while(q--)
    {
        cin >> x;

        if(Search(rootPtr, x))
            cout << "Found\n";
        else
            cout << "Not Found\n";
    }



    return 0;
}

/*
8 10
21 10 42 35 50 45 62 70
*/
