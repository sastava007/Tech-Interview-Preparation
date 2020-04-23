/*
    A good problem that can be optimized to solve in O(N) using hashing, which was else solved in O(N2)
    https://www.geeksforgeeks.org/count-distinct-elements-in-every-window-of-size-k/?ref=rp

*/

#include <bits/stdc++.h>
using namespace std;

void countDistinct(int[], int, int);

int main() 
{
    int t;
    cin >> t;
    while (t--) {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        countDistinct(a, k, n);
        cout << endl;
    }
    return 0;
}

void countDistinct(int A[], int k, int n) 
{
   unordered_map<int, int> m;
   int i;
   for(i=0;i<k;i++)
    m[A[i]]++;

    for(i=k;i<n;i++)
    {
        cout<<m.size()<<" ";
        
        //remove the first element of previous winodw if it's been just 1 time else decrement it's count.
        if(m[A[i-k]]==1)
            m.erase(A[i-k]);
        else
            m[A[i-k]]--;
        
        //add current element
        m[A[i]]++;
    }
    cout<<m.size();
}