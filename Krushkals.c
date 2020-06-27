#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[9][9],parent[9];

int find(int i)
{
	while(parent[i])
		i=parent[i];
	return i;
}

int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}

void krushkals()
{
	while(ne<n)
	{
		for(i=1,min=999;i<=n;i++)
			for(j=1;j<=n;j++)
				if(cost[i][j]<min)
    				{
     					min=cost[i][j];
     					a=u=i;
     					b=v=j;
    				}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
   			printf("%d edge (%d,%d) = %d\n",ne,a,b,min);
   			mincost +=min;
  		}
  		cost[a][b]=cost[b][a]=999;
		ne++;
 	}
	printf("\nMinimum cost = %d.\n\n",mincost);
}

int main()
{
	clock_t start,end;
	printf("Implementation of Kruskal's algorithm \n");
	printf("How many vertices does your graph have :: ");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
    				cost[i][j]=999;
  		}
	start=clock();
	printf("\nThe edges of Minimum Cost Spanning Tree are : \n");
	krushkals();
	end=clock();
	double time=((double)(end-start))/CLOCKS_PER_SEC;
	printf("Time taken :: \nStart = %ld\nEnd = %ld\nTotal time taken = %f\n\n",start,end,time);
	return 0;
}
