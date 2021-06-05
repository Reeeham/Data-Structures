#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = NULL;

void insertNode(int value);
void display();
void deleteNode(int value);
void insertBegin(int value);
void deleteBegin();
void deleteEnd();
int main()
{
    insertNode(5);
    insertNode(10);
    insertNode(15);
    insertNode(7);
    display();
    deleteNode(15);
    display();
    insertBegin(10);
    display();
    deleteBegin();
    display();
    return 0;
}

void insertNode(int value)
{
    node *newNode, *last;
    newNode = new node;
    newNode->data = value;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        last = head;
        while (last.next != NULL)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = NULL;
    }
}

void display()
{
    node *currentNode;
    if (head == NULL)
    {
        cout << "linked list is empty";
    }
    else
    {
        currentNode = head;
        while (currentNode != NULL)
        {
            cout << currentNode->data << "\t";
            currentNode = currentNode->next;
        }
    }
    cout << endl;
}
void deleteNode(int value)
{
    node *current, *prev;
    current = head;
    prev = head;

    if (current - > data == value)
    {
        head = current->next;
        free(current);
        return;
    }
    while (current->data != value)
    {
        prev = current;
        current = current->next;
    }

    prev->next = current->next;
    free(current);
}

void insertBegin(int value)
{
    node *newNode = new node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void deleteBegin()
{
    if (head == NULL)
    {
        cout << "linked list is empty"
    }
    else
    {
        node *firstNode = head;
        head = firstNode->next;
        delete (firstNode);
    }
}

void deleteEnd(){
    if(head == NULL) //  node nodes
    {
         cout << "linked list is empty";
         
    }else if(head -> next == NULL) { //one node
        delete(head);
        head = NULL;
    }else{
        node *ptr = head;
        while(ptr->next->next != NULL){
            ptr = ptr->next;
        }
        delete(ptr->next);
        ptr->next = NULL;
    }
}