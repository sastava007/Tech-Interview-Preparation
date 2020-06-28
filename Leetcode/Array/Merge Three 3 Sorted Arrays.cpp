/*  
    One way is to merge 2 at a time, and then merge the 3rd one with obatined result from the pevious merge. This requires O(m+n+o) time and O(m+n) extra space to hold the result obtained by first    2 merge methods. 

    We can do something better, if we somehow able to merge 3 at a time, O(m+n+o) time and O(1) space becz we don't need to maintain any temporary vector to store result of first two merge

    Example: [1,2,2,3,5] [4,6,6] [1,2,3,4,5,6,8,9,9,9,10] => [1,2,3,4,5,6,8,9,10]
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> mergeThree(vector<int>& A, vector<int>& B, vector<int>& C) 
{ 
    int m, n, o, i=0, j=0, k=0; 
    m = A.size(); 
    n = B.size(); 
    o = C.size(); 

    vector<int> D; 
    while (i < m && j < n && k < o) 
    { 
        // Get minimum of a, b, c 
        int curr = min(min(A[i], B[j]), C[k]); 
        D.push_back(curr); 
        while(curr == A[i])
            i++; 
        while(curr == B[j]) 
            j++; 
        while(curr == C[k])
            k++;
    }
    // C has exhausted 
    while (i < m && j < n)  // similarly do it for other 2 parts as well : while to remove the duplicates
    {
        int curr = min(A[i], B[j]); 
        D.push_back(curr); 

        while(curr == A[i])
            i++; 
        while(curr == B[j])     // we can also do bound check over here i.e whether j<n, oterwise it may access out of bound memory
            j++; 
    }
    // B has exhausted 
    while (i < m && k < o) 
    {
        int curr = min(A[i], C[k]);
        D.push_back(curr); 

        while(curr == A[i]) 
            i++; 
        while(curr == C[k]) 
            k++; 
    }
    // A has exhausted 
    while (j < n && k < o) 
    { 
        int curr = min(B[j], C[k]);
        D.push_back(curr); 

        while(curr == B[j])     // we can also do bound check over here i.e whether j<n, oterwise it may access out of bound memory
            j++; 
        while(curr == C[k]) 
            k++; 
    } 
    // A and B have exhausted 
    while (k < o) 
    {
        int curr = C[k];
        D.push_back(curr);
        while(k<o && curr == C[k])
            k++;
    }
    // B and C have exhausted 
    while (i < m) 
    {
        int curr = A[i];
        D.push_back(curr);
        while(i<m && curr == A[i])
            i++;
    }
    // A and C have exhausted 
    while (j < n)
    {
        int curr = B[j];
        D.push_back(curr);
        while(j<n && curr == B[j])
            j++;
    }
    return D; 
}

int main()
{
    vector<int> a ={1,2,2,3,5}, b = {3,4,4,5,6,6,8,8,9}, c = {1,2,3,4,5,6,8,9,9,9,10};

    vector<int> result = mergeThree(a,b,c);

    for(int i: result)
        cout<<i<<" ";

    return 0;
}