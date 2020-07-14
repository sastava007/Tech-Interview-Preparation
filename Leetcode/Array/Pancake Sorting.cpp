/* 
    Find the maximum number index in array of length n, supppse it idx;
    Reverse the array from (0 to idx), now max number comes at index 0. 
    Reverse the complete array now, max element is now at index, arr.size()-1

    Now again find the maxinum index of array in length (n-1), as maximum is already at its position.
    Repeat above

    TC O(N^2) and O(N) Space
*/

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> result;
        for(int i = 0;i < A.size();i++)
        {
           auto maxPosition = max_element(A.begin(), A.end() - i);

           result.push_back(maxPosition  - A.begin() + 1);
           result.push_back(A.size() - i);

           reverse(A.begin(),maxPosition+1);
           reverse(A.begin(),A.end() - i);
        }
        return result;
    }
};