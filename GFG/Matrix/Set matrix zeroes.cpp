#include <bits/stdc++.h>
using namespace std;

/*
// Time Complexity: O(m*n)
// Space Complexity: O(1)
*/
void setZeroes(vector<vector<int>> &a, int rows, int cols)
{
    bool firstRow = false; 
    bool firstCol = false; 
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (a[i][j] == 0)
            { 
                if (i == 0)
                    firstRow = true;
                if (j == 0)
                    firstCol = true;
                a[i][0] = 0;
                a[0][j] = 0;
            }
        }
    }
    
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (a[i][0] == 0 || a[0][j] == 0)
            {
                a[i][j] = 0;
            }
        }
    }

    if (firstRow)
    {
        for (int i = 0; i < cols; i++)
            a[0][i] = 0;
    }

    if (firstCol)
    {
        for (int i = 0; i < rows; i++)
            a[i][0] = 0;
    }
}

/*
// Time Complexity: O(m*n)
// Space Complexity: O(m+n)

void setZeroes(vector<vector<int>> &matrix, int rows, int cols)
{
    vector<int> rowmarker(rowsize, 1);
    vector<int> columnmarker(columnsize, 1);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowmarker[i] = 0;
                columnmarker[j] = 0;
            }
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (rowmarker[i] == 0 || columnmarker[j] == 0)
                matrix[i][j] = 0;
        }
    }
}
*/

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    setZeroes(matrix, m, n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j];
        }
    }

    return 0;
}