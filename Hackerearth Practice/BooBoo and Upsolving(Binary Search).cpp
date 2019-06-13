#include <iostream>
using namespace std;
int main() {
    int n,m,i,ques,c;
    cin>>n>>m;
    long long int a[n],sum,max_ele=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        max_ele=max(max_ele,a[i]);
    }
    while(1)
    {
        sum=0,c=0;
        for(i=0;i<n;i++)
        {
            sum+=a[i];
            if(sum==max_ele)
            {
                ques+=i+1;
                c++;
            }
        }
        if(ques==n && c<=m)
            {
                cout<<max_ele;
                break;
            }
            max_ele++;
    }

}
