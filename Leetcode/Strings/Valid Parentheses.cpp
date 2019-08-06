#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    char findPair(char c)
    {
        if(c==')')
        return '(';
        else if(c=='}')
        return '{';
        else
        return '[';

    }

    bool isValid(string s)
    {
        stack<char> temp;
        int flag=0;

        for(int i=0;i<s.length();i++)
        {

            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            temp.push(s[i]);

            else
            {
                char c=findPair(s[i]);

                /// make this check to ensure that if closing bracket is the first thing which we encounter then it's unbalanced and we should return false without checking
                if(temp.empty())
                return false;

                if(c!=temp.top())
                {
                    flag=1;
                    break;

                }
                temp.pop();
            }
        }
        if(flag==1 || !temp.empty())
        return false;
        else
        return true;
    }
};

main()
{
    Solution obj;
    string s;
    cin>>s;
    cout<<obj.isValid(s);

}
