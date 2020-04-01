/*
    https://practice.geeksforgeeks.org/problems/equal-sum-and-xor/1
    https://www.geeksforgeeks.org/equal-sum-xor/
    n+i = n^i this implies that n&i=0 which means that i has to unset all the set bits of n.
    So if we take an example n=12 1 1 0 0 then i must has initial 2 bits as 0 and rest can be anything i.e 0 0 0/1 0/1 => 2^2 
    i.e the number of unset bits in 'n'
*/

int numOfBits(int n)
{
    int x=log2(n)+1;
    return x;
}

int countValues (int n)
{
   return (1<<(numOfBits(n)-__builtin_popcount(n)));
}