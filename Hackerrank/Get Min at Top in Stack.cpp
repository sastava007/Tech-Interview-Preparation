// THIS PROGRAM WILL RETURN MIN ELEMENT IN STACK AFTER EACH INSERTION,
// WHENEVER WE CALL getmin_top(),  IT WILL RETURN THE MIN ELEMENT AMONG THE STACK AFTER CURRENT INSERTIONS.

#include<bits/stdc++.h>
using namespace std;
void insert(int ele,stack<int> *s,stack<int> *min)
{
    if(s->size()==0)
    {
        s->push(ele);
        min->push(ele);
    }
    else
    {
        s->push(ele);
        if(s->top()<min->top())
        min->push(ele);
    }
}
void getmin_top(stack<int> *s,stack<int> *min)
{
    if(min->top()==s->top())
        s->pop();
    cout<<min->top()<<endl;
    min->pop();
}
 main()
 {
     stack<int> s,min;
     insert(6,&s,&min);
     insert(3,&s,&min);
     insert(4,&s,&min);
     insert(2,&s,&min);
        getmin_top(&s,&min);
     insert(18,&s,&min);
     insert(1,&s,&min);
        getmin_top(&s,&min);
     insert(0,&s,&min);
     getmin_top(&s,&min);
 }
