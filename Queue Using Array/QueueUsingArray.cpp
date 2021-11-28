#include <iostream>
using namespace std;

class Queue{
    private:
        int *front;
        int *rear;
        int *que;
        int size;
    
    public:
        Queue(int s)
        {
            size = s;
            que = new int[size];
            front = NULL;
            rear = NULL;
        }
        void Enqueue(int val)
        {
            if(rear == NULL)
            {
                rear = que;
                front = que;
                *rear = val;
                
                return;
            }
            if((rear == que+size-1 && front == que ) || (rear+1 == front))
            {
                cout << "que is Full" << endl;
                return;
            }
            if (rear == que+size-1)
            {
                rear = que;
                *rear = val;
                return;
            }
             rear++;
                *rear = val;
               
            
        }


        void Dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is Empty" << endl;
            return;
        }
        if (front == rear)
        {
            front = NULL;
            rear = NULL;
            return;
        }
        if (front == que+size-1)
        {
            front = que;
            return;
        }
        front++;
        
        
    }
    void Print()
        {
          if (front == NULL)
          {
            return;
          }
            int *temp = front;
            while (temp != rear)
            {
                cout << *temp << endl;
                if (temp == que+size-1)
                {
                    temp = que;
                }
                else
                {
                    temp++;
                }
                if (temp == rear)
                {
                    cout << *temp << endl;
                }            
            }   
        } 
 

};
int main()
{
    Queue q(4);
    q.Dequeue();
    q.Enqueue(1);
    q.Dequeue();
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Enqueue(6);
    q.Dequeue();
    q.Dequeue();
    q.Enqueue(7);
    q.Print();
}