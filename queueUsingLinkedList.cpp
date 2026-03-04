#include <iostream>
#include <vector>
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



class Queue{
    Node* head;
    Node* tail;

public:
    Queue(){
        head = tail = NULL;
    }

    void push(int data){
        Node* newNode = new Node(data);
        if(empty()){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;

    }

    void pop(){
        if(empty()){
            cout << "Empty Queue\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int front(){
        if(empty()){
            return -1;
        }
        return head->data;
    }

    bool empty(){
        return head==NULL;
    }
};

int main(){
    return 0;
}