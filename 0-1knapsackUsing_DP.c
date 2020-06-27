#include<stdio.h> 
#include<time.h>

int max(int a, int b) 
{ 
	return (a>b)?a:b; 
} 

void getinput(int n, int array[])
{
	for(int i=0;i<n;i++)
	{
		printf("Object %d :: ",i+1);
		scanf("%d",&array[i]);
	}
}

int knapsack(int W, int wt[], int val[], int n) 
{ 
	int i,w,K[n+1][W+1]; 
	for(i=0;i<=n;i++) 
	{ 
       		for(w=0;w<=W;w++) 
       		{ 
           		if(i==0 || w==0) 
               			K[i][w] = 0; 
           		else if (wt[i-1]<=w) 
                 		K[i][w]=max(val[i-1]+K[i-1][w-wt[i-1]], K[i-1][w]); 
           		else
                		K[i][w]=K[i-1][w]; 
       		} 
   	} 
	return K[n][W]; 
} 
  
int main() 
{ 
	int W,n;
	printf("What is your knapsack capacity? ");
	scanf("%d",&W);
	printf("How many objects? ");
	scanf("%d",&n);
	int val[n],wt[n];
	printf("Enter values of profit for %d objects :: \n",n);
	getinput(n,val);
	printf("Enter corresponding weights for %d objects :: \n",n);
	getinput(n,wt);
	clock_t start,end;
	start=clock();
	printf("Total profit of the knapsack :  %d. \n	", knapsack(W, wt, val, n));
	end=clock();
	double time=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n\nTime taken :: \nStart = %ld\nEnd = %ld\nTotal time taken = %f\n\n",start,end,time); 
   	 return 0; 
}
