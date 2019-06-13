#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct queue_list
{
        struct node *fron;
        struct node *rear;
};
void init(struct queue_list *q)
{
    q->rear=NULL;
    q->fron=NULL;
}
bool isempty(struct queue_list *q)
{
    if((q->rear==q->fron)&&q->fron==NULL)
        return true;
    else
        return false;
}
void enqueue_list(struct queue_list *q,int ele)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->next=NULL;
    if(isempty(q))
    {
        q->fron=new_node;
        q->rear=new_node;
    }
    else
    {
        q->rear->next=new_node;
        q->rear=new_node;
    }
}
void dequeue_list(struct queue_list *q)
{
    if(isempty(q))
        cout<<"Uunderflow"<<endl;
    else
    {
        struct node *r=q->fron;
        int data=q->fron->data;
        q->fron=q->fron->next;
        cout<<data<<endl;
        if(q->fron==NULL)
        {
            q->rear=NULL;
        }
        free(r);
    }
}
void print(struct queue_list *q)
{
    struct node *temp=q->fron;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
}
main()
{
  struct queue_list q;
  init(&q);
  int c,ele;
    while(1)
    {
        cout<<"Enter Your Choice"<<endl<<"1. Enqueue_list_LL"<<endl<<"2. Dequeue_list_LL"<<endl<<" EXIT"<<endl;
       cin>>c;
       if(c==1)
       {
           cin>>ele;
           enqueue_list(&q,ele);
       }
       else if(c==2)
       {
           dequeue_list(&q);
       }
       else if(c==3)
        {
            print(&q);
        }
       else
        exit(1);
    }

}
