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

class CircularLinkedList : public Node
{
    private:
        Node *head;
        Node *curr, *curr1;

    public:
        CircularLinkedList()
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
                head->next = head;
            }
            else if (pos == 1)
            {
                Node *n = new Node;
                n->data = val;
                n->next = curr;
                curr->next = n;
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
      void Add(int val)
        {
            if (head == NULL)
            {
                head = new Node;
                head->data = val;
                head->next = head;
                return;
            }
            curr = head;
            while (curr->next!=head)
            {
                
                    curr1 = new Node;
                    curr1->data = val;
                    curr1->next = curr->next;
                    curr->next=curr1;
                    return;
            }
        }

        void Delete(int val)
        {
          if (head == NULL)
          {
            return;
          }
          curr = head;
          curr1 = head;
          while (curr != NULL)
          {
            if(curr->next->data == val )
            {

                curr1 = curr->next;
                curr->next = curr1->next;
                delete curr1;
                return;
            }
            if(curr->data == val)
            {
                curr1 = curr->next->next;
                head = curr->next;
                curr1->next = head;
                delete curr;
                return;
            }
            
            curr = curr->next;
            
          }
        }
};
int main()
{
    Node n;
    CircularLinkedList l1;
    l1.insert(1,1);
    l1.insert(2,2);
    l1.insert(3,3);
    l1.Add(4);
    l1.Add(5);
    l1.Delete(3);


}