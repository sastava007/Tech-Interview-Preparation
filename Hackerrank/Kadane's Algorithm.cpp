// THIS ALGORITHM WORKS ONLY WHEN THERE IS ATLEAST 1 INPUT, BUT THIS CAN BE MODIFIED BY STORING *max_element() IN MAX_SO_FAR

#include<bits/stdc++.h>
using namespace std;
main()
{
    int a[]={-10,1,3,-2,4};
    int max_so_far=a[0],max_upto_here=a[0];
    for(int i=1;i<5;i++)
    {
        max_upto_here=max(a[i],max_upto_here+a[i]);
        if(max_upto_here>max_so_far)
            max_so_far=max_upto_here;
    }
    cout<<max_so_far;

}
