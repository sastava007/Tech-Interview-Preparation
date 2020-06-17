/*  As array is sorted so one way is to find upper_bound(0) for every row and check for minimum among the obatined result. 
    TC: O(row*log(col))

    Other way is to start from top right(0, m-1) and check if current value is zero, then move downwards(i++), else if current value is 1 then move towards left(j--)
    TC: O(m+n)

    As we're given that matrix is sorted from left->right, so we'll have 0 at left and 1 at right. 

    Note: This is an invalid matrix
    
    matrix2    =          {{0, 0, 0, 0},
                          {0, 1, 0, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0}};

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
