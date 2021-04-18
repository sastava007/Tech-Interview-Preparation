/*  
    We've to group the files in system, which has common content. So basically our idea is to use content of file as a key in a hash-map and add address of all the files having same content

    Input = ["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
    Output = [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]

    TC and Space: O(N*S) where N is total no. of strings and S is avg. length of each string
*/

vector<vector<string>> findDuplicate(vector<string>& paths) 
{
    unordered_map<string, vector<string>> m;
    vector<vector<string>> result;
    
    for(string path: paths)
    {
        int i = 0;
        while(i < path.size())
        {
            string directoryPath = "";
            while(path[i] != ' ')
            {
                directoryPath += path[i];
                i++;
            }
            i++; // skip the space
            while(i < path.size())
            {
                string fileName, content;
                while(i< path.size() && path[i] != '(')
                    fileName += path[i++];
                i++; // skip the (
                while(i< path.size() &&  path[i] != ')')
                    content += path[i++];
                
                m[content].push_back(directoryPath+"/"+fileName);
                i+=2;   // skip the ')' and space
            }
        }
    }
    for(auto it: m)
        if(it.second.size() > 1)
            result.push_back(it.second);
    return result;
}

/*

1.  Imagine you are given a real file system, how will you search files? DFS or BFS ?
    In general, BFS will use more memory then DFS. However BFS can take advant  age of the locality of files in inside directories, and therefore will probably be faster.
    DFS consumes less memory, becz it only need to store the info. of next node to traverse, wheras BFS will first store all the nodes at that level & then only move to next.

    Just for a file system, it's more common the case you have 100 files stored in one folder, instead of 100 level of directories

2.  If the file content is very large (GB level), how will you modify your solution?
    In a real life solution we will not hash the entire file content, since it's not practical. Instead we will first map all the files according to size. Files with different sizes are guaranteed to be different. We will than hash a small part of the files with equal sizes (using MD5 for example). Only if the md5 is the same, we will compare the files byte by byte

3.  If you can only read the file by 1kb each time, how will you modify your solution?
    This won't change the solution. We can create the hash from the 1kb chunks, and then read the entire file if a full byte by byte comparison is required.

4.  What is the time complexity of your modified solution? What is the most time consuming part and memory consuming part of it? How to optimize?
    Time complexity is O(n^2 * k) since in worse case we might need to compare every file to all others. k is the file size
    The most time consuming part is generating hash, we can optimize it by using efficient hashing algorithms 

5.  How to make sure the duplicated files you find are not false positive?
    We will use several filters to compare: File size, Hash and eventually byte by byte comparisons.

*/