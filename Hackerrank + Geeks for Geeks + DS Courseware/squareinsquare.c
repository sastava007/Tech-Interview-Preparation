#include<stdio.h>
main()
{
	int c=1,n,i,j,x,s=0,k;
	scanf("%d",&n);
	k=n-1;
	
		
	  while(1)
	  {
		   for(i=0;i<n;i++)
		   {
		    for(j=0;j<n;j++)
		    {
			if(i<=s||i>=k||j<=s||j>=k)
			printf("+");
			else
			printf(" ");
		    }
		    printf("\n");
		   }
		  printf("\n1.Continue\n0.Exit\n");
     	  scanf("%d",&c);
     	  if(c==0)
     	  break;
     	  s++;
     	  k--;
      }
    
        
    
      
     	
     
}
