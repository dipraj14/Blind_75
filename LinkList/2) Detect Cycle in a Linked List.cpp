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

bool hasCycle(Node *head) {
        Node* first = head;  Node *slow = head;
        
        while(first != NULL && first->next != NULL){
            if(slow->next == first ->next -> next ) return true;
            
            slow = slow ->next;
            first = first -> next -> next;
            
        }
        
        return false;
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

    // Creat a Loop in a a lisk list 
    head2 -> next -> next -> next = head2 -> next -> next;
    
    if(hasCycle(head2) == true){
        cout << "Cycle Detected" << endl;
    }else{
        cout << "Cycle Not Detected" ;
    }
    cout << endl;

}