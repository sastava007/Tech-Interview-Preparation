
#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string txt,pat;
	getline(cin,txt);
	getline(cin,pat);

	int i=0,j=0,l=txt.length(),m=pat.length();
	string s="";

	string found="No string";

	int min_len=INT_MAX;
	bool ifprev=false;

	if(txt[0]==pat[0])
        ifprev=true;

	for(i=1;i<l;i++)
	{
		if(txt[i]==' ' && pat[j]!=' ')
		{
		    s="";
		    j=0;
		}

		if(ifprev)
            s+=txt[i];

		else if(txt[i]==pat[j])
		{
			j++;
			ifprev=true;
		}

		if(j==m)
		{
			if(s.length()<min_len)
			{
				found=s;
				min_len=found.length();
			}
		}
	}
	cout<<found;
	return 0;
}
