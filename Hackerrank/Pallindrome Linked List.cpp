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



//to reverse the part of linked list
struct node *reverse(struct node *temp)
{
    struct node *prev=NULL,*next=NULL,*current=temp;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }

    return prev;
}



void reverse_otherhalf(int n)
{
    struct node *temp=start;
    if(n%2==0)
    {
    for(int i=0;i<n/2-1;i++){
        temp=temp->next;}
    temp->next=reverse(temp->next);
    }
    else
    {
       for(int i=0;i<(n+1)/2-1;i++){
        temp=temp->next;}
    temp->next=reverse(temp->next);
    }
}
void pallindrome(int n)
{
    int flag=0;
    reverse_otherhalf(n);
    struct node *temp1=start,*temp2=start;
    n=n%2==0?n/2:(n+1)/2;
    for(int i=0;i<n;i++)
        temp2=temp2->next;
    while(temp2!=NULL)
    {
        if(temp1->data!=temp2->data)
            flag=1;
            temp1=temp1->next;
            temp2=temp2->next;
    }
    if(flag==0)
        cout<<"Pallindrome"<<endl;
    else
        cout<<"Not Pallindrome"<<endl;
}


//to print the LL
void view_node()
{
    struct node *t;
    if(start==NULL)
        printf("Underflow\n");
    else
    {
        t=start;
        while(t!=NULL)
        {
            cout<<t->data<<" ";
            t=t->next;
        }
        cout<<"\n";
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
    view_node();
    pallindrome(n);
    //view_node();
}
