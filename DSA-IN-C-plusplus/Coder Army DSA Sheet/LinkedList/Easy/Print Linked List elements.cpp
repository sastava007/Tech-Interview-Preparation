//{ Driver Code Starts
#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
}*start;

void insert();

// } Driver Code Ends
/*
  Print elements of a linked list on console 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     Node *next;
  }
*/

class Solution
{
    public:
    void display(Node *head)
    {
      //your code goes here
      
      while(head != NULL){
          cout<<head->data<<" ";
          head = head->next;
      }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      start=NULL;
      insert();
      Solution ob;
      ob.display(start);
      cout<<endl;
    }
    return 0;

}


 void insert()
 {
     int n,value;
     cin>>n;
     struct Node *temp;
     for(int i=0;i<n;i++)
     {
         cin>>value;
         if(i==0)
         {
              start=(struct Node *) malloc( sizeof(struct Node) );
              start->data=value;
              start->next=NULL;
              temp=start;
              continue;
         }
         else
         {
             temp->next= (struct Node *) malloc( sizeof(struct Node) );
             temp=temp->next;
             temp->data=value;
             temp->next=NULL;
         }
     }
 }


// } Driver Code Ends
