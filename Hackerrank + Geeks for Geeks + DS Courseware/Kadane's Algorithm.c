// THIS ALGORITHM WORKS ONLY WHEN THERE IS ATLEAST 1 INPUT, BUT THIS CAN BE MODIFIED BY STORING *max_element() IN MAX_SO_FAR

#include<bits/stdc++.h>
using namespace std;
main()
{
    int a[]={-2, -3, 4, -1, -2, 1, 5, -3};
    int max_so_far=0,max_upto_here=0;
    for(int i=0;i<8;i++)
    {
        max_upto_here+=a[i];
        if(max_upto_here<0)
            max_upto_here=0;
        if(max_upto_here>max_so_far)
            max_so_far=max_upto_here;
    }
    if(max_so_far!=0)
    cout<<max_so_far;
    else
        cout<<*max_element(a,a+8);

}
