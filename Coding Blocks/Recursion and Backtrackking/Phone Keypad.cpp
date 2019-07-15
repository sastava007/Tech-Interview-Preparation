#include<bits/stdc++.h>
using namespace std;
#define ll long long

char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void phone_keypad(char *in, char *out, int i, int j)
{
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<" ";
        return;
    }

    int digit=in[i]-'0';
    if(digit==0||digit==1)
        phone_keypad(in,out,i+1,j);
    for(int k=0;keypad[digit][k]!='\0';k++)
    {
        out[j]=keypad[digit][k];
        phone_keypad(in,out,i+1,j+1);
    }

}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char in[100],out[100];

    cin>>in;
    phone_keypad(in,out,0,0);

}

