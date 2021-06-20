#include <iostream>
using namespace std;

class BST
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;

        Node(int value){
            data = value;
            left = nullptr;
            right = nullptr;
        }
    };
    Node *root = nullptr;

    void addHelper(Node *temp, int value)
    {
        if (value <= temp->data)
        {
            if (temp->left == nullptr)
            {
                Node *newNode = new Node(value);

                temp->left = newNode;
            }
            else
            {
                addHelper(temp->left, value);
            }
        }
        else
        {
            if (temp->right == nullptr)
            {
                Node *newNode = new Node(value);

                temp->right = newNode;
            }
            else
            {
                addHelper(temp->right, value);
            }
        }
    }
    int getMaxHelper(Node* temp){
        if(temp->right == nullptr)
        {
            return temp->data;
        }else{
            return getMaxHelper(temp->right);
        }
    }
    int getMinHelper(Node* temp){
        if(temp->left == nullptr)
        {
            return temp->data;
        }else{
            return getMinHelper(temp->left);
        }
    }
    int getHeightHelper(Node* temp){
        if( temp == nullptr)
        {
            return -1;
        }else{
            int leftSubtree = getHeightHelper(temp ->left);
            int rightSubtree = getHeightHelper(temp->right);
              return 1+ max(leftSubtree,rightSubtree);
        }

      
    }

public:
    void add(int value)
    {
        if (root == nullptr)
        {
            Node *newNode = new Node(value);
            root = newNode;
        }
        else
        {
            addHelper(root, value);
        }
    }
    int getMin(){
        return getMinHelper(root);
    }
    int getMax(){
        return getMaxHelper(root);
    }
    int getHeight(){
        if( root == nullptr){
            return -1;
        }else{
            return getHeightHelper(root);
        }
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