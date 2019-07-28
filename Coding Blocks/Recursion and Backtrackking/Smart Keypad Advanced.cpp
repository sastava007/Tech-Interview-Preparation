#include<bits/stdc++.h>
using namespace std;
#define ll long long

char keypad[][10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

vector<string> searchIn = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

void computeLPSArray(char *pat, int M, int lps[])
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

bool kmp_search(string txt, char *pat)
{
    int N=txt.length();
    int M=strlen(pat);

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

void phone_keypad(char *in, char *out, int i, int j)
{
    if(in[i]=='\0')
    {
        out[j]='\0';
        for(int i=0;i<searchIn.size();i++)
        {
            if(kmp_search(searchIn[i],out))
            {
                cout<<searchIn[i]<<"\n";
                break;
            }
        }

        return;
    }

    int digit=in[i]-'0';
    if(digit==0||digit==1)
        phone_keypad(in,out,i+1,j);
    for(int k=0;keypad[digit][k]!='\0';k++)
    {
        out[j]=keypad[digit][k];
        phone_keypad(in,out,i+1,j+1);
    }

}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    char in[100],out[100];

    cin>>in;
    phone_keypad(in,out,0,0);

}
