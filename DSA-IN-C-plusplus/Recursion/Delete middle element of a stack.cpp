//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void DeleteMiddle(stack<int> &s,int i,int n)

    {

        if(i==n)

            return;

        int topEle=s.top();

        s.pop();

        DeleteMiddle(s,i+1,n);

        if(i== n/2)

            return;

        else

            s.push(topEle);

        return;

    }

    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        DeleteMiddle(s, 0, s.size());
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends
