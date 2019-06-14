#include<bits/stdc++.h>
#define max 100
using namespace std;
struct dequeue
{
    int array[max];
    int rear;
    int fron;
};
bool isempty(struct dequeue *q)
{
    if(q->fron==-1 && q->rear==-1)
        return true;
}
bool isfull(struct dequeue *q)
{
    if(q->fron==0&&q->rear==max-1 || q->fron=q->rear+1)
        return true;
}
void insert_rear(struct dequeue *q,int ele)
{
    if(isfull(q))
        cout<<"overflow"<<endl;
    else
    {
        if(isempty(q))
        {
            q->rear=0;
            q->array[q->rear]=ele;
            q->fron=0;
        }
        else if(q->rear==max-1)
            q->rear=0;
        else
            q->rear++;
    }
}
main()
