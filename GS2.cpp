class Solution {
public:
    vector<int> findSpecialProduct( vector<int> inputArray ) {
        int n = nums.size();
        vector<int> result( n, 1 );
        for( int i=1; i < n; ++i ) {
			// get the product from start
            result[i] = result[i-1]*nums[i-1];
        }
        int productFromLast = 1;
        for( int i=n-1; i >= 0; --i ) {
            result[i] = result[i]*productFromLast;
			// get product from end on the go.
            productFromLast = productFromLast * nums[i];
        }
        return result;
    }
};
