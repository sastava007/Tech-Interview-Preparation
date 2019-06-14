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
void delete_node(int del)
{
    struct node *temp=start,*r;
    while(temp!=NULL&&temp->next->data!=del)
    {
        temp=temp->next;
    }
    if(temp->next->data==del)
    {
    r=temp->next;
        temp->next=temp->next->next;
        free(r);
    }
    else
    {
    cout<<"Element not found";
    exit(0);
    }
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
    int del;
    cout<<"Enter element to delete"<<endl;
    cin>>del;
    delete_node(del);
    struct node *temp=start;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}

