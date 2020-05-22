/*
    https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
    Approach: The idea is to keep adding elements to a temporary variable untill it's sum is <= than given sum and checking if it's values is equal is equal to sum. 
                Once we found the sum break the loop and return but if the value of sum get greater that given value then reset the sum & value of i.  
*/

/* Sliding window approach, only works for non-negative numbers */

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k,i;
        cin>>n>>k;
        ll a[n];
        for(i=0;i<n;i++)
            cin>>a[i];

        i=0;
        ll j = 0, sum = 0;
        bool flag = false;
        
        while(i<n && j<n)
        {
            sum += a[j++];
            while(sum>k && i<j)
            {
                sum=sum-a[i++];
            }           
            if(sum==k)
            {
                flag = true;
                break;
            }
        }
        if(flag)
            cout<<i+1<<" "<<j<<"\n";
        else
            cout<<"-1\n";
       
    }
    return 0;
}

/* Using hashing to store the current sum, works for both +ve/-ve numbers, It requires extra O(n) space */
#include <bits/stdc++.h>
using namespace std;

int main() 
{   
    int t;
    cin>>t;
    while(t--)
    {
        int n, i, j, k;
        cin>>n;
        int a[n];
        for(i=0; i<n; i++)
            cin>>a[i];
        
        cin>>k;
        
        int sum = 0;
        unordered_map<int, int> m;
        
        for(i=0; i<n; i++)
        {
            sum += a[i];
            
            if(sum == k)
            {
                cout << "Sum found between indexes "
                 << 0 << " to " << i << endl; 
                return; 
            }
    
            if(m.find(sum-k) != m.end())
            {
                cout << "Sum found between indexes "<<m[sum-k] + 1<< " to " << i << endl; 
                return; 
            }

            m[sum] = i;
        }
        
    }
    
	return 0;
}

/* For constant space, modify the array to contain only +ve elements by adding smallest -ve element, this way our target sum is also get modified
    K += (number of elements in the subarray) * (absolute value of min element)
    
*/