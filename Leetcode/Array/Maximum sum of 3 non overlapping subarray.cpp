/* 
    Since we only care about the sum of the subarray. We can create an array and store the subarray sum starting from each index.
    If we start from the left index, middle index and right index, this will be very slow because the middle index is dependent on the left index and the right index is dependent on the middle index. So the optimization is Decoupling. Let left and right index both connect to the middle index. Then, the left and right index can be updated separately. By the way, the range of left, middle and right indices are 0 -> middle-k, k -> nums.length-2k and middle+k -> end

    Updating: we need to check the situations for each middle index. With middle index moving forward, we can figure out the range of left index and right index. The range of the left index increases one while the one of right index decreases one for each iteration. So, this allows us to use the information from the previous iteration.
    For left index: we only need to check the sum of the new left index is bigger than the previous max one.
    For right index: we only update when the previous max index is no longer in the range.
    Hope you can like this solution.

 */

class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        int m = n - k + 1;
        int[] sum = new int[m];
        for(int i = 0; i < k; i++) sum[0] += nums[i];
        for(int i = 1; i < m; i++) sum[i] = sum[i-1] + nums[i+k-1] - nums[i-1];
        int[] res = new int[]{0, k, 2*k-1};
        int[] temp = new int[]{0, k, 2*k-1};
        int max = Integer.MIN_VALUE;
        for(int middle = k; middle <= n-2*k; middle++) {
            temp[1] = middle;
            //update the left index (temp[0]) when the new left index.
            if(sum[temp[0]] < sum[middle-k]) temp[0] = middle-k;
            //update the right index(temp[1]) when previous max index is not in the range.
            if(temp[2] < middle+k) {
                int tempR = Integer.MIN_VALUE;
                for(int right = middle+k; right < m; right++) {
                    if(tempR < sum[right]) {
                        tempR = sum[right];
                        temp[2] = right;
                    }
                }
            }
            if(max < sum[temp[0]] + sum[temp[1]] + sum[temp[2]]) {
                max = sum[temp[0]] + sum[temp[1]] + sum[temp[2]];
                res[0] = temp[0];
                res[1] = temp[1];
                res[2] = temp[2];
            }
        }
        return res;
    }
}