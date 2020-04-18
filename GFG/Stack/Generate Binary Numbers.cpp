/*
    A very smart solution based on pattern observation, and how later you can justify over your findings.
    There exist's a pattern i.e a number x generates (2x) and (2x+1) if we append some particular digit to it.
    
    Like 2[10] is generating 4[100] and 5[101] which can be made by appending 0 & 1 to [10]

    Proof: To double(2x) a number we normally left shift it in bitwise and here's it's equivalent is appending 0 to it's binary representation which will basically shift entire thing to left by 1 position.
    And for (2x+1) we have alredy doubled the no by appending 0, now we just need to add(append) 1 to it's LSB.  

*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        queue<string> q;
        q.push("1");
        for(i=1;i<=n;i++)
        {
            string front = q.front();
            q.pop();
            cout<<front<<" ";
            q.push(front+"0");
            q.push(front+"1");
        }
        cout<<"\n";
    }
	return 0;
}