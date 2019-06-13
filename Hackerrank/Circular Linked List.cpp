#include<bits/stdc++.h>
using namespace std;
struct node
{
int data;
struct node *next;
};

struct node *last=NULL;
struct node * insert_firstvalue(int ele)
{
    if(last==NULL)
    {
        struct node *new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=ele;
        new_node->next=NULL;
        last=new_node;
        return last;
    }
}
void insert_last(int ele)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->next=NULL;

    new_node->next=last->next;
    last->next=new_node;
    last=new_node;
}
void create_node()
{
    int ele,n;
    cout<<"Enter first value"<<endl;
    cin>>ele;
    struct node *last=insert_firstvalue(ele);
    cout<<"Enter total number of elements in Linked list"<<endl;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        cin>>ele;
        insert_last(ele);
    }
}
void insert_beg()
{
    int ele;
    cout<<"Enter value to Add at Beginning"<<endl;
    cin>>ele;
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->next=NULL;
    new_node->next=last->next;
    last->next=new_node;
}
void display()
{
    struct node * temp=last->next;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=last->next);
}
void insert_after()
{
    int ele,after;
    cout<<"Enter element to be added and after which"<<endl;
    cin>>ele>>after;
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->next=NULL;
    struct node *temp=last->next;
    while(temp->data!=after)
    temp=temp->next;
    new_node->next=temp->next;
    temp->next=new_node;
    if(temp==last)
        last=new_node;
}
main()
{
    create_node();
    insert_beg();
    insert_after();
    display();

}

