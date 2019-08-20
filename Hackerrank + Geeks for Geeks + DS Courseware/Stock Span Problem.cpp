
/*     Here we need to find span of a stock, which means on how many days the price of the stock was less than or eqyul to current price before this date
 *     Naive Approach: from a given element check for all the elements before it by running a inner loop, but this will cost O(n2) time, so there's an efficient method also
 *     using stack, in which we store index of latest greatest element. If current element is greater than previous element then pop out all previous elements and if it is small,
 *     then add its index to stack.        https://www.geeksforgeeks.org/the-stock-span-problem/
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout<<#x<<" "<<x<"\n"
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];

    stack<int> s;
    s.push(0);

    cout<<1<<" ";       ///1st stock will always have span 1, becz no element will be smaller than it
    for(i=1;i<n;i++)
    {
        while(!s.empty() && a[s.top()]<=a[i])
            s.pop();
        int span=s.empty()==false?(i-s.top()):(i+1);
        cout<<span<<" ";
        s.push(i);
    }
}
