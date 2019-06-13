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

void quick_sort(int a[],int first,int last)
{
    int low=first;
    int high=last;
    int pi=a[(first+last)/2];
    do
    {
        while(a[low]<pi)    //change sign for descending
            low++;
        while(a[high]>pi)   //change sign for descending
            high--;
        if(low<=high)
        {
            int temp=a[low];
            a[low++]=a[high];
            a[high--]=temp;
        }
    }while(low<=high);
    if(first<high)
        quick_sort(a,first,high);
    if(low<last)
        quick_sort(a,low,last);
}

void find_value(int key)
{
    struct node *a=find_key(key);
    cout<<a->value<<"\n";
    table[key]=a->next;
}
main()
{
    int i;
    cin>>n;
    int a[n],temp_array[n];
    for(i=0;i<n;i++)
        {
            cin>>a[i];
            temp_array[i]=a[i];
        }
    quick_sort(a,0,n-1);
    for(i=0;i<n;i++)
        insert_value(a[i],i);


    // Find the element in hash_table in O(1)
    for(i=0;i<n;i++)
    {
        find_value(temp_array[i]);
    }

}
