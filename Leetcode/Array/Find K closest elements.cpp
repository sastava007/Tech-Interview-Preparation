/*  Naive Approach: Sorting (nlogn)  
    Max Heap: O(nlogk) 
    {
        If there isn't k elements on the heap yet, we can just push the element onto the max_heap
        If there is k elements on the heap and the current element we are on is closer to x than the element at the top of the heap , we can pop of the top element and push the current element on.
        Finally after iterating over the list we can pop all k elements off the heap into a list and sort the list
    }

    Two Pointers: O(n)
    Binary Search + Two Pointers: O(logn + k)

    The idea is to find the first number which is equal to or greater than x in arr. Then, we determine the indices of the start and the end of a subarray in arr, where the subarray is our result. The time complexity is O(logn + k).

    Note: Here the array is alaready given sorted

*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        // int index = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int index = lowerBound(arr, x);
        int i=index-1, j=index;     //the idea is to get two indices and then keep on expanding towards left & right
        
        while(k--)
        {
            if(i<0 || (j<arr.size() && abs(arr[i]-x) > abs(arr[j] -x))) // as diff. is greter at i side so if we move back, then diff is only going to increse so there's no way of going back. So move forward 
               j++;
            else
               i--;
        }
        vector<int> result(arr.begin()+i+1, arr.begin()+j);
        return result;
    }
private:
    int lowerBound(vector<int> &arr, int x)     //lower_bound implementation
    {
        int low=0, high=arr.size()-1;
        while(low<=high)
        {
            if(low==high)
                return low;
            int mid = low + (high-low)/2;
            if(arr[mid]<x)
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
};

/* 2 Pointers: O(N) */
class Solution 
{
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int lo = 0;
		int hi = arr.length - 1;
		while (hi - lo >= k) {
			if (Math.abs(arr[lo] - x) > Math.abs(arr[hi] - x)) {
				lo++;
			} else {
				hi--;
			}
		}
		List<Integer> result = new ArrayList<>(k);
		for (int i = lo; i <= hi; i++) {
			result.add(arr[i]);
		}
		return result;
    }
}