#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct dequeue
{
    struct node *rear;
    struct node *fron;
};
void init(struct dequeue *q)
{
    q->rear=NULL;
    q->fron=NULL;
}
void insert_fron(struct dequeue *q,int ele)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->next=NULL;
    new_node->prev=NULL;
    if(q->fron==NULL)
    {
        q->rear=new_node;
        q->fron=new_node;
    }
    else
    {
        new_node->next=q->fron;
        q->fron->prev=new_node;
        q->fron=new_node;
    }
}
void insert_rear(struct dequeue *q,int ele)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->next=NULL;
    if(q->rear==NULL)
    {
        q->rear=new_node;
        q->fron=new_node;
    }
    else
    {
        q->rear->next=new_node;
        new_node->prev=q->rear;
        q->rear=new_node;
    }
}
void delete_fron(struct dequeue *q)
{
    if(q->fron==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        struct node *r=q->fron;
        cout<<r->data;
        q->fron=q->fron->next;
        q->fron->prev=NULL;
        free(r);
    }
}
void delete_rear(struct dequeue *q)
{
    if(q->fron==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        struct node *r=q->rear;
        cout<<r->data;
        q->rear=q->rear->prev;
        q->rear->next=NULL;
        free(r);
    }
}
main()
{
    struct dequeue q;
    init(&q);
    insert_fron(&q,10);
    insert_fron(&q,20);
     insert_fron(&q,50);
    insert_fron(&q,60);
    insert_rear(&q,30);
    insert_rear(&q,40);
    delete_fron(&q);
    delete_rear(&q);
}
