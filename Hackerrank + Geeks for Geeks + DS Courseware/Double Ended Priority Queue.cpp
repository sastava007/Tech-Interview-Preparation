//USING Double Linked List.

#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    int priority;
    struct node *prev;
    struct node *next;
};
struct DEPQ
{
    struct node *head;
    struct node *tail;
};
void init(struct DEPQ *q)
{
    q->head=NULL;
    q->tail=NULL;
}
void enqueue(struct DEPQ *q,int ele,int priority)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->priority=priority;
    new_node->prev=NULL;
    new_node->next=NULL;
    if(q->head==q->tail && q->head==NULL)
    {
        q->head=new_node;
        q->tail=new_node;
    }
    else if(new_node->priority < q->head->priority)
    {
        new_node->next=q->head;
        q->head->prev=new_node;
        q->head=new_node;
    }
    else if(new_node->priority > q->tail->priority)
    {
        q->tail->next=new_node;
        new_node->prev=q->tail;
        q->tail=new_node;
    }
    else
    {
        struct node *temp=q->head;
        while(temp->next!=NULL && new_node->priority > temp->next->priority)
            temp=temp->next;
        new_node->next=temp->next;
        temp->next->prev=new_node;
        new_node->prev=temp;
        temp->next=new_node;
    }
}
void getmax(struct DEPQ *q)
{
    if(q->head==q->tail && q->tail==NULL)
        cout<<"Underlow"<<endl;
    else
    {
        cout<<q->head->data<<endl;
    }
}
void getmin(struct DEPQ *q)
{
    if(q->head==q->tail && q->tail==NULL)
        cout<<"Underlow"<<endl;
    else
    {
        cout<<q->tail->data<<endl;
    }
}
void delete_max(struct DEPQ *q)
{
    struct node *r=q->head;
    q->head=q->head->next;
    free(r);
}
void delete_min(struct DEPQ *q)
{
    struct node *r;
    r=q->tail;
    q->tail=q->tail->prev;
    free(r);
}
main()
{
    struct DEPQ q;
    init(&q);
    enqueue(&q,6, 3);
    enqueue(&q, 4, 1);
    enqueue(&q, 5, 2);
    enqueue(&q, 7, 0);
    getmax(&q);
    delete_max(&q);
    getmax(&q);
        getmin(&q);
    delete_min(&q);
    getmin(&q);
}
