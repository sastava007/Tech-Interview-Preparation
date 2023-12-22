//{ Driver Code Starts
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
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */

void sorted(stack<int> &s,int n)

{

    if(n<=1)

        return;

    int topele= s.top();

    s.pop();

    sorted(s,n-1);

    stack<int> dummy;

    while(!s.empty() && s.top()>topele)

        dummy.push(s.top()),s.pop();

    s.push(topele);

    while(dummy.size())

        s.push(dummy.top()),dummy.pop();

    return;

}

void SortedStack :: sort()

{

   sorted(s,s.size());

}
