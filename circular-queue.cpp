#include<iostream>

using namespace std;


#define SIZE 5

int queue[SIZE];

int front = -1, rear =-1;

bool isEmpty();
bool isFull();
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

    display(); // 1 2 3 4 5

    enqueue(6); // will print queue is full

    dequeue();

    display();// will print 2 3 4 5

    enqueue(6);

    display(); //  will print 2 3 4 5 6 

    cout << "peek = " << peek();

    return 0;
}

bool isEmpty() {
    if (front == -1 && rear == -1) {
        return true;
    }else { 
        return false;
    }
}
bool isFull(){
    if(front ==0 && rear == SIZE -1){
        return true;
    }else if( rear == front-1){
        return true;
    }else{
        return false;
    }
}

void enqueue(int value){
    if(isFull()){
        cout << "queue is full." << endl;
    }else{
        if(isEmpty()){
            front = rear = 0;
            queue[rear] = value;
        }else if(rear == SIZE -1) {
            rear = 0;
            queue[rear] = value;
        }else {
            queue[++rear] = value;
        }
    }
}
void dequeue(){
    if(isEmpty()){
        cout << "queue is empty" << endl;
    }else {
        if(front == rear){
            front = rear = -1;
        }else if(front == SIZE -1 ){
            front = 0;
        }else{
            front++;
        }
    }
}

int peek(){
    if(!isEmpty()){
        return queue[front];
    }else{
        cout << "queue is empty" << endl;
        return -1;
    }
}

void display(){
    if(isEmpty()) {
         cout << "queue is empty" << endl;
    }else{
        if(front <= rear){
            for( int i = front; i <= rear; i++){
                cout << queue[i] << "\t";
            }
            cout << endl;
        }else{
            // front greater than rear we wil make to for loop
            // one from front till size-1 
            //the second from 0 to rear
              for( int i = front; i < SIZE; i++){
                cout << queue[i] << "\t";
            }
             for( int i = 0; i <= rear; i++){
                cout << queue[i] << "\t";
            }
            cout << endl;

        }
    }
}