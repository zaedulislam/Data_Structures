
#include <iostream>
using namespace  std;

struct Node{
    int data;
    Node *next;
};

class SinglyLinkedList{
    private:
        Node* head;
        int linkedListLength;

    public:
        SinglyLinkedList();

        void insertAtBeginning(int value);
        void insertAtMiddle(int value);
        void insertAtEnd(int value);
        void insertAtGivenPosition(int value);

        void deleteFromBeginning(int value);
        void deleteFromMiddle(int value);
        void deleteFromEnd(int value);
        void deleteFromGivenPosition(int value);

        void printSinglyLinkedLis();
};


SinglyLinkedList::SinglyLinkedList() {
    head = NULL;
    linkedListLength = 0;
}



int main() {
    SinglyLinkedList linkedListObject;

    linkedListObject.printSinglyLinkedLis();



    return 0;
}
