


string merge (string s1, string s2)
{
    // your code here
    string s;
    int n=s1.size(), m = s2.size();
    int i=0, j=0;
    
    while(i<n && j<m){
        s += s1[i++];
        s += s2[j++];
    }
    
    while(i != n){
        s += s1[i++];
    }
    
    while(j != m){
        s += s2[j++];
    }
    
    return s;
}
