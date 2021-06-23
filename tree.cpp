#include <iostream>
#include <queue>
using namespace std;

class BST
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
    };
    Node *root = nullptr;
   int getMaxHelper(Node* temp){
        if(temp->right == nullptr)
        {
            return temp->data;
        }else{
            return getMaxHelper(temp->right);
        }
    }    
    void preOrder(Node *temp)
    {
        if (temp == nullptr)
            return;
        cout << temp->data << " ";
        preOrder(temp->left);
        preOrder(temp->right);
    }
    void inOrder(Node *temp)
    {
        if (temp == nullptr)
            return;
        inOrder(temp->left);
        cout << temp->data << " ";
        inOrder(temp->right);
    }
    void postOrder(Node *temp)
    {
        if (temp == nullptr)
            return;
        inOrder(temp->left);
        inOrder(temp->right);
        cout << temp->data << " ";
    }
    Node* removeHelper(Node* root, int data){
        if(root == nullptr) return root;
        else if(data < root->data)
                root->left = removeHelper(root->left,data);
        else if(data > root->data)
                root->right = removeHelper(root->right,data);
        else{
            if(root->left == nullptr){
                Node* temp = root->right;
                delete temp;
                return temp;
            }
            else if( root->right == nullptr){
                Node* temp = root->left;
                delete root;
                return temp;
            }else { 
                int maxValue = this->getMaxHelper(root->left);
                root->data = maxValue;
                root->left = removeHelper(root->left, maxValue);
            }
        }
        return root;
    }

public:
    void add(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        Node *temp = root;
        Node *parent = nullptr;
        while (temp != nullptr)
        {
            parent = temp;
            if (value < -temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        if (value <= parent->data)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
    }

    int getMax()
    {
        Node *temp = root;
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        return temp->data;
    }
    int getMin()
    {
        Node *temp = root;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp->data;
    }
    int getHeight()
    {
        return 0;
    }
    void display_levelOrder()
    {
        if (root == nullptr)
            return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();
            cout << current->data << " ";
            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
        cout << endl;
    }
    void display_preOrder()
    {
        if (root != nullptr) preOrder(root);
    }
    void display_inOrder(){
        if(root != nullptr) inOrder(root);
    }
    void display_postOrder(){
        if(root != nullptr) postOrder(root);
    }
    void remove(int data){
        root = removeHelper(root,data);
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
    obj.display_preOrder();
    obj.display_inOrder();
    obj.remove(5);
    obj.display_postOrder();
    cout << obj.getMax() << endl;
    cout << obj.getMin() << endl;

    system("pause");
    return 0;
}
