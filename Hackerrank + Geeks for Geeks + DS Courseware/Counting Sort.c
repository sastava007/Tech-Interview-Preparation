#include<stdio.h>
int main()
{
    int n;
    int i;
    scanf("%d",&n);
    int a[n];
    int max, min;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(i==0){
            max = a[i];
            min = a[i];
        }else if(a[i] > max){
            max = a[i];
        }else if(a[i] < min){
            min = a[i];
        }
    }
    int f[max-min+1];
    
    for(int i = 0; i < max-min+1; i++){
        f[i] = 0;
    }
    
    for(int i = 0; i < n; i++){
        f[a[i]-min]++;
    }
    
    for(int i = 0; i <= max-min; i++){
        while(f[i]-- > 0){
            printf("%d ", i+min);
        }
    }
}
