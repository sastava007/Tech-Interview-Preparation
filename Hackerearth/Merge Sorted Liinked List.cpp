#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node *next;};

struct node *p=NULL;
struct node *q=NULL;
struct node* create_node()
{
  struct node *new_node;
  new_node=(struct node*)malloc(sizeof(struct node));
  return new_node;
}
void insert(struct node **start,int ele)
{
  struct node *new_node=create_node();
  new_node->data=ele;
  new_node->next=NULL;
  if(*start==NULL)
    *start=new_node;
  else
  {
      struct node *t=*start;
      while(t->next!=NULL)
        t=t->next;
      t->next=new_node;
  }
}
void Movenode(struct node** destRef, struct node** sourceRef)
{
    /* the front source node  */
    struct node* newnode = *sourceRef;
    assert(newnode != NULL);

    /* Advance the source pointer */
    *sourceRef = newnode->next;

    /* Link the old dest off the new node */
    newnode->next = *destRef;

    /* Move dest to point to the new node */
    *destRef = newnode;
}

struct node* SortedMerge(struct node* a, struct node* b)
{
  struct node* result = NULL;

  /* point to the last result pointer */
  struct node** lastPtrRef = &result;

  while(1)
  {
    if (a == NULL)
    {
      *lastPtrRef = b;
       break;
    }
    else if (b==NULL)
    {
       *lastPtrRef = a;
       break;
    }
    if(a->data <= b->data)
    {
      Movenode(lastPtrRef, &a);
    }
    else
    {
      Movenode(lastPtrRef, &b);
    }

}
}
void view_node(struct node *start)
{
    struct node *t;
    if(start==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        t=start;
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
    }
}
main()
{
    int n,ele,i;
    cin>>n;
    cout<<"Enter elements of 1st LL"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        insert(&p,ele);
    }
    view_node(p);
    cout<<"Enter elements of 2nd LL"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        insert(&q,ele);
    }
    view_node(q);
    struct node *start=SortedMerge(p,q);
    view_node(start);
}
