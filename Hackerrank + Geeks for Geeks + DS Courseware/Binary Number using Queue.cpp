#include<bits/stdc++.h>
#define MAX 10
using namespace std;
struct queue_array
{
   int arr[MAX];
   int rear;
   int front;
};
bool isempty(struct queue_array *q)
{
    if(q->front==-1)
        return true;
    else
        return false;
}
bool isfull(struct queue_array *q)
{
    if(q->front==MAX-1)
        return true;
    else
        return false;
}
void enqueue_array(struct queue_array *q,int ele)
{
    if(isfull(q))
        cout<<"Overflow"<<endl;
    else
    {
        q->rear=(q->rear+1)%MAX;
        q->arr[q->rear]=ele;
        if(q->front==-1)
            q->front=q->rear;
    }
}
void print(struct queue_array *q)
{
    int x=q->rear;
    for(int x=q->rear;x>=q->front;x--)
        cout<<q->arr[x]<<" ";
    cout<<endl;
}
main()
{
    int n,quot,r;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        struct queue_array q;
        q.front=-1;
        q.rear=-1;
        quot=i;
        while(quot>0)
        {
           r=quot%2;
           enqueue_array(&q,r);
           quot/=2;
        }
        print(&q);
    }

}
