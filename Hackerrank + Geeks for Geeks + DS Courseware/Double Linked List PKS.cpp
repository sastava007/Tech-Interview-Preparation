#include<bits/stdc++.h>
using namespace std;

struct node
{
int data;
struct node *prev;
struct node *next;
};
struct dlllist
{
    node *head;
    node *tail;
};
void init(struct dlllist *dll)
{
    dll->head=NULL;
    dll->tail=NULL;
}
void insert_node(struct dlllist *dll,int ele)
{

    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->prev=NULL;
    new_node->next=NULL;
    if(dll->head==NULL)
        {
            dll->head=new_node;
            dll->tail=new_node;
        }
    else
    {
        dll->tail->next=new_node;
        new_node->prev=dll->tail;
        dll->tail=new_node;
    }

}
void delete_node(struct dlllist *dll)
{
    if(dll->head==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        struct node *r=dll->tail;
        dll->tail->prev->next=NULL;
        free(r);
    }
}
// to delete a particular element lying in between the LL
void delete_bw(struct dlllist *dll,int key)
{
    struct node *temp=dll->head,*r;
    while(temp->data!=key)
        temp=temp->next;
    r=temp;
    r->prev->next=r->next;
    r->next->prev=r->prev;
    free(r);
}
void print_node(struct dlllist *dll)
{
    node *temp=dll->head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insert_head(struct dlllist *dll,int ele)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->prev=NULL;
    new_node->next=NULL;

    new_node->next=dll->head;
    dll->head->prev=new_node;
    dll->head=new_node;
}
void insert_bw(struct dlllist *dll,int key,int ele)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->prev=NULL;
    new_node->next=NULL;

    struct node *temp=dll->head;
    while(temp->data!=key)
        temp=temp->next;
    new_node->prev=temp;
    new_node->next=temp->next;
    temp->next->prev=new_node;
    temp->next=new_node;
}
void merge(struct dlllist *dl1,struct dlllist *dl2)
{
    if(dl1->head!=NULL&&dl2->head!=NULL)
       dl1->tail->next=dl2->head;
}
main()
{
    struct dlllist dl1,dl2;
    init(&dl1);
    init(&dl2);
    int n,ele,key;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        insert_node(&dl1,ele);
    }
    print_node(&dl1);

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        insert_node(&dl2,ele);
    }
    print_node(&dl2);
    //delete_node(&dll);
   // print_node(&dll);
    //cin>>ele;
    //insert_head(&dll,ele);
    //print_node(&dll);
    //cin>>key>>ele;
    //insert_bw(&dll,key,ele);
    //cin>>key;
    //delete_bw(&dll,key);
    merge(&dl1,&dl2);
    print_node(&dl1);
}
