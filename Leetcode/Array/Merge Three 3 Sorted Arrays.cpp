/*  One way is to merge 2 at a time, and then merge the 3rd one with obatined result from the pevious merge. This requires O(m+n+o) time and O(m+n) extra space to hold the result obtained by first 2 
    merge methods. 

    We can do something better, if we somehow able to merge 3 at a time, O(m+n+o) time and O(1) space becz we don't need to maintain any temporary vector to store result of first two merge
*/

Vector mergeThree(Vector& A, Vector& B, Vector& C) 
{ 
    int m, n, o, i, j, k; 
    m = A.size(); 
    n = B.size(); 
    o = C.size(); 

    Vector D; 
    D.reserve(m + n + o); 
  
    i = j = k = 0; 
  
    while (i < m && j < n && k < o) { 
  
        // Get minimum of a, b, c 
        int m = min(min(A[i], B[j]), C[k]); 
  
        // Put m in D 
        D.push_back(m); 
  
        if (m == A[i])      // to remove duplicates replace if with while
            i++; 
        else if (m == B[j]) 
            j++; 
        else
            k++; 
    }
  
    // C has exhausted 
    while (i < m && j < n)  // similarly do it for other 2 parts as well : while to remove the duplicates
    {
        if(A[i]==B[j])
        {
            D.push_back(A[i]);
            cur=A[i];
            while(A[i]==cur)
                i++;
            while(B[j]==cur)
                j++;
        }
        else if(A[i]<B[j])
            i++;
        else
            j++;
    } 
  
    // B has exhausted 
    while (i < m && k < 0) { 
        if (A[i] <= C[j]) { 
            D.push_back(A[i]); 
            i++; 
        } 
        else { 
            D.push_back(C[j]); 
            k++; 
        } 
    } 
  
    // A has exhausted 
    while (j < n && k < 0) { 
        if (B[j] <= C[k]) { 
            D.push_back(B[j]); 
            j++; 
        } 
        else { 
            D.push_back(C[j]); 
            k++; 
        } 
    } 
  
    // A and B have exhausted 
    while (k < o) 
        D.push_back(C[k++]); 
  
    // B and C have exhausted 
    while (i < m) 
        D.push_back(A[i++]); 
  
    // A and C have exhausted 
    while (j < n) 
        D.push_back(B[j++]); 
  
    return D; 
} 