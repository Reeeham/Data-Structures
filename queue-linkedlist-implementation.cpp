#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* front= NULL, *rear = NULL;
void enqueue(int value);
void dequeue();
int peek();
void display();

int main(){

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display(); //1 2 3 4 5 
    dequeue();
    display(); // 2 3 4 5 
    cout << "peek = " << peek();
    
    return 0;
}

void enqueue(int value) { 
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if(front == NULL) { 
        front = rear = newNode;

    }else{
        rear -> next = newNode;
        rear = newNode;
    }
}

void dequeue(){
    if(rear == NULL){
        cout << "queue is empty" << endl;
    }else if(rear == front){
        Node* ptr = front;
        front = rear = NULL;
        delete(ptr);
    }else{
        Node* ptr = front;
        front = front -> next;
        delete(ptr);
    }
}

int peek() { 
    if(front == NULL){
        cout << "queue is empty." << endl;
        return -1;
    }else{
        return front->data;
    }
}

void display(){
    
   if(front == NULL){
       cout << "queue is empty" << endl;
   }else{
       Node* current = front;
       while(current != NULL){
           cout << current->data << "\t";
           current = current -> next;
       }
       cout << endl;
   }
}