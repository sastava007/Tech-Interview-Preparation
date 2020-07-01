/* 
    Given an int array wood representing the length of n pieces of wood and an int K. It is required to cut these wood block into >=K pieces of same length.
    What is the longest len you can get?

    Idea: Is to use discrete binary search, if we can cut pieces if 'mid' length and achieve total no. of pieces >=K then we can also achieve the same by cutting into smaller length, so no
    need to check for smaller length, go further and try to next feasible length.

    Input: [5, 9, 7], k = 4  Output: 4
    Input: [20, 5, 20], k = 4  Output: 10 (we've discarded 5, though we were getting more blocks of same length if we cut for 5 length)
*/

public int cutWood(int[] wood, int k)
{
    // corner cases:
    if(wood.length == 0 || k == 0) 
        return 0;

    int left = 1, right = *max_element(wood.begin(), wood.end());
    int res = 0;

    if(!isValid(wood, left, k))     //just safety check, if it's even possible to achive the same by cutting into length of 1
        return 0;

    while(left < right)
    {
        int mid = left + (right - left)/2;
        boolean valid = isValid(wood, mid, k);
        if(valid){
            left = mid + 1;
            res = mid;
        }
        else
            right = mid;
    }
    return res;
}

boolean isValid(int[] wood, int cutLength, int k)
{
        int count = 0;
        for(int w: wood){
            count += w / cutLength;
        }
        return count >= k;
}
