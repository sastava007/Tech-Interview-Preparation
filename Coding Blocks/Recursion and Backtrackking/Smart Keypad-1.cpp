#include<bits/stdc++.h>
using namespace std;

char keypad[][10]={ " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
void solveKeypad(string num, char *out, int i, int j)
{
    //base case
    if(num[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<"\n";
        return;
    }
    int code=num[i]-'0';

    for(int k=0;keypad[code][k]!='\0';k++)
    {
        out[j]=keypad[code][k];
        solveKeypad(num,out,i+1,j+1);
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string num;
    cin>>num;
    char out[1000];

    solveKeypad(num,out,0,0);
}
