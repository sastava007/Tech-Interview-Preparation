class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int start = 0, end = m*n -1;

        while(start<=end){
            int mid = (start + end)/2;

            if(matrix[mid/n][mid%n] == target){
                return true;
            }

            if(matrix[mid/n][mid%n]<target){
                start = mid + 1;
            }

            else{
                end = mid -1;
            }
        }
        return false;
    }
};
