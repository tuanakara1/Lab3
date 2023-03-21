#include <iostream>
using namespace std;

class Node {
public:
    Node* next;
    Node(int d){
        data =d;
        next=NULL;
    }
    int data;
};

class Queue{

public:
    Node* front;
    Node* rear;
    int count;

    Queue(){
        front=NULL;
        rear=NULL;
        count=0;
    }

    void enqueue(int data){
        Node* newNode=new Node(data);
        if(rear==NULL){
            front=rear=newNode;
        }
        else{
            rear->next=newNode;
            rear=newNode;
        }
        count++;
    }

    bool isEmpty(){
        return (front==NULL);
    }

    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        Node* temp=front;
        int data =temp->data;
        front= front->next;
        if(front==NULL){
            rear=NULL;
        }
        delete temp;
        count--;
        return data;
    }

    int size(){
        return count;
    }

    int top(){
        if(isEmpty()){
            cout<<"Queue is empty "<<endl;
            return -1;
        }
        return front->data;
    }
};


int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(5);
    q.enqueue(7);
    cout<<"Top element of queue:"<<q.top()<<endl;
    cout<<"Queue size:"<<q.size()<<endl;
    q.dequeue();
    cout<<"--After dequeue--"<<endl;
    cout<<"Top element of queue:"<<q.top()<<endl;
    cout<<"Queue size:"<<q.size()<<endl;

}
