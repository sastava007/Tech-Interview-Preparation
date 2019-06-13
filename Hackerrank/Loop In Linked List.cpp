#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    int flag;
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
    temp->flag=0;
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
//Floyd's cycle finding Algorithm to check loop and count size of loop
void check_loop()
{
    int c=0;
    struct node *temp=start;
    while(temp!=NULL)
    {
        if(temp->next->flag!=0)
        {
            cout<<"LOOP EXIST"<<endl;
            struct node *t=temp->next;
            temp=temp->next;
            do
            {
                c++;
                temp=temp->next;
            }while(temp!=t);
            cout<<c<<endl;
            exit(0);
        }
        temp->flag=1;
        temp=temp->next;
    }
    cout<<"Loop does not exist"<<endl<<c;
}
void print_node()
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
    int n,ele;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        insert_node(ele);
    }
    print_node();
    start->next->next->next->next = start;
    check_loop();
}
