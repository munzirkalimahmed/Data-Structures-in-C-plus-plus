#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next, *prev;
        Node()
        {   
            data = 0;
            next = NULL;
            prev = NULL;
        }
};

class DoublyLinkedList : public Node
{
    private:
        Node *head;
        Node *curr, *curr1;

    public:
        DoublyLinkedList()
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
                head->prev = NULL;
                head->next = NULL;
            }
            else if (pos == 1)
            {
                Node *n = new Node;
                n->data = val;
                n->next = curr ->prev;
                curr->prev = n;
                n->next = curr;
                head = n;
                head->prev = NULL;
            }
            else
            {
                for (int i = 2; curr!=NULL; i++)
                {
                    if (pos == i)
                    {
                        Node *n = new Node;
                        n->data = val;
                        n->next = curr->next;
                        n->prev = curr;
                        if ( curr->next != NULL)
                        {
                          curr->next->prev = n;
                        }                        
                        curr->next = n;
                    }
                    curr = curr->next;
                }
                
            }    
            
        }

     void Add(int val)
        {
            if (head == NULL)
            {
                head = new Node;
                head->data = val;
                head->next = NULL;
                head->prev = NULL;
                return;
            }
            
            curr = head;
            while (curr->next != NULL)
            {
              curr = curr->next; 
            }
                curr1 = curr->prev;
                Node *n = new Node;
                n->data = val;
                curr->next = n;
                n->prev = curr;
                n->next = NULL;
                       
        }
   void Remove(int val)
    {
        if (head == NULL)
        {

            return;
        }
        curr = head;
        curr1 = head;
        while (curr!=NULL)
        {
            if (curr->data == val)
            {
                curr1 = head;
                curr1 = curr1->next;
                curr1->prev = NULL;
                head = curr1;
                delete curr;
                return;
            }            
            else
            {
              if(curr->next->data == val)
              {
                 curr1 = curr->next;
                 curr->next = curr1->next;
                 
                 if (curr->next != NULL)
                 {
                    curr1->next->prev = curr;
                 }
                 
                 delete curr1;
                 return;
              }  
            }  
            curr = curr->next;
        }
    }
};
int main()
{
    Node n;
    DoublyLinkedList l1;
    l1.insert(1,1);
    l1.insert(2,2);
    l1.insert(3,3);
    l1.Add(5);
    l1.Add(4);
    l1.Remove(2);
}