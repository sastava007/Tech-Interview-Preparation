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
    struct node *temp1=start,*temp2,*r;
    int c=0;
    if(del==1)
    {
        r=start;
        start=start->next;
        free(r);
    }
    else
    while(c!=del-2)
    {
        c++;
      temp1=temp1->next;
    }
    temp2=temp1->next;
    r=temp1;
    temp1->next=temp2->next;
    free(r);
}
int main()
{
    int n,ele,del;
    cout<<"Enter Number of elements";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        insert(ele);
    }
    cout<<"Enter node number to delete"<<endl;
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

