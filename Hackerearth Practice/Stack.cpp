#include<bits/stdc++.h>
#define size 10
using namespace std;
struct st
{
    int arr[size];
    int top;
};
bool isfull(struct st *a)
{
    return(a->top==size-1);
}
bool isempty(struct st *a)
{
    return(a->top==-1);
}
void push(struct st *a,int ele)
{

    if(isfull(a))
    {
        cout<<"Overflow"<<endl;
        return;
    }
    else
    {
      a->top=a->top+1;
      a->arr[a->top]=ele;
    }
}
int pop(struct st *a)
{
    if(isempty(a))
    {
        cout<<"Underflow"<<endl;
    }
    else
    {
        int data=a->arr[a->top];
        (a->top)--;
    }

}
void sort(struct st *a,int n)
{
    int i,j;
        for(i=0;i<a->top;i++)
        for(j=0;j<a->top-1;j++)
        if(a->arr[j]>a->arr[j+1])
        swap(a->arr[j],a->arr[j+1]);
}
main()
{
    struct st a;
    a.top=-1;
    push(&a,26);
    push(&a,20);
    push(&a,50);
    push(&a,10);
    sort(&a,4);
    pop(&a);
    pop(&a);
    pop(&a);

}
