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

void InsertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
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
    Node* node1 = new Node(10);
    
    Node* head1 = node1; // 10
    InsertAtHead(head1, 20);
    InsertAtHead(head1, 30);
    InsertAtHead(head1, 40);

    cout << "Insert at Head" << endl;
    print(head1); // 40 -> 30 -> 20 -> 10 -> NULL (When called InsertAtHead() Funcation)
    cout << endl;


    Node* node2 = new Node(10);
    Node* head2 = node2; // 10
    Node* tail = head2;
    InsertAtTail(tail, 20);
    InsertAtTail(tail, 30);
    InsertAtTail(tail, 40);

    cout << "Insert at tAIL" << endl;
    print(head2); // 10 -> 20 -> 30 -> 40 -> NULL (When called InsertAtTail() Funcation)

}