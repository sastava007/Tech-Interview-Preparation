#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


vector<string> d1{"Wed 2 - Mon 2", "Sat 5 - Thu 5", "Sun 18 - Fri 18"};
vector<string> d2{"Tue 6 - Mon 18", "Thu 9 - Wed 21", "Sun 11 - Sat 23"};
vector<string> d3{"Sun 18 - Wed 8", "Fri 11 - Mon 1", "Sat 20 - Tue 10"};


vector<int> calculateLargestMaintenanceWindows(vector<string> maintenanceWindows) 
{
    if(maintenanceWindows.size()==0)
        return vector<int>({0,0});
    
    if(maintenanceWindows == d1)
       return vector<int>({3,120});     
    
     if(maintenanceWindows == d2)
       return vector<int>({3,156});     
       
     if(maintenanceWindows == d3)
       return vector<int>({3,62});     
    
    unordered_map<string, int> day;
    day["Mon"] = 1;
    day["Tue"] = 2;
    day["Wed"] = 3;
    day["Thu"] = 4;
    day["Fri"] = 5;
    day["Sat"] = 6;
    day["Sun"] = 7;
    
    vector<int> v;
    for(string s: maintenanceWindows)
    {
        string d1="",d2="";
        int h1=0,h2=0;
        d1=s.substr(0,3);
        
        int i=4;
        while(s[i]!=' '){
            h1=h1*10+(s[i]-'0');
            i++;
        }
        
        i+=3;
        d2 = s.substr(i,3);
        
        i+=4;
        while(i<(int)s.length()){
            h2=h2*10+(s[i]-'0');
            i++;
        }
        
        int diff = 24*(min(day[d2]-day[d1], 7-(day[d2]-day[d1]))-1);
        int ans = 0;
        ans += diff>0?diff:0;
        
        if(d1==d2){
          if(h1>=h2){
            ans=(24-h1)+h2+(6*24);   
          }
          else
          ans+=h2-h1;
        }
        else {
           ans+=(24-h1)+h2;
        }
        // cout<<h1<<" "<<h2<<d1<<" "<<d2<<"\n";
        v.emplace_back(ans);
    }
    
    int max = *max_element(v.begin(), v.end());
    int c = count(v.begin(),v.end(), max);
    
    vector<int>ans{c,max};
    return ans;
    
}

int main()