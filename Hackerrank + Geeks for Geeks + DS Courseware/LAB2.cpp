#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
    struct node *next;
    int key;
    int value;
};

struct node * table[1000]={NULL};
int hash_function(int key)
    {
        int index=key%10;
        return index;
    }

struct node * find_key(int key)
{
   struct node *temp=table[key];
   while(temp!=NULL)
        {
            if(temp->key==key)
            {
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
}

void insert_value(int key,int value)
{
        struct node *new_node=(struct node *)malloc(sizeof(struct node ));
        new_node->key=key;
        new_node->value=value;
        new_node->next=NULL;

        struct node *a=find_key(key);

                if(table[key]!=NULL)
                {
                    struct node *temp=table[key];
                    while(temp->next!=NULL)
                        temp=temp->next;
                    temp->next=new_node;
                }
                else if(table[key]==NULL)
                {
                    table[key]=new_node;
                }
}

void find_value(int key)
{
    struct node *a=find_key(key);
    cout<<a->value<<"\n";
    table[key]=a->next;
}
main()
{
    int i,t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=)
    }



    // Find the element in hash_table in O(1)
    for(i=0;i<n;i++)
    {
        find_value(temp_array[i]);
    }

}

