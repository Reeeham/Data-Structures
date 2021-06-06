#include <iostream>
using namespace std;

void enqueue(int value);
void dequeue(int value);
int peek();
void display();

#define SIZE 5

int queue[SIZE];
int front =-1,rear =-1;

int main(){

      enqueue(5);
      enqueue(10);
      enqueue(3);
      enqueue(9);
      display();

      display();

      cout << "peek =" << peek(); 

    return 0;
}

void enqueue(int value){

    if(rear != SIZE -1){

        if(front == -1 && rear == -1){

            front++;
            queue[++rear] = value;
        }else{
            
             queue[++rear] = value;

        }

    }else{
        cout<< "queue is full." << endl;
    }

}
void dequeue(int value){
    if(front != -1 && rear !=-1 && front <= rear){
        front++;
        
    }else{
        cout<< "queue is empty." << endl;
    }
}

int peek(){
   if(front != -1 && rear !=-1 && front <= rear){
        return queue[front];
        
    }else{
        cout<< "queue is empty." << endl;
        return -1;
    }
    
}

void display(){
   if(front != -1 && rear !=-1 && front <= rear){
        for(int i=front; i<=rear;i++){
            cout << queue[i] << "\t";
        }
        cout << endl;
    }else{
        cout<< "queue is empty." << endl;
    }
}