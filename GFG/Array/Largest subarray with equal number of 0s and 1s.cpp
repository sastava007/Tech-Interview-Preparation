/* Similar to finding count of subarray with equal number of 0s and 1s
    We replace 0 with -1, and maintain a cumulative sum, whenever this sum equal to zero we know that there ocuured a subarray with zero sum starting from 0th index
    or when the current sum has already occured then we take diffeence of both indexes.
    
 */

int maxLen(int a[], int n) 
{
    int i, sum = 0, maxlen = 0;
    unordered_map<int, int> m;
    
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
            sum += -1;
        else
            sum += 1;
            
        if(sum == 0)
            maxlen = max(maxlen, i+1);
            
        if(m.find(sum) != m.end())
            maxlen = max(maxlen, i-m[sum]);
        else
            m[sum] = i;
    }
    
    return maxlen;
}