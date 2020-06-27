#include<stdio.h>
#include<time.h>
#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX],int n,int startnode)
{
    int cost[MAX][MAX],distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;
    for(i=0;i<n;i++)
   	 for(j=0;j<n;j++)
   		 if(G[i][j]==0)
   			 cost[i][j]=INFINITY;
   		 else
   			 cost[i][j]=G[i][j];
    for(i=0;i<n;i++)
	{
  	distance[i]=cost[startnode][i];
  	pred[i]=startnode;
  	visited[i]=0;
	}
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1)
	{
  	mindistance=INFINITY;
  	for(i=0;i<n;i++)
    	if(distance[i]<mindistance&&!visited[i])
      	{
        	mindistance=distance[i];
        	nextnode=i;
      	}
   		 visited[nextnode]=1;
   		 for(i=0;i<n;i++)
   			 if(!visited[i])
   				 if(mindistance+cost[nextnode][i]<distance[i])
        	{
          	distance[i]=mindistance+cost[nextnode][i];
          	pred[i]=nextnode;
        	}
  	count++;
	}
    for(i=0;i<n;i++)
   	 if(i!=startnode)
  	{
    	printf("\nDistance of node %d = %d ",i,distance[i]);
    	printf("\nPath=%d ",i);
    	j=i;
    	while(j!=startnode)
      	{
        	j=pred[j];
        	printf("<-%d",j);
      	}
  	}
}

int main()
{
	clock_t start,end;
    	int G[MAX][MAX],i,j,n,u;
    	printf("Enter no. of vertices:");
    	scanf("%d",&n);
    	printf("\nEnter the adjacency matrix:\n");
    	for(i=0;i<n;i++)
   		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
	printf("\nEnter the starting node:");
    	scanf("%d",&u);
  	start=clock();
    	dijkstra(G,n,u);
	end=clock();
	double time=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n\nTime taken :: \nStart = %ld\nEnd = %ld\nTotal time taken = %f\n\n",start,end,time);
	return 0;
 
}
