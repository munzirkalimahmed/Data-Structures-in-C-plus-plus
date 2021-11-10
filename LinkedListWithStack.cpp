#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node()
        {
            data = 0;
            next = NULL;
        }
};

class LinkedList : public Node
{
    private:
        Node *head;
        Node *curr, *curr1;

    public:
        LinkedList()
        {
            head = NULL;
            curr = NULL;
            curr1 = NULL;
        }

 
    void insert(int val, int pos)
        {
            curr = head;
            if (head == NULL)
            {
                head = new Node();
                head->data = val;
                head->next = NULL;
            }
            else if (pos == 1)
            {
                Node *n = new Node;
                n->data = val;
                n->next = curr;
                head = n;
            }
            else
            {
                for (int i = 2; i<=pos; i++)
                {
                    if (pos == i)
                    {
                        Node *n = new Node;
                        n->data = val;
                        n->next = curr->next;
                        curr->next = n;
                    }
                    curr = curr->next;
                }
                
            }    
            
        }
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        
    }

    void remove(int val)
        {
          if (head == NULL)
          {
            return;
          }
          curr = head;
          curr1 = head;
          while (curr1 != NULL)
          {
            if(curr1->next->data == val )
            {
                curr = curr1;
                curr1 = curr->next;
                curr->next = curr1->next;
                
                curr1->next = NULL;
                delete curr1;
                return;
            }
            if(curr1->data == val)
            {
                head = curr1->next;
                curr = curr1->next;

                delete curr1;
                return ;
            }
            
            curr1 = curr1->next;
            
          }
        }

    int get(int pos)
    {
        if (head == NULL)
        {
            return -105;
        }
        curr = head;
        for (int i = 1; i <= pos; i++)
        {
            if (i == pos)
            {
                cout << curr->data << endl;
                return curr->data;
            }
            curr = curr->next;
            
        }  
    }




 
};

class Stack
{
    private:
        LinkedList l;
    public:
        void push(int val)
        {
            l.insert(val,1);
            cout << val <<endl;
        }
        int pop()
        {
            if (l.isEmpty())
            {
                cout << "Overflow" << endl;
                return -105;
            }
            else
            {
                int val = l.get(1);
                //cout << val << endl;

                l.remove(val);
                //cout << val << endl;

                return val;    





            }
            
            
        }
};
int main()
{
    Node n;
    Stack l1;
    l1.push(2);
    l1.push(3);
    l1.push(4);
    l1.pop();
    l1.pop();
    l1.pop();
    
}
