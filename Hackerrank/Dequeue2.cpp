#include <iostream>
#define MAX 100
using namespace std;
struct Deque{       //Declaring deque
    int arr[MAX];
    int Front;
    int Rear;
}dq;
 bool overflow(int n){
     return((dq.Rear==n-1 && dq.Front==0) || dq.Front==dq.Rear+1);
 }
 bool underflow(int n){
     return(dq.Front==-1 && dq.Rear==-1);
 }
void InsertFront(int i,int n){
    if(overflow(n))
    {
        cout<<"Overflow!!!"<<endl;
        return;
    }
    if(underflow(n)) //condition if are we are adding first element
        {dq.Front=0;
        dq.Rear=0;
        dq.arr[dq.Front]=i;
        return;}
    if(dq.Front==0)
        dq.Front=n-1;
    else
        dq.Front--;
    dq.arr[dq.Front]=i;
}
void InsertRear(int i,int n){
     if(overflow(n))
    {
        cout<<"Overflow!!!"<<endl;
        return;
    }
    if(underflow(n))  //condition if are we are adding first element
        {dq.Front=0;
        dq.Rear=0;
        dq.arr[dq.Rear]=i;
        return;}
    if(dq.Rear==n-1)
        dq.Rear=0;
    else
        dq.Rear++;
    dq.arr[dq.Rear]=i;
}
void DeleteFront(int n){
    if(underflow(n)){
        cout<<"Underflow!!!"<<endl;
        return;
    }
    if(dq.Front==dq.Rear){ //when only one element is left in deque we make values of front and rear back to their initial values
        dq.Front=-1;
        dq.Rear=-1;
        return;
        }
    if(dq.Front==n-1)
        dq.Front=0;
    else
        dq.Front++;
}
void DeleteRear(int n){
    if(underflow(n)){
        cout<<"Underflow!!!"<<endl;
        return;
    }
    if(dq.Front==dq.Rear){
        dq.Front=-1;
        dq.Rear=-1;
        return;
        }
     if(dq.Rear==0)
        dq.Rear=n-1;
     else
        dq.Rear--;
}
void Traverse(int n){
    if(underflow(n)){
        cout<<"Empty deque"<<endl;//if deque is empty
        return;
    }
    int i=dq.Front;
    cout<<dq.arr[i]<<" ";
    while(i!=dq.Rear){
        if(i==n-1)
            i=0;
        else i++;
        cout<<dq.arr[i]<<" ";
    }
    cout<<endl;
}
main()
{
    dq.Front=-1;  dq.Rear=-1; //initialization
    cout<<"Enter number of element:";
    int n,count=0;
    cin>>n;
    while(1){
    cout<<"1. Insert at Front"<<endl;
    cout<<"2. Insert at Rear"<<endl;
    cout<<"3. Delete at front"<<endl;
    cout<<"4. Delete at Rear"<<endl;
    cout<<"5. Print"<<endl;
    cout<<"6. EXIT"<<endl;
    int c;
    cout<<"Enter your choice:";
    cin>>c;
    int i;
    switch(c)
    {
    case 1:
        cout<<"Enter integer to add:";
        cin>>i;
        InsertFront(i,n);
        count++;
        break;
    case 2:
        cout<<"Enter integer to add:";
        cin>>i;
        InsertRear(i,n);
        count++;
        break;
    case 3:
        DeleteFront(n);
        count--;
        break;
    case 4:
        DeleteRear(n);
        count--;
        break;
    case 5:
        Traverse(n);
        break;
    case 6:
        exit(1);
    }
    if(n-count>=0)
    cout<<"Empty spaces:"<<n-count;
    cout<<endl<<endl;
    }
}
