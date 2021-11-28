#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node* left;
    Node* right;

};

class BST
{

    public:

        Node* root;


        BST()
        {
            root = NULL;
        }

        void insert(int key, Node *& temp)
        {
            if(temp==NULL)
            {
                temp = new Node;
                temp->val = key;
                temp->left = NULL;
                temp->right = NULL;
                return;
            }
            
        
            if(temp->val == key)
            {
                cout<<"Already Exists."<<endl;
                return;
            }

            if(key>temp->val)
            {
                insert(key,temp->right);
                return;
            }
            if(key<temp->val)
            {
                insert(key,temp->left);
            }
        }

       Node *search(int key , Node *root)
       {
           if(root->val == NULL)
           {
              return NULL ;
           }
           if(root->val == key)
           {
               cout << "value found" << endl;
               return root;
           }
           if (root->val > key)
           {
              if (root->left == NULL)
              {
                cout << "Value not found" << endl;
                return NULL;
              }
               root = root->left;
               search(key,root);
                

           }
           else if (root->val < key)
           {
             if (root->right == NULL)
              {
                cout << "Value not found" << endl;
                return NULL;
              }
               root = root->right;
               search(key,root);
               
           }
           else
           {
             return root;
           }
           
       }

// Traveral in In-Order:

 void Traversal(Node *root)
 {
     if (root == NULL)
     {
         return;
     }
     else
     {
         Traversal(root->left);
     }
     cout << root->val << endl;
     Traversal(root->right);
     
 }
// Traveral in Pre-Order:
/* void Traversal(Node *root)
 {
     if (root == NULL)
     {
         return;
     }
     else
     {
         cout << root->val << endl;
         Traversal(root->left);
     }
     Traversal(root->right);
     
 }*/

 // Traveral in post-Order:
 /*void Traversal(Node *root)
 {
     if (root == NULL)
     {
         return;
     }
     else
     {
         Traversal(root->left);
     }
     Traversal(root->right);
    cout << root->val << endl;   
 }*/

Node *sucessor(int key, Node *root)
{
    Node *temp = search(key,root);
    if ( temp == NULL)
    {
      return NULL;
    }
    if(temp->right != NULL)
    {
        temp = temp->right;
      while(temp->left != NULL)
        {
            temp = temp->left;
        }  
    cout << temp->val << endl;
    return temp;
    }
    int val;
    if(temp->right == NULL)
    {
        while (root != temp)
        {
            if (temp->right == NULL)
            {
                val = root->val;    
            }
            if (root->val == temp->val)
            {
                return temp;
            }
            if (root->val > temp->val)
            {
                root = root->left;
                if (val > root->val)
                {
                    val = root->val;
                }
                
            }
            if (root->val < temp->val)
            {
                root = root->right;
                if (val < root->val)
                {
                    val = root->val;
                }
                
            }
            cout << val << endl;
            return temp;
        }
        
    }
 

} 

void predeceddor(int key, Node *root)
{
    Node *temp = search(key,root);
    if ( temp == NULL)
    {
      return;
    }
    if(temp->left != NULL)
    {
        temp = temp->left;
      while(temp->right != NULL)
        {
            temp = temp->right;
        }  
    cout << temp->val << endl;
    return;
    }
    int val;
    if(temp->right == NULL)
    {
        while (root != temp)
        {
            if (temp->right == NULL)
            {
                val = root->val;    
            }
            if (root->val == temp->val)
            {
                return ;
            }
            if (root->val > temp->val)
            {
                root = root->left;
                if (val > root->val)
                {
                    val = root->val;
                }
                
            }
            if (root->val < temp->val)
            {
                root = root->right;
                if (val > root->val)
                {
                    val = root->val;
                }
                
            }
            cout << val << endl;
            return ;
        }
        
    }
 
}  

void remove(int key,Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Node *temp = search(key,root);
    if(temp == NULL)
    {
        return;
    }
    Node *temp1 = root;
    if (temp->val == key)
    {
        if (temp->left == NULL && temp->right == NULL)
        {
            while (temp1 != temp)
            {
                if (temp1->val < temp->val)
                {
                    temp1 = temp1->right;
                }
                else
                {
                    temp1 = temp1->left;
                }
                if (temp1->left == temp)
                {
                    delete temp;
                    temp1->left = NULL;
                    return;
                }
                if (temp1->right == temp)
                {
                    delete temp;
                    temp1->right = NULL;
                    return;
                }          
            }        
        } 
        if (temp->left != NULL && temp->right != NULL)
        {
            Node *temp1 = sucessor(temp->val, root);
            temp->val = temp1->val;
            if (temp->left != NULL && temp->right != NULL)
            {
                while (temp1 != temp)
                {
                    if (temp->left == temp1)
                    {
                        delete temp1;
                        temp->left = NULL;
                        return;
                    }
                    if (temp->right == temp1)
                    {
                        delete temp1;
                        temp->right = NULL;
                        return;
                    }
                    if (temp1->val >= temp->val)
                    {
                        temp = temp->right;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
            }
        }
        if (temp->right != NULL && temp->left == NULL)
        {
            while (temp1 != temp)
            {
                if (temp1->left == temp)
                {
                    temp1->left = temp->right;
                    delete temp;
                    return;
                }
                if (temp->right == temp)
                {
                    temp1->right = temp->left;
                    delete temp;
                    return; 
                }
                if (temp1->val > temp->val)
                {
                    temp1 = temp1->left;
                }
                else
                {
                    temp1 = temp1->right;
                }
                
            }
            
        }
        if (temp->left != NULL && temp->right == NULL)
        {
            while (temp1 != temp)
            {
                if (temp1->left == temp)
                {
                    temp1->left = temp->left;
                    delete temp;
                    return;
                }
                if (temp1->right == temp)
                {
                    temp1->right = temp->left;
                    delete temp;
                    return; 
                }
                if (temp1->val > temp->val)
                {
                    temp1 = temp1->left;
                }
                else
                {
                    temp1 = temp1->right;
                }         
                
            }
            
        }
        
    }

    
    
}
};
     
  

       


int main(){
    BST tree;
    tree.insert(10, tree.root);
    tree.insert(-1, tree.root);
    tree.insert(5, tree.root);
    tree.insert(4, tree.root);
    tree.insert(6, tree.root);
    tree.insert(20 ,tree.root);
    tree.insert(15 ,tree.root);
    tree.insert(100 ,tree.root);
    tree.insert(80 ,tree.root);
    tree.insert(70 ,tree.root);
    //tree.sucessor(400 ,tree.root);
    //tree.search(70, tree.root);
    //tree.predeceddor(100,tree.root);
    //tree.remove(-1,tree.root);
    tree.remove(50 , tree.root);
    tree.Traversal(tree.root);
    
}