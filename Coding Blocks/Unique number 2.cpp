// Using hashing but it consumes more space so we need to reduce space complexicity using bitmasking


/*

#include<bits/stdc++.h>
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,ele,i;
    cin>>n;
    map<int,int> a;
    for(i=0;i<n;i++)
    {
        cin>>ele;
        a[ele]++;
    }
    for(auto it:a)
    if(it.second==1)
        cout<<it.first<<" ";
}

*/

#include<bits/stdc++.h>
using namespace std;
int firstsetbit(int n)
{
    int i=0;
    while(1)
        {
            if((1<<i)&n!=0)
            break;
            else
            i++;
        }
    return i;

}
int firstnumber(int *a,int n,int x)
{

    int mask=(1<<x);
    int first=0;
    for(int i=0;i<n;i++)
    {
        if((mask&a[i])!=0)
            {
                first=first^a[i];
            }
    }

    return first;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,n;
    cin>>n;
    int a[n],xore=0;
    for(i=0;i<n;i++)
        {
            cin>>a[i];
            xore=xore^a[i];
        }
    int x=firstsetbit(xore);
    int first_ele=firstnumber(a,n,x);
    int second_ele=xore^first_ele;
    cout<<first_ele<<" "<<second_ele;

}
