#include<bits/stdc++.h>
#define maxsize 100
using namespace std;
struct node
{
    int info;
    int next;
}node[maxsize];
int avl=0;
for(int i=0;i<maxsize-1;i++)
 node[i].next=i+1;
 node[maxsize-1].next=-1;

int get_node()
{
    if(avl==-1)
        {
            cout<<"Overflow";
            exit(0);
        }
        int p=avl;
        avl=node[avl].next;
        return p;
}
void insert_after(int p,int ele)
{
    if(p==-1)
    {
        cout<<"Insertion not possible"<<endl;
        exit(0);
    }
    int q=get_node();
    node[q].info=ele;
    node[q].next=node[p].next;
    node[p].next=q;
}
void delete_after(int p,int *ele)
{
    if(p==-1||node[p].next==-1)
        {
            cout<<"Delete Not Possible"<<endl;
            exit(0);
        }
        int q=node[p].next;
        ele=node[q].info;
        node[p].next=node[q].next;
        freenode(q);
}
void freenode(int p)
{
    node[p].next=avl;
    avl=p;
}
