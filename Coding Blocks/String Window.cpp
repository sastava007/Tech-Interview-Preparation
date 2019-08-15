/*  Find window with minimum length which contains all the characters of second string
 *  Approach: Fisrt find window which contains all characters of string 2 and then try to minimize that window
 *  https://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
 */

#include<bits/stdc++.h>
using namespace std;

string minimumWindowString(string a, string b)
{
    if(a.length()<b.length())
    {
        return "No string";
    }
    unordered_map<char,int> str,pat;
    for(int j=0;j<b.length();j++)
        pat[b[j]]++;

    int start=0,start_index=-1;
    int min_len=INT_MAX;
    int cnt=0;
    for(int j=0;j<a.length();j++)
    {
        str[a[j]]++;
        if(pat.find(a[j])!=pat.end() && str[a[j]]<=pat[a[j]])
        {
            cnt++;
        }
        if(cnt==b.length())         ///which means we have found one such window so now we need to minimize it
        {
            while(pat.find(a[start])==pat.end() || str[a[start]]>pat[a[start]])
            {
                if(str[a[start]]>pat[a[start]])
                    str[a[start]]--;
                    start++;
            }

            if((j-start+1)<min_len)
            {
                min_len=j-start+1;
                start_index=start;
            }
        }

    }
    if(start_index!=-1)
    return a.substr(start_index,min_len);
    else
        return "No string";

}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    string a,b;
    getline(cin,a);
    getline(cin,b);
    cout<<minimumWindowString(a,b);
}
