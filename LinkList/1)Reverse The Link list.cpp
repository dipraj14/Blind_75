#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }


};

Node* reverseList_Two_Ptr(Node* head) {

    Node* prevPrt = NULL;
    Node* currPrt = head;
    Node* nextPtr;

    while(currPrt != NULL){
        nextPtr = currPrt -> next;
        currPrt -> next = prevPrt;
        prevPrt = currPrt;
        currPrt = nextPtr;

    }

    return prevPrt;
        
}
Node* reverseList_Reculsion(Node* head) {
    if(head == NULL or head -> next == NULL) return head;
    Node* newHead = reverseList_Reculsion(head -> next);
    head -> next -> next = head;
    head->next  = NULL;
    return newHead;
        
}
void InsertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}
void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data <<" ";
        temp = temp -> next;
    }
}

int main(){
    Node* node2 = new Node(10);
    Node* head2 = node2; // 10
    Node* tail = head2;
    InsertAtTail(tail, 20);
    InsertAtTail(tail, 30);
    InsertAtTail(tail, 40);

    cout << "Insert at tAIL" << endl;
    print(head2); // 10 -> 20 -> 30 -> 40 -> NULL (When called InsertAtTail() Funcation)
    cout << endl;

    cout << "After Reverse the linl list" << endl;
    // Node* newHead = reverseList_Two_Ptr(head2); // ittritive Way
    Node* newHead = reverseList_Reculsion(head2); //Reculsive Way
    print(newHead);

}