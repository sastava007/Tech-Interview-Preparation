/*  As array is sorted so one way is to find upper_bound(0) for every row and check for minimum among the obatined result. 
    TC: O(row*log(col))

    Other way is to start from top right(0, m-1) and check if current value is zero, then move downwards(i++), else if current value is 1 then move towards left(j--)
    TC: O(m+n)
 */

 /**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface BinaryMatrix {
 *     public int get(int row, int col) {}
 *     public List<Integer> dimensions {}
 * };
 */

class Solution 
{
    public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) 
    {
         List<Integer> dimension=binaryMatrix.dimensions();
        int n=dimension.get(0);
        int m=dimension.get(1);
       
        int i=0,j=m-1,leftMostOne=-1;
        
        while(i<n && j>=0)
        {
            int result=binaryMatrix.get(i,j);
            if(result==0)
              i++;
            else{
                leftMostOne=j;
                j--;
             }
        } 
        return leftMostOne;
    }
}
