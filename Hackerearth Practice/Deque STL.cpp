/*Given an array and an integer k, find the maximum for each and every contiguous subarray of size k
                                      using SLIDING WINDOW ALGORITHM */
/*https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/*/

#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k){
	int i;
    deque<int > a;
    for(i=0;i<k;i++)
    {
        while(!a.empty() &&arr[i]>=arr[a.back()])
        a.pop_back();
        a.push_back(i);
    }
    for(i=k;i<n;i++)
    {
        //print the largest element of previous window
        printf("%d ",arr[a.front()]);
        //remove the first element of previous window
        if(a.front() <=i-k)
        a.pop_front();
        //insert the remaining elements with the same logic
        while(!a.empty()&&arr[i]>=arr[a.back()])
        a.pop_back();
        a.push_back(i);
    }
    printf("%d\n",arr[a.front()]);
}

int main(){

	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	scanf("%d%d",&n,&k);
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		scanf("%d",&arr[i]);
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

