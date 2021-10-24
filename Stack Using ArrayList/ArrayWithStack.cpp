#include<iostream>
using namespace std;

class Stack
{
    private:
        int *arr;
        int top;    //index
        int size;

    public:
        Stack(int s)
        {
            size = s;
            arr = new int[size];
            top = -1;              //mtlb yeh khali hain
        }
        ~Stack()
        {
            delete []arr;
        }
     
        void posh(int val)
        {
            if (top == (size-1))   //IsFull
            {
                cout << "Overflow" << endl;
                return ;
            }
            arr[++top] = val;
        }

        int pop()
        {
            if (top == -1)    //IsEmpty
            {
                cout << "Underflow" << endl;
                return -105;
            }
            return arr[top--];
        }

        int peek()
        {
           if (top == -1)    //IsEmpty
            {
                cout << "Underflow" << endl;
                return -105;
            }
            return arr[top]; 
        }           
    
};

int main()
{
    Stack s1(4);
    s1.posh(2);
    s1.posh(3);
    s1.posh(4);
    s1.posh(5);
    s1.pop();
    s1.pop();
    s1.pop();
    s1.peek();
}