#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void formalize_querry(string &line , vector<string> &fq);

void querry(string& que, vector<vector<string>> &vv){
    vector<string> fq ;
    formalize_querry(que,fq);
    vector<string> ans;
    for(auto line : vv){
       if(line[0][0]=='/'){
            ans.pop_back();
       }else{
            ans.push_back(line[0]);
       }
       
       if(ans==vector<string>(fq.begin(),fq.end()-1)){
        for(auto w=line.begin(); w!=line.end()-1; w++){
            if(*w==*(fq.end()-1)){
                cout<<string((*(w+1)).begin()+1,(*(w+1)).end()-1)<<endl;
                return;
            }
        }
       } 
    }
        cout<<"Not Found!"<<endl;

}

void formalize_querry(string &line , vector<string> &fq){
    string word="";
    for(char c : line){
        if(c!='.' && c!= '~'){ word+=c;}
        else{
            fq.push_back(word);
            word="";
        }
    }
    fq.push_back(word);
}

void formalize_entry(const string& line,vector<string> &vv){
    string word="";
    for(char c : line){
        if(c=='<'){continue;}
        if(c=='='|| isspace(c)  || c=='>'){
            if(!word.empty())vv.push_back(word);
            word="";
            continue;
        }else{
            word+=c;
        } 
        
    }
 
}

int main() {
    int n,q;
    cin>>n>>q;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<vector<string>> v; // formalized version of entry
    vector<string> vv; // a line
    vector<string> qq; // a querry
    string line;
    vector<string> cp;
    for(int i=0; i<n; i++){
        getline(cin,line);
        formalize_entry(line, vv);
        //is formalize right ??
        cp=vv;
        v.push_back(cp);
        // printv(v);
        vv={};
        
    }
       
   
    for(int i=0; i<q; i++){
        getline(cin,line);
        querry(line,v);
    }

    
    
    
    return 0;
}
