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

        void AddEnd(int val)
        {
            if (head == NULL)
            {
                Node *n = new Node;
                n->data = val;
                head = n;
                head->next = NULL;
                return;
            }
            
            curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            
            Node *n = new Node;
            n->data = val;
            curr->next = n;
            n->next = NULL;
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
                for (int i = 2; i<=val; i++)
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
        void Delete(int val)
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

        void Search(int val)
        {
          if (head == NULL)
          {
            return;
          }
          curr = head;
          while(curr!=NULL)
          {
            if (curr->data == val)
            {
              cout << "value found" << endl;
              return;
            }
              curr = curr->next;                      

          }
          cout << "value not found" << endl;
          
        }

        void Print()
        {
            curr = head;
            if (head == NULL)
            {
                return ;
            }
            while (curr != NULL)
            {
                cout << curr->data << endl;
                curr = curr->next;
            }   
        }

        
      
};

int main()
{
    Node n;
    LinkedList l1;
    l1.AddEnd(2);
    l1.AddEnd(3);
    l1.insert(4,1);
    l1.insert(5,2);
    l1.Delete(2);
    l1.Search(4);
    l1.Print();


    return 0;
}


