/*
    GfG Array: Easy
    An O(n) time and O(1) space solution using unordered_set
    It's important how cleverly I removed the use of array for storing the initial incoming elements 
*/


#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    ull p;
	    bool flag=false;
	    cin>>n>>p;
        unordered_set<ull> s;
        for(i=0;i<n;i++)
        {
            ull x;
            cin>>x;
            // As here we are breaking in b/w as we get our solution so this may give WA becz input is not completely read, so don't break and let it continue.
            // Instead use !flag as first condition inside if
            if(x!=0 && p%x==0 && s.find(p/x)!=s.end())
            {
                flag=true;
                break;
            }
            s.insert(x);
        }
        flag?cout<<"Yes\n":cout<<"No\n";
        s.clear();
	}
	return 0;
}