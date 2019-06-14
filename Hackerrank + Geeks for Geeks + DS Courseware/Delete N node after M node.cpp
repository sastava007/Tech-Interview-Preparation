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
struct node *delete_node(struct node *temp,int n)
{
    int c=0;
    while(c!=n)
    {
        struct node *r=temp;
        temp=temp->next;
        c++;
        free(r);
    }
    return temp;
}
void delete_n_m(int n,int m)    // DELETE FROM FIRST
{
    int c1=0,c=0;
    struct node *temp=start;
    while(temp!=NULL)
    {
                while(1)
                {

                    if(c1==m)
                   {
                       temp=delete_node(temp,n);
                       break;
                   }
                    c1++;
                }
                c1=0;
                continue;
    }

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
main()
{
    insert_node(1);
    insert_node(2);
    insert_node(3);
    insert_node(4);
    insert_node(5);
    insert_node(6);
    insert_node(7);
    insert_node(8);
    view_node();
    cout<<endl;
    int n=2,m=2;
    delete_n_m(n,m);
    view_node();
    cout<<endl;
}
