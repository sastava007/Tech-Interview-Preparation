class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        int v[26];
        memset(v,0,sizeof(v));
        for(int i=0;i<s.size();i++)
        {
            v[s[i]-97]++;
        }
        for(int i=0;i<t.size();i++)
        {
            if(v[t[i]-97])
            {
                v[t[i]-97]--;
            }
            else
            {
                return t[i];
            }
        }
        return t[0];
    }
};