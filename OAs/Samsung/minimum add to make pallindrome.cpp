#include<bits/stdc++.h>
using namespace std;

bool isPallindrome(char *str)
{
    if(strlen(str) == 1)
        return true;

    int n = strlen(str);

    char *i = str, *j = str+n-1;
    while(j>i)
    {
        if(*j != *i)
            return false;
        i++;
        j--;
    }
    return true;
}

int minAppends(char *str)
{
    if(isPallindrome(str))
        return 0;
    str++;
    return minAppends(str)+1;
}

char* makePallindrome(char *str)
{
    int n = minAppends(str);
    char *res = new char[n];

    for(int i=n-1; i>=0; i--)
        res[n-i-1] = str[i];

    return res;
}

int main()
{
    char s[]="abcdc";
    cout<<makePallindrome(s);

    return 0;
}