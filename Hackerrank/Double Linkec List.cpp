#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *prev,*next;
};
struct node *start=NULL;
void insert_first(int ele)
{
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->prev=NULL;
    new_node->next=NULL;
    if(start==NULL)
        start=new_node;
    else
    {
        start->prev=new_node;
        new_node->next=start;
        start=new_node;
    }
}
void insert_bw(int ele,int after_ele)
{
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->prev=NULL;
    new_node->next=NULL;
    struct node *temp=start,*t;
    while(temp->data!=after_ele)
        temp=temp->next;
        t=temp->next;
        new_node->next=t;
        new_node->prev=temp;
        temp->next=new_node;
}
void insert_last(int ele)
{
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->prev=NULL;
    new_node->next=NULL;
    if(start==NULL)
        start=new_node;
    else
    {
        struct node *temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        new_node->prev=temp;
        temp->next=new_node;
    }
}
void delete_first()
{
    struct node *r;
    if(start==NULL)
        cout<<"Underflow";
    else
    {
        r=start;
        start=start->next;
        start->prev=NULL;
        free(r);
    }
}
void view_node()
{
    struct node * temp=start;
    while(temp!=NULL)
    {   cout<<temp->data<<" ";
        temp=temp->next;
    }
}
main()
{
    insert_first(10);
    insert_first(20);
    insert_first(70);
    insert_first(80);
    view_node();
    cout<<endl;
    insert_bw(69,20);
    view_node();
    cout<<endl;
    insert_last(500);
    view_node();
}

