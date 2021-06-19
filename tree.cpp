#include <iostream>
using namespace std;

class BST
{
private:
   struct Node{
    int data;
    Node* left;
    Node* right;
    };
    Node* root = nullptr;
public:
   void add(int value){
       Node* newNode= new Node;
       newNode -> data = value;
       newNode -> left = nullptr;
       newNode -> right = nullptr;
       if( root == nullptr){
           root = newNode;
           return;
       }
       Node* temp = root;
       Node* parent = nullptr;
       while(temp != nullptr){
           parent = temp;
           if(value <- temp->data)
           {
               temp = temp -> left;
           }else{
               temp = temp -> right;
           }
       }
       if(value <= parent->data){
           parent->left = newNode;
       }else{
           parent->right = newNode;
       }
   }

   int getMax(){
       Node* temp = root;
       while(temp->right != nullptr){
           temp = temp -> right;
       }
       return temp->data;
   }
   int getMin(){
       Node* temp = root;
       while(temp->left != nullptr){
           temp = temp -> left;
       }
       return temp->data;
   }
};

int main()
{
    BST obj;
    obj.add(8);
    obj.add(5);
    obj.add(13);
    obj.add(3);
    obj.add(7);
    obj.add(10);
    obj.add(15);

    cout << obj.getMax() << endl;
    cout << obj.getMin() << endl;

    system("pause");
    return 0;
}
