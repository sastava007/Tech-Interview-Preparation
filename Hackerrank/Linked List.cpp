#include<bits/stdc++.h>
using namespace std;
struct node
{
int data;
struct node *next;
};

struct node *start=NULL;
struct node* create_node()
{
  struct node *new_node;
  new_node=(struct node*)malloc(sizeof(struct node));
  return new_node;
}
void insert(int ele)
{
  struct node *new_node=create_node();
  new_node->data=ele;
  new_node->next=NULL;
  if(start==NULL)
    start=new_node;
  else
  {
      struct node *t=start;
      while(t->next!=NULL)
        t=t->next;
      t->next=new_node;
  }
}

void reverse()
{
    struct node *prev=NULL,*next=NULL;
    struct node *current = start;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    start=prev;
}

int main()
{
    int n,ele;
    cout<<"Enter Number of elements";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        insert(ele);
    }
    struct node *temp=start;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    reverse();
    cout<<endl<<"After reversing linked list:"<<endl;
    struct node *temp2=start;
    while(temp2!=NULL)
    {
        cout<<temp2->data<<" ";
        temp2=temp2->next;
    }
    return 0;
}

