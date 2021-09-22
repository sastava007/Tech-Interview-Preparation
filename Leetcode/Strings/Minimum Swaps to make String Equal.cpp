/* 
    Given 2 equal length string, that contains only x and y characters. Find the minimum no. of swaps to make them equal. We can swap string1[i] with string2[j] 
    Example: 
        S1 = "xx"  =>   x [y]      After 1 swap 
        S2 = "yy"  =>   [x] y

    Example: 
        S1 = "xy"  =>  After 1 swap     x[x]   After 2 swap     =>  x[y]
        S2 = "yx"  =>                   y[y]                    =>  [x]y
*/

/* 
    Idea: So we know that at ith place either both the characters will be same or we can (x/y) or (y/x).
    And for every (x/y) pair we need 1 swap [x x]  we can perform 1 swap and similarly for  [y y]  we can do 1 swap     (a)
                                            [y y]                                           [x x]
    And if there's a combination of [x y] then  we need 2 swap which can computed by (xy%2 + yx%2)                      (b)
                                    [y x]
*/

int minimumSwap(string s1, string s2) 
{
    int xy  = 0, yx = 0;
    for(int i=0; i<s1.size(); i++)
    {
        if(s1[i]=='x' && s2[i]=='y')
            xy++;
        else if(s1[i]=='y' && s2[i]=='x')
            yx++;
    }
    
    if((xy%2 + yx%2)%2 == 1)   // this means that either of them is present 0 and 1 number of times, or #x and #y are present odd number of times  
        return -1;
    
    return (xy/2 + yx/2 + xy%2 + yx%2);     // formula obtained as a+b
}