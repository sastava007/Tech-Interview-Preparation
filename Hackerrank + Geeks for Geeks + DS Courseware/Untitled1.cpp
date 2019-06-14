#include <bits/stdc++.h>
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

int kmp_search(string txt, string pat, int N, int M)
{
	int lps[M];

	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
  	int c=0;
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			c++;
			j = lps[j - 1];
		}

		else if (i < N && pat[j] != txt[i]) {

			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
  	return c;
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    string txt,pat;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        cin>>txt;
        cin>>pat;
        pat=pat.substr(0,k);
        int c=kmp_search(txt,pat,n,k);
        if(c!=0)
            cout<<c<<"\n";
        else
            cout<<"-1\n";

    }
}
