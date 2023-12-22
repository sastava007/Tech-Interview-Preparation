class Solution
{
  public:
      long long int atMostK(string &s,int k){
      vector<long long int>freq(26,0);
      long long int start =0,count=0,distinct=0;
      
      for(int i=0; i<s.size();i++){
          if(freq[s[i]-'a']==0)
           distinct++;
          freq[s[i]-'a']++;
          
          while(distinct>k){
              freq[s[start]-'a']--;
              if(freq[s[start]-'a']==0)
              distinct--;
              start++;
          }
          if(distinct<=k)
          count = count+i-start+1;
      }
      return count;
  }
    long long int substrCount (string s, int k) {
    	//code here.
    	return atMostK(s,k) -atMostK(s,k-1);
    }


};
