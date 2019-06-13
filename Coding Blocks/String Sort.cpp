#include<bits/stdc++.h>
using namespace std;

void computeLPSArray(string pat, int M, int lps[])
{
	int len = 0;
    lps[0] = 0;
    int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0) {
				len = lps[len - 1];


			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

bool kmp_search(string txt, string pat)
{
    int N=txt.length();
    int M=pat.length();

	int lps[M];

	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]

	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			return true;
		}

		else if (i < N && pat[j] != txt[i]) {

			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
  	return false;
}
 bool compare(string a,string b)
 {
     if(kmp_search(a,b))
     {
         return a.length() > b.length();
     }
     else
        return a<b;
 }
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n,i;
	cin>>n;
	vector<string> s(n);
	for(i=0;i<n;i++)
	cin>>s[i];

	sort(s.begin(),s.end(),compare);

	for(i=0;i<n;i++)
        cout<<s[i]<<"\n";

}
