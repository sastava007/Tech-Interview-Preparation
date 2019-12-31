#include <bits/stdc++.h>
using namespace std;
#define maxn 100

void merge(int l, int r, int n, int *output)
{
    int mid=(l+r)/2;
	int l_in = l*n, r_in = (mid+1)*n;

	int l_c = (mid-l+1)*n;
	int r_c = (r-mid)*n;

	int left_array[l_c], right_array[r_c];

	for (int i = 0; i < l_c; i++)
		left_array[i] = output[l_in + i];

	for (int i = 0; i < r_c; i++)
		right_array[i] = output[r_in + i];

	int l_curr = 0, r_curr = 0;
	int in = l_in;

	while (l_curr + r_curr < l_c + r_c)
    {
		if (r_curr == r_c || (l_curr != l_c && left_array[l_curr] < right_array[r_curr]))
			output[in] = left_array[l_curr], l_curr++, in++;
		else
			output[in] = right_array[r_curr], r_curr++, in++;
	}
}

void divide(int l, int r, int n, int* output, int arr[][maxn])
{
	if (l == r)
	{
		for (int i = 0; i < n; i++)
			output[l * n + i] = arr[l][i];
		return;
    }
    int mid=(l+r)/2;
	divide(l, mid, n, output, arr);
	divide(mid+1, r, n, output, arr);
	merge(l, r, n, output);
}

main()
{
    int n,k;
    cout<<"Enter number of array: ";
    cin>>k;
    cout<<"Enter size of array: ";
    cin>>n;

    int arr[maxn][maxn];
    for(int i=0;i<k;i++)
        for(int j=0;j<n;j++)
        cin>>arr[i][j];

	int* output = new int[n * k];
	divide(0, k - 1, n, output, arr);
	for (int i = 0; i < n * k; i++)
		cout << output[i] << " ";
}
