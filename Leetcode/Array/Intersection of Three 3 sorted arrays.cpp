/*  Find the intersection(and not merge) of three sorted array 
    
    Clarifying Questions to ask:
        1. What if one of the arrays is empty? should be return empty result
        2. Can there be duplicated, becz this code doesn't handle case of duplicates
*/

class Solution
{
    public List<Integer> arraysIntersection(int[] arr1, int[] arr2, int[] arr3)
    {
        List<Integer> res = new ArrayList<>();
        if(arr1 == null || arr2 == null || arr3 == null)    // if any one of the array is empty, then return empty reusult
        {
            return res;
        }

        int i = 0, j = 0, k = 0;

        while(i < arr1.length && j < arr2.length && k < arr3.length)
        {
            if(arr1[i] == arr2[j] && arr1[i] == arr3[k])
            {
                res.add(arr1[i]);
                i++;
                j++;
                k++;
            }else if(arr1[i] < arr2[j]){    
                i++;
            }else if(arr2[j] < arr3[k]){        // this means that arr1[i] >= arr2[j], this means that 2 is smallest among all element
                j++;
            }else{              // this means that arr3[k] is smallest so increment K
                k++;
            }
        }
        return res;
    }
};