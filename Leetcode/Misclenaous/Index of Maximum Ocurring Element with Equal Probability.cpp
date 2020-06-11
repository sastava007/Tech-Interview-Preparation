/* One way to do, is to use some kind of hashtable to count the freq of each element, and then select the element with maximum frequency. This requires O(N) time and O(N) space */

/*  Another way is to use Reservoir Sampling 
    Input: [11, 30, 2, 30, 30, 30, 6, 2, 62, 62] here we should return indexes randomly in [1,3,4,5]
*/

int maxRandomIndex(vector<int> nums)
{
    int max = INT_MIN, max_index=0, count=0;
    srand(time(NULL));

    for(int i=0; i<nums.size(); i++)
    {

        if(nums[i]>max[i])
        {
            max=nums[i];
            max_index=i;
            count=1;
        }
        else if(max==nums[i])
        {
            count++;
            if(rand()%count==0)
                max_index = i;
        }
        
    }

    return max_index;
}