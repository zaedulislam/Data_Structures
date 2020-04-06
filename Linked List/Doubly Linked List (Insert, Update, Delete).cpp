// Doubly Linked List (Insert, Update, Delete).cpp

#include<iostream>
using namespace std;




struct DoublyLinkedList
{
    int data;
    DoublyLinkedList *prev, *next;
};



DoublyLinkedList *CreateNewNode(int data)
{
    DoublyLinkedList *newNode = new DoublyLinkedList();
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}



DoublyLinkedList *Insert(DoublyLinkedList *root, int data)
{
    DoublyLinkedList *newNode = CreateNewNode(data);

    if(root == NULL)
        root = newNode;
    else
    {
        DoublyLinkedList *curr = root;
        while(curr->next != NULL)
            curr = curr->next;

        curr->next = newNode;
        newNode->prev = curr;
    }

    return root;
}



int main()
{
    int I, n, data;
    cin >> n;

    DoublyLinkedList *rootPtr = NULL;

    for(I = 0; I < n; I++)
    {
        cin >> data;
        rootPtr = Insert(rootPtr, data);
    }

    ///Print
    while(rootPtr != NULL)
    {
        cout << rootPtr->data << ' ';
        rootPtr = rootPtr->next;
    }
}
