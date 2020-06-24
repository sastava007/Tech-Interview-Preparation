/* LC Version: Number of subarrays with given sum K 
The cumulative sum upto two indices, say i and j is at a difference of k i.e. if sum[i] - sum[j] = k, the sum of elements lying between indices i and j is K.
We store the data in the form: (sum_i, no. of occurences of sum_i)

We traverse over the array nums and keep on finding the cumulative sum. Every time we encounter a new sum, we make a new entry in the hashmap corresponding to that sum.
If the same sum occurs again, we increment the count corresponding to that sum in the hashmap. Further, for every sum encountered, we also determine the number of times
the sum (sum-k) has occured already, since it will determine the number of times a subarray with sum k has occured upto the current index. We increment the countcount by the same amount.

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> m;
        m[0]=1;
        
        int sum=0, count=0;
        
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            
            if(m.find(sum-k) != m.end())
                count += m[sum-k];
            
            m[sum]++;
        }
        
        return count;
    }
};


/* Sliding window approach, only works for non-negative numbers
    Intution: The idea is to keep adding elements to a temporary variable untill it's sum is <= than given sum and checking if it's values is equal is equal to sum. 
            Once we found the sum break the loop and return but if the value of sum get greater that given value then reset the sum & value of i.  
*/

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
                cout<<"Sum found between indexes "<< 0 << " to " << i << endl;
                return;
            }
    
            if(m.find(sum-k) != m.end())
            {
                cout<<"Sum found between indexes "<<m[sum-k] + 1<< " to " <<i<< endl; 
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