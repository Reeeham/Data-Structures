#include <iostream>
using namespace std;
/* prioritized array using last in first out using push, pop, peek, display **/


#define size 5
int stack[size],top = -1;

void push(int value);
int pop();
int peek();
void display();

int main(){
    
    push(5);
    push(7);
    push(9);
    push(6);
    display();
    cout << "peek = " << peek() << endl;

    return 0;
}

void push(int value) { 
    if(top == size-1){
        cout << "Stack overflow I can't add";
    }else { 
        top++;
        stack[top] = value;
    }

}

int pop(){

    if(top == -1){
        cout << "Stack underflow, stack is Empty" << endl;
        return 0;
    }else { 

        return stack[top--]; // will return first stack[top] then will decrement value of top by one

    }
}

int peek(){
    if(top == -1){
        cout << "Stack underflow, stack is Empty" << endl;
        return 0;
    }else{
       return stack[top];
    }
}

void display(){
    if(top == -1){
                cout << "Stack underflow, stack is Empty" << endl;

    }else{
        for(int i = top; i>=0; i--){
            cout << stack[i]<<endl;
        }
    }
}