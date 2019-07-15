#include<bits/stdc++.h>
using namespace std;
#define ll long long

void recursion_sequences(char *s, char *temp, int i, int j)
{
    //base case
    if(s[i]=='\0')
    {
        temp[j]='\0';
        cout<<temp<<" ";
        return;
    }

    //include the current character
    temp[j]=s[i];
    recursion_sequences(s,temp,i+1,j+1);
    //exclude the current character
    recursion_sequences(s,temp,i+1,j);
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char s[100]="abcd";
    char temp[100];
    recursion_sequences(s,temp,0,0);
}

