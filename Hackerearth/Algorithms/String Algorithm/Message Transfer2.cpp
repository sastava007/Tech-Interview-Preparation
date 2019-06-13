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

void kmp_search(string txt, string pat, vector<int> index)
{
    int N=txt.length();
    int M=3;
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
			index.push_back(i-j);
			j = lps[j - 1];
		}

		else if (i < N && pat[j] != txt[i]) {

			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}

}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i;
    cin>>t;
    string s;
    while(t--)
    {
        cin>>s;
        vector<int> index;
        kmp_search(s,"WUB",index);
        for(auto it:index)
        {
            for(i=0;i<it;i++)
            cout<<s[i];
            cout<<" ";
        }
        cout<<"\n";
    }

}
