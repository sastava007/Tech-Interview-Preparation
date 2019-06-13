/*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                                                                    SHIVANSH SRIVASTAVA
                                                                                Email: sastava007@gmail.com

                                                                            Bachelors in Computer Science (2018-22)
                                                                    INDIAN INSTITUTE OF INFORMATION TECHNOLOGY, GWALIOR

                                                                                    GOD PRAY FOR ME !
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


*/


#include<bits/stdc++.h>
using namespace std;
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
   int i=hash_function(key);
   struct node *temp=table[i];
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
    int i=hash_function(key);
        struct node *new_node=(struct node *)malloc(sizeof(struct node ));
        new_node->key=key;
        new_node->value=value;
        new_node->next=NULL;

        struct node *a=find_key(key);
        if(a!=NULL)
            a->value=value;
        else
        {
                if(table[i]!=NULL)
                {
                    struct node *temp=table[i];
                    while(temp->next!=NULL)
                        temp=temp->next;
                    temp->next=new_node;
                }
                else if(table[i]==NULL)
                {
                    table[i]=new_node;
                }
        }
}



void print_table()
{
    int i=0;

    while(i<10)
    {
        struct node *temp=table[i];
        if(temp!=NULL)
        {
            struct node *temp2=table[i];
            cout<<i<<" th Bucket :";
            while(temp2!=NULL)
            {
                cout<<"( "<<temp2->key<<","<<temp2->value<<" )"<<"   ";
                temp2=temp2->next;
            }
            cout<<"\n";
        }
        else if(temp==NULL)
        {
            cout<<i<<" th Bucket :";
            cout<< " NULL\n";
        }

        i++;
    }
}
void find_value(int key)
{
    struct node *a=find_key(key);
    cout<<a->value<<"\n";
}

main()
{
    int c,key,value;
    while(1)
    {
        cout<<"1. Insert\n2. Print Table\n3.Find element\n4.Exit\n";
        cin>>c;
        if(c==1)
        {
            cin>>key>>value;
            insert_value(key,value);
        }
        else if(c==2)
        {
            print_table();

        }
        else if(c==3)
        {
            cin>>key;
            find_value(key);
        }
        else
        {
            exit(1);
        }
    }

}
