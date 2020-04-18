/*
    Sort in descending order;
*/

#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        SortedStack *ss = new SortedStack();
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
        int k;
        cin>>k;
        ss->s.push(k);
        }
        ss->sort();
        printStack(ss->s);
    }
}

void SortedStack :: sort()
{
    stack<int> s2;
    while(!s.empty())
    {
        int x = s.top();
        s.pop();
        // while keeping smallest element should be at the top
        while(!s2.empty() && s2.top()<x)
        {
            s.push(s2.top());
            s2.pop();
        }
        s2.push(x);
    }
    while(!s2.empty())
    {
        s.push(s2.top());
        s2.pop();
    }
}

void SortedStack :: sort()
{
    stack<int> s2;
    while(!s.empty())
    {
        int x = s.top();
        s.pop();
        // while keeping largest element at top of stack, we don't need the second loop for transferring the element to original stack
        // Though there will be no change in no of comparisons becz we are stil using swap which is O(n)
        while(!s2.empty() && s2.top()>x)
        {
            s.push(s2.top());
            s2.pop();
        }
        s2.push(x);
    }

    swap(s,s2);
}