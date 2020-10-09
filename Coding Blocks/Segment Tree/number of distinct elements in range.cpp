/* 
    A brute force solu is by using unordered_set<> but that would have time complexity of O(N*Q) 

    But by using Segment Tree, it can be solved in O(logN) per query
*/

#include <bits/stdc++.h> 
using namespace std; 
  
// Each segment of the segment tree would be a set to maintain distinct elements 
set<int>* segment; 
  
void build(int i, int s, int e, int arr[]) 
{
    if (s == e) {   // if just have single element
        segment[i].insert(arr[s]); 
        return; 
    } 
  
    // Else divide the range into two halves (start to mid) and (mid+1 to end) first half will be the left node and the second half will be the right node 
    build(2 * i, s, (s + e) / 2, arr); 
    build(1 + 2 * i, 1 + (s + e) / 2, e, arr); 
  
    // Insert the sets of right and left node of the segment tree 
    segment[i].insert(segment[2 * i].begin(), segment[2 * i].end()); 
    segment[i].insert(segment[2 * i + 1].begin(), segment[2 * i + 1].end()); 
}
  
// Query in an range a to b 
set<int> query(int node, int l, int r, int a, int b) 
{ 
    set<int> left, right, result; 
  
    // If the range is out of the bounds of this segment 
    if (b < l || a > r) 
        return result; 
  
    // If the range lies in this segment 
    if (a <= l && r <= b) 
        return segment[node]; 
  
    // Else query for the right and left leaf node of this subtree and insert them into the set

    left = query(2 * node, l, (l + r) / 2, a, b); 
    result.insert(left.begin(), left.end()); 
  
    right = query(1 + 2 * node, 1 + (l + r) / 2, r, a, b); 
    result.insert(right.begin(), right.end()); 
  
    return result; 
} 
  
// Initialize the segment tree 
void init(int n) 
{ 
    int h = (int)ceil(log2(n));     // Get the height of the segment tree 
    h = (2 * (pow(2, h))) - 1; 
    
    segment = new set<int>[h];  // Initialize the segment tree 
} 
  
// Function to get the result for the subarray from arr[l] to arr[r] 
void getDistinct(int l, int r, int n) 
{
    set<int> ans = query(1, 0, n - 1, l, r);  
    cout << ans.size() << endl; 
} 
  
// Driver code 
int main() 
{
    int arr[] = { 1, 1, 2, 1, 3 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    init(n); 
    build(1, 0, n - 1, arr); 
  
    getDistinct(0, 4, n);   // Query in range 0 to 4 
  
    return 0; 
} 