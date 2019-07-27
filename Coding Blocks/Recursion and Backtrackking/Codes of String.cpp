#include<bits/stdc++.h>
using namespace std;

char alphabets[]=" abcdefghijklmnopqrstuvwxyz";
vector<string> ans;
void allpossible(char *number, int index, int n)
{
    static char s[50]="";
    static int i=0;
    if(index==n)
    {
        ans.emplace_back(s);
        return;
    }
    int numformed;
    numformed=number[index]-'0';
    if(numformed>0)
    {
        s[i++]=alphabets[numformed];
        s[i]='\0';
        allpossible(number, index+1, n);
        i--;
        if(index+1<n)
        {
            numformed=(number[index]-'0')*10 + number[index+1]-'0';
            if(numformed<27)
            {
                s[i++]=alphabets[numformed];
                s[i]='\0';
                allpossible(number, index+2, n);
                i--;
            }
        }
    }
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    char num[1000];
    cin>>num;
    char out[1000];
    allpossible(num,0,strlen(num));

    cout<<ans;
}
