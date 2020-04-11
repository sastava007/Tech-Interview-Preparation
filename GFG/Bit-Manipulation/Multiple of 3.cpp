/*
    Every no of 2^x can be represented in the form of 3k(+-)1 if x is even then 3k+1 else 3k-1
    1011 now add 1*(3*0+1) + 1*(3*1-1) + 0*(3*1+1) + 1*(3*3-1) so after doing sum of this we get (1 + 3*1 -1 + 3*3 -1) which can be summed to 3*something + another_something so if this another_something term can result into multiple of 3 then this whole no is multiple of 3. 
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        int n= s.length()-1;
        int rem=0;
        for(int i=n;i>=0;i--)
        {
            if(s[i]=='1' && !((n-i)&1))
                rem++;
            else if(s[i]=='1' && ((n-i)&1))
                rem--;
        }
        cout<<((rem%3)==0)<<"\n";
    }

    return 0;
}

// Approach 2 : General approach for any modulo

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int rem = 0;
        for(int i=0;i<s.size();++i)
            rem = (rem*2+s[i]-'0')%3;
        cout<<(rem==0)<<endl;
    }
    return 0;
}