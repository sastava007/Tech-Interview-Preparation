#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string first,second;
    
    cin>>first>>second;
    
    cout<<first.size()<<" "<< second.size()<<endl;
    
    // Concatinate the strings
    cout<<first+second<<endl;
    
    // Swap the first and last character
    // char temp=first[0];
    // first[0]=second[0];
    // second[0]=temp;
    
    // Usin swap function
    swap(first[0], second[0]);
    cout<<first<<" "<<second;


    return 0;
}
