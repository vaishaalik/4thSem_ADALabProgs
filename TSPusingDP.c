#include<stdio.h>
#include<time.h>

int a[10][10],completed[10],n,cost=0;

int least(int c)
{
	int i,nc=999;
	int min=999,kmin;
	for(i=0;i < n;i++)
		if((a[c][i]!=0)&&(completed[i]==0))
    			if(a[c][i]+a[i][c] < min)
      			{
        			min=a[i][0]+a[c][i];
        			kmin=a[c][i];
        			nc=i;
      			}
	if(min!=999)
		cost=cost+kmin;
	return nc;
}

void mincost(int city)
{
	int i,ncity;
	completed[city]=1;
	printf("%d--->",city+1);
	ncity=least(city);
	if(ncity==999)
	{
  		ncity=0;
  		printf("%d",ncity+1);
  		cost=cost+a[city][ncity];
  		return;
	}
	mincost(ncity);
}

int main()
{
	clock_t start,end;
	int i,j;
	printf("Enter the number of cities:");
	scanf("%d",&n);
	printf("\nEnter the Matrix\n");
	for(i=0;i < n;i++)
		for( j=0;j < n;j++)
		  	scanf("%d",&a[i][j]);
    	printf("\n\nThe Path is:\n");
	start=clock();
	mincost(0);
    	printf("\n\nMinimum cost is %d\n ",cost);
	end=clock();
	double time=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n\nTime taken :: \nStart = %ld\nEnd = %ld\nTotal time taken = %f\n\n",start,end,time);
	return 0;
}
