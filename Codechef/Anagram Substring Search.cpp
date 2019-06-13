#include<bits/stdc++.h>
using namespace std;

void computeLPSArray(string &pat, int M, int* lps)
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

int kmp_search(string &txt, string &pat, int N, int M)
{
	int lps[M];

	computeLPSArray(pat, M, lps);
	unordered_map<char,int> temp;
	for(int x=0;x<M;x++)
        {
            if()
        }
    if(temp.size)

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

main()
{

}
