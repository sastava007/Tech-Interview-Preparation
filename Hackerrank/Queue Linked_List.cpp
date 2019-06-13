#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct queue_LL
{
    struct node *rear;
    struct node *front;
};
void init(struct queue_LL *q)
{
    q->rear=NULL;
    q->front=NULL;
}
struct node * create_node()
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    return new_node;
}
void enqueue_LL(struct queue_LL *q,int ele)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->next=NULL;
    if((q->rear==q->front)&&q->front==NULL)
    {
        q->rear=new_node;
        q->front=new_node;
    }
    else
    {
        q->rear->next=new_node;
        q->rear=new_node;
    }
}
void dequeue_LL(struct queue_LL *q)
{
    if(q->front==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        struct node *r;
        r=q->front;
        int ele=q->front->data;
        q->front=q->front->next;
        cout<<ele<<" ";
        free(r);
    }
}
main()
{
    struct queue_LL q;
    init(&q);
    int c,ele;
    while(1)
    {
        cout<<"Enter Your Choice"<<endl<<"1. Enqueue_LL"<<endl<<"2. Dequeue_LL"<<endl<<" EXIT"<<endl;
       cin>>c;
       if(c==1)
       {
           cin>>ele;
           enqueue_LL(&q,ele);
       }
       else if(c==2)
       {
           dequeue_LL(&q);
       }
       else
        exit(1);
    }

}
