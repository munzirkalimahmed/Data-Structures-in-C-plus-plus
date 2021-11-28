#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next=NULL;
};
class Queue
{
    private:
        Node *front;
        Node *rear;
        Node *que;
    public:
        Queue()
        {
            que = NULL;
            front = NULL;
            rear = NULL;
        }
         void Enqueue(int val)
        {
            if (que == NULL)
            {
                que = new Node;
                que->data = val;
                que->next = NULL;
                return;
            }
            else
            {
                           
              rear = que;
              while (rear->next != NULL)
              {
                rear = rear->next;
              }
            
              Node *n = new Node;
              n->data = val;
              rear->next = n;
              n->next = NULL;
      
            }
            
        }
        void Dequeue()
        {
            if (front == NULL)
            {
                cout << "Queue is empty" << endl;
                return;
            }
            if (front == rear)
            {
                front = NULL;
            }
            if (front->next == NULL)
            {
                front = que;
                return;
            }
            front++;
        }
};

int main()
{
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Dequeue();
    q.Dequeue();
}
