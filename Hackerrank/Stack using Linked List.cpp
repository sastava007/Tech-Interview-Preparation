#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;
void push(int ele)
{
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=ele;
    new_node->next=NULL;
    if(top==NULL)
        top=new_node;
    else
    {
        new_node->next=top;
        top=new_node;
    }
}
void pop()
{
    if(top==NULL)
        cout<<"Underflow"<<endl;
    else
    {
        struct node *r=top;
        cout<<r->data<<endl;
        top=top->next;
        free(r);
    }
}
main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    pop();
}
