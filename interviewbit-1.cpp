#include<iostream>
#include<cmath>
using namespace std;


int main()
{
    vector<int> A;
    vector<int> B;
    int ans=0;
    int n=A.size();
    for(int i=0;i<n-1;i++)
    {

        int x1=A[i],x2=A[i+1],y1=B[i],y2=B[i+1];
        ans=ans+math.max(math.abs(x1-x2),math.abs(y1-y2));

    }
    return ans;
}
