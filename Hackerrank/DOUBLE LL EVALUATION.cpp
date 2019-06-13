#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct dllist
{
    struct node *head;
    struct node *tail;
};
void init(struct dllist *dl)
{
    dl->head=NULL;
    dl->tail=NULL;
}
struct node * create_node()
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    return new_node;
}

void insert_at_head(struct dllist *dl,int ele)
{
    struct node *new_node=create_node();
    new_node->data=ele;
    new_node->prev=NULL;
    new_node->next=NULL;
    if((dl->head==dl->tail)&&dl->head==NULL)
    {
        dl->head=new_node;
        dl->tail=new_node;
    }
    else
    {
        dl->head->next=new_node;
        dl->head=new_node;
    }
}
void insert_bw(struct dllist *dll,int key,int ele)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->prev=NULL;
    new_node->next=NULL;

    struct node *temp=dll->tail;
    while(temp->data!=key)
        temp=temp->next;
    new_node->prev=temp;
    new_node->next=temp->next;
    temp->next->prev=new_node;
    temp->next=new_node;
}
void delete_from_tail(struct dllist *dl)
{
    if((dl->head==dl->tail)&&dl->head==NULL)
        cout<<"Linked List is empty"<<endl;
    else
    {
        struct node *r=dl->tail;
        dl->tail=dl->tail->next;
        free(r);
    }
}
void delete_bw(struct dllist *dll,int key)
{
    struct node *temp=dll->tail,*r;
    while(temp->data!=key)
        temp=temp->next;
    r=temp;
    r->prev->next=r->next;
    r->next->prev=r->prev;
    free(r);
}
void print(struct dllist *dl)
{
    struct node *temp=dl->tail;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
main()
{
    struct dllist dl;
    init(&dl);
    int c,ele,key;
    while(1)
    {
        cout<<"Enter Your Choice"<<endl<<"1. Insert at HEAD"<<endl<<"2. Insert After"<<endl<<"3. Delete from TAIL"<<endl<<"4. Delete Key"<<endl<<"5. Print"<<endl<<"EXIT"<<endl;
        cin>>c;
        if(c==1)
        {
            cin>>ele;
            insert_at_head(&dl,ele);
        }
        else if(c==2)
        {
            cout<<"Enter key after which you want to insert and what element you want to insert"<<endl;
            cin>>key>>ele;
            insert_bw(&dl,key,ele);
        }
        else if(c==3)
        {
            delete_from_tail(&dl);
        }
        else if(c==4)
        {
            cin>>key;
            delete_bw(&dl,key);
        }
        else if(c==5)
        {
            print(&dl);
        }
        else
            exit(1);
    }
}
