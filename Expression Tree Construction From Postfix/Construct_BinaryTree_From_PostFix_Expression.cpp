#include <iostream>
using namespace std;

struct Node
{
    char val;
    Node *left;
    Node *right;
};

class ExpressionTree
{
    public:
        Node *root;
        Node *arr[10];
        int top;
    public:
        ExpressionTree()
        {
            top = -1;
        }
    void insert(int key)
    {
        if (key >= 'a' && key <= 'z' )
            {
                Node *temp = new Node;
                temp->val = key;
                temp->left = NULL;
                temp->right = NULL;
                push(temp);
            }
          else if (key == '+' || '-' || '*' || '/')
            {
                Node *temp = new Node;
                temp->val = key;
                temp->right = pop();
                temp->left = pop();
                push(temp);
            }
            
            
            else
            {
                return;
            }   
    }
    Node *push(Node *data)
    {
        top++;
        arr[top] = data;
    }
    Node *pop() 
    {
      top--;
      return (arr[top + 1]);
    }

    
    // Traveral in In-Order:
    void Traversal(Node *root)
    {
        if (root != NULL) 
        {
            Traversal(root->left);
            cout << root->val << " ";
            Traversal(root->right);
        }
    }

};

int main()
{
    ExpressionTree t1;
    t1.insert('a');
    t1.insert('b');
    t1.insert('+');
    t1.insert('c');
    t1.insert('d');
    t1.insert('e');
    t1.insert('+');
    t1.insert('*');
    t1.insert('*');
    t1.Traversal(t1.arr[0]);
}