#include<bits/stdc++.h>
using namespace std;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    unordered_set<char> vowel;
    vowel.insert('a');
    vowel.insert('e');
    vowel.insert('i');
    vowel.insert('o');
    vowel.insert('u');
    int n=s.length();
    int c=0,max_len=0;

    int i;
    bool if_prev;
    if(s[0]=='a'||s[0]=='e'||s[0]=='i'||s[0]=='o'||s[0]=='u')
    {
        if_prev=true;
        c++;

    }
    for(i=1;i<n;i++)
    {
        auto it=vowel.find(s[i]);

        if(if_prev && it!=vowel.end())
        {
            c++;
            if_prev=true;
        }
        else if(!if_prev && it!=vowel.end())
        {
            c=1;
            if_prev=true;
        }
        else if(it==vowel.end())
            c=0;
        max_len=max(max_len,c);
    }
    cout<<max_len;


}

