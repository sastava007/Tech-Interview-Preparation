// the ide ais to find if sum is already present in hash set, this code is based on the fact that when sum is repaeated again or is already
//present then it means that there might be an subarray which nullifies itself.

#include<bits/stdc++.h>
using namespace std;
main()
{
    int n=5,i,sum=0;
    int a[]={4, 2, -3, 1, 6};
    unordered_set<int> sumset;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        if(sumset.find(sum)!=sumset.end() || sum==0)
        {
            cout<<"Subarray with zero sum is present"<<endl;
            break;
        }
        sumset.insert(sum);
    }
}
