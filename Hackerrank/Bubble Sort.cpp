/*
#include<bits/stdc++.h>
using namespace std;
main()
{
    int a[]={10, 7, 8, 9, 1, 5};
    int i,j,temp,n=6;
   bool switched=true;
    for( i=0;i<n-1&&switched==true;i++)
    {
        bool switched=false;
        for( j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                switched =true;
            }
        }
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
*/

/*
    BUBBLE SORT USING RECURSION
    */
#include<bits/stdc++.h>
using namespace std;
void bubble_sort(int a[],int n)
{
    static int i=0,j=0;
    static bool switched =true;
    if(i<n-1)
    {
        switched=false;
        if(j<n-1-i)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                switched=true;
            }
            j++;
            bubble_sort(a,n);
        }
        j=0;
      i++;
      bubble_sort(a,n);
    }

}
main()
{
    int a[]={5,1,4,2,8};
    bubble_sort(a,5);
    for(int i=0;i<5;i++)
        cout<<a[i]<<" ";
}
