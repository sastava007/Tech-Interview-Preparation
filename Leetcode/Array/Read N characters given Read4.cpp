/* We're given an API int read4() that reads 4 character at a time, and return the no. of characters read. We've to implement a method to read N characters */

#include<bits/stdc++.h>
using namespace std;

int read(string &buff, int n)
{
    bool eof = false;
    int total = 0;
    while(!eof && total<n)
    {
        char temp[4];
        int count = read4(temp);

        eof = count<4;  // if we've reached the end of file, such that the total characters left in file is less than 4. Which means we don't need to call it another time.

        count = min(count, n-total);    // (n-total) depicts the more characters that we've to read. So suppose we have to just read 2 more characters but read4() API has read 4 chaacters

        for(int i =0; i<count; i++)
            buff[total++] = temp[i]; 
    }

    return total;
}

/*  In above solu, we've assumed that this mentod is called just single time. But if this method is called multiple times then we have to save the status of the internal buffer 
    that indicates past character read.
 */

int read(string &buff, int n)
{
    static int charactersInBuffer = 0;
    static int offset = 0;
    static char temp[4];

    bool eof = false;
    int total = 0;
    while(!eof && total<n)
    {
        if(charactersInBuffer == 0)
        {
            charactersInBuffer = read4(temp);
            eof = charactersInBuffer<4;
        }

        int numCharactersUsed = min(charactersInBuffer, n-total);
        for(int i =0; i<numCharactersUsed; i++)
        {
            buff[total++] = temp[offset+i];
        }

        charactersInBuffer -= numCharactersUsed;    //decrease the no. of characters that has been used from the current buffer
        offset = (offset + numCharactersUsed)%4;    //store the offset for next operation, i.e from which position to start copying when you call next
    }

    return total;
}