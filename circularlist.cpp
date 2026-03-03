#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class CircularList{
private:
    Node* head;
    Node* tail;

public:
    CircularList(){
        head = tail = NULL;
    }

    void insertAtHead(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
            tail->next = head;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
    }

    void insertAtTail(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
            tail->next = head;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    void deleteAtHead(){
        if(head==NULL){
            cout << "CLL is empty";
            return;
        }
        if(tail==tail->next){
            delete tail;
            tail = NULL;
            head = NULL;
            return;
        }
        Node* temp = tail->next;
        tail->next = temp->next;
        temp->next = NULL;
        delete temp;
    }

    void deleteAtTail(){
        if(head==NULL){
            cout << "CLL is empty";
            return;
        }
        if(tail==tail->next){
            delete tail;
            tail = NULL;
            head = NULL;
            return;
        }
        Node* temp = tail->next;
        Node* temp2 = tail;
        while(temp->next!=tail){
            temp = temp->next;
        }
        temp->next = tail->next;
        tail->next = NULL;
        tail = temp;
        delete temp2;
    }

    void printList(){
        Node* temp = tail->next;
        cout << temp->data << " -> ";
        temp = temp->next;
        while(temp!=tail->next){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main(){
    CircularList cll;
    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtHead(3);
    cll.insertAtTail(4);
    cll.printList();
    return 0;
}