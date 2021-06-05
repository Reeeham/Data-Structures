#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *top = NULL;

void display();
void push(int value);
int pop();
int peek();

int main()
{
    push(10);
    push(5);
    push(16);
    display();
    pop();
    display();
    cout << peek();
    
    return 0;
}

void display()
{
    node *currentNode;
    if (top == NULL)
    {
        cout << "stack is empty";
    }
    else
    {
        currentNode = top;
        while (currentNode != NULL)
        {
            cout << currentNode->data << "\n";
            currentNode = currentNode->next;
        }
    }
    cout << endl;
}

void push(int value)
{
    node *newNode = new node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    int value;

    if (top == NULL)
    {
        cout << "stack underflow";
        return -1;
    }
    else
    {
        node *firstNode = top;
        top = firstNode->next;
        value = firstNode->data;
        delete (firstNode);
        return value;
    }
}

int peek(){
    if(top == NULL){
           cout << "stack underflow. \n";
        return -1;
    }else{
        return top->data;

    }
}