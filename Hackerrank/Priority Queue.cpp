#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    int priority;
    struct node *next;
};
struct node *start=NULL;
bool isempty()
{
    return(start==NULL);
}
void enqueue(int ele,int priority)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->priority=priority;
    new_node->next=NULL;
    if(start==NULL)
    {
        start=new_node;
    }
    else if(new_node->priority<start->priority)
    {
        new_node->next=start;
        start=new_node;
    }
    else
    {
        struct node *temp=start;
        while(temp->next!=NULL && new_node->priority > temp->next->priority)
            temp=temp->next;
         new_node->next=temp->next;
         temp->next=new_node;
    }
}
void peek()
{
  if(isempty())
    {
        cout<<"Underflow"<<endl;
        return;
    }
    cout<<start->data<<endl;
}
void dequeue()
{
    struct node *r=start;
    start=start->next;
    free(r);
}
main()
{
    enqueue(6, 3);
    enqueue(4, 1);
    enqueue(5, 2);
    enqueue(7, 0);
    peek();
    dequeue();
    peek();
    dequeue();
    peek();
}
