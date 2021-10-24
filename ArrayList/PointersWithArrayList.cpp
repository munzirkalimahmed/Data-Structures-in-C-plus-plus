#include<iostream>
using namespace std;
class ArrayList{
    private:
        int *arr;
        int max_size;
        int *curr,*temp;
        int len;

    public:
        ArrayList(int size)
        {
            len = 0;
            arr = new int[size];
            max_size = size;
            curr = nullptr;
            temp =nullptr;
        }

        ~ArrayList()
        {
            delete [] arr;
        }

        void Start()
        {
            curr = arr;
        }
        
        void End()
        {
          Start();
          curr = curr+(max_size-1);
        }
        
        void Next()
        {
          curr++;
        }
        
        void Back()
        {
          curr--;
        }

       ArrayList(ArrayList& othrList)
       {
	          max_size = othrList.max_size;
	          len = othrList.len;
	
	          for(int i=0;i<max_size;i++)
            {
	              arr[i] = othrList.arr[i];

	          }
	
	      }

        void clear()
        {
	
		      temp=arr;

		      for(int i=0;i<len;i++)
          {
		        *temp=0;
		        temp++;
		      }

	len=0;
	}
       void Length()
        {
          Start();
          while(curr != (arr + max_size))
          {
            len++;
            curr++;
          }
        }

      void insert(int value,int pos)
      {
	
		      cout<<"position is :"<<pos<<endl;
		      cout<<"length is: "<<len<<endl;

		      if(pos > max_size || pos <= 0)
          {
			        cout<<"index/position out of bounds"<<endl;
			        return;
		      }
		      if((len == 0 && pos != 1) || (len != 0 && pos > len+1))
          {
			
			      cout<<"Invalid position!!!!";
		
		      }

		      else
		      {

			      Start();
			      for(int i=1;i<pos;i++)
            {
			          curr++;
			      }
			
			      if(pos ==  len+1)
            {
				        *curr=value;
				        len++;
				        return;
			      }

			      for(int i=1;i<len;i++)
            {
			          temp++;
			      }

			      while(temp>=curr)
            {
			          *(temp+1)=*temp;
			          temp--;
			      }

			      *curr=value;
			      len++;
		      }

	    }
        
        void Update(int val,int pos)
        {
          Start();
          for(int i=1; i<=pos; i++)
          {
            if(i==pos)
            {
              *curr = val;
            }
            curr++;
          }


        }
        void remove(int pos)
        {
    
          Start();
          for(int i=1;i<pos;i++)
          {
            curr++;
          }
    
          temp=curr;

          for(int i=pos-1;i<len;i++)
          {
            *temp=*(temp+1);
            temp++;
          }
          len--;
        }
  
  
      int get(int pos)
      {
	      temp=arr;
	
	      for(int i=1;i<pos;i++)
        {
	        temp++;
	      }
	      return *temp;
	    }
          
    void Add(int value)
    {
      Start();
      while(curr<=(arr+len-1))
      {
        curr++;
      }
    *curr=value;
    }



};


int main()
{
  ArrayList l1(4);
  l1.Start();
  l1.Next();
  l1.Back();
  l1.End();
  l1.Length();
  l1.Update(14,2);
  l1.remove(2);
  l1.get(3);
  l1.Add(3);
   return 0;
}
