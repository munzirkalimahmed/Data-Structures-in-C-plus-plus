#include<iostream>
using namespace std;
struct Node
{
  int data;
  Node *Next=NULL;
};

class Stack
{
  Node *top;
  public:
  Stack()
  {
    top=NULL;
    }

  void insert(int val)
  {
    Node *n=new Node;
    n->data=val;
    if(top==NULL)
    {
        top=n;
    }
    else
    {
      n->Next=top;
      top=n;
    }
    }
    void remove(int pos)
    {
      if(pos==1)
      {
        Node *temp=new Node;
        temp=top;
        top=top->Next;
        delete temp;
        }
    }
    void get(int pos)
    {
      Node *temp=new Node;
      temp=top;
      for(int i=1;i<pos;i++)
      {
        temp=temp->Next;
        }
      cout<<temp->data<<endl;
      }
    bool is_Empty()
    {
      if(top==NULL)
      {
        cout<<"Underflow  "<<endl;
        return true;
        }
      else
      {
        return false;
        }
    }
  void push(int val)
  {
      insert(val);
    }
  void pop()
  {
    if(is_Empty())
    {
      return;
    }
    else
    {
      remove(1);
    }
  }
  void print()
  {
    if(is_Empty())
    {
      return;
      }
    else
    {
    while(top!=NULL)
    {
      cout<<top->data<<endl;
      pop();
        }
    }
  }
      };
int main() 
{
  Stack s1;
  s1.push(5);
  s1.push(6);
  s1.push(7);
  s1.push(8);
  s1.print();
  s1.pop();

  return 0;
}