#include <bits/stdc++.h>
using namespace std;

void split(const string &s, char delimeter, vector<string> &words) 
{ 
    string token; 
    stringstream tokenStream(s); 
    while (getline(tokenStream, token, delimeter)) 
        words.push_back(token); 
}

string distance(string s, string w1, string w2) 
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    transform(w1.begin(),w1.end(), w1.begin(), ::tolower);
    transform(w2.begin(), w2.end(), w2.begin(), ::tolower);
    
    vector<string> words; 
    split(s, ' ', words);
    
    int min_dist = words.size() + 1;
    
    int start=-1,end=-1;
    
    string match;
    for (int index = 0; index < words.size(); index++) 
    {
//        cout<<words[index]<<" "<<w1<<"1"<<endl;
        if (words[index] == w1 || words[index]==w2) 
        {
            if(start==-1)
            {
                match=words[index];
                start=index;
            }
            else
            {
                if(end==-1 && words[index]!=match)
                {
                    end=index;
                    break;
                }
                if(words[index]==match)
                {
                    start=index;
                }
            }
        } 
    }

    string ans="";
    if(start==-1 || end==-1)
    return ans;
	start=start-3;
	end=end+3;

    for(int i=max(start,0); i<=min(end,(int)words.size()-1); i++)
    {
        ans+=words[i]+" ";
    }
    
    return ans; 
}

string searchSnippet(string content, string queryW1, string queryW2) 
{    
    return distance(content, queryW1, queryW2);
}
int main()
{
	string con, q1, q2;
	getline(cin, con);
	cin>>q1>>q2;
	cout<<searchSnippet(con, q1, q2);
}