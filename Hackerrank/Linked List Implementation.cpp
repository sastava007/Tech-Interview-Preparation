#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *create_node()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
return temp;
}

void insert_node(int ele)     // INSERT AT LAST
{
    struct node *temp=create_node();
    temp->next=NULL;
    temp->data=ele;
    struct node *t;
    if(start==NULL)
        start=temp;
    else
    {
        t=start;
        while(t->next!=NULL)
            t=t->next;
        t->next=temp;
    }
}
void insert_first(int ele)
{
  struct node *temp=create_node();
  temp->data=ele;
  temp->next=NULL;
  temp->next =start;
  start=temp;
}
void insert_last(int ele)
{
    struct node *new_node=create_node(),*temp;
    new_node->data=ele;
    new_node->next=NULL;
    temp=start;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=new_node;
}
void insert_bw(int ele,int after)
{
    struct node *new_node=create_node();
    new_node->data=ele;
    new_node->next=NULL;
    struct node *temp=start;
    while(temp!=NULL)
    {
        if(temp->data==after&&temp->next!=NULL)
        {
            new_node->next=temp->next;
            temp->next=new_node;
        }
        else if(temp->data==after&&temp->next==NULL)
        insert_last(ele);
        temp=temp->next;
    }
}

void delete_first()    // DELETE FROM FIRST
{
    struct node *r;
    if(start==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        r=start;
        start=r->next;
        free(r);
    }
}
void delete_last()
{
    struct node *tail,*temp=start,*r;
    while(temp->next!=NULL)
        temp=temp->next;
        tail=temp;
        temp=start;
    while(temp->next!=tail)
        temp=temp->next;
    r=tail;
    free(r);
    temp->next=NULL;
    tail=temp;


}

void view_node()
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
int main()
{
    insert_node(10);
    insert_node(20);insert_node(30);insert_node(40);
    insert_first(69);
    view_node();
    cout<<endl;
    insert_bw(25,20);
    view_node();
    cout<<endl;
    insert_bw(500,40);
    view_node();
    /*
    delete_last();
    view_node();
    cout<<endl;
    delete_last();
    view_node();
    cout<<endl;
   delete_first();
view_node();
*/
    return 0;
}
