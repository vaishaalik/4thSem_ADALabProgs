#include<stdio.h>
#include<time.h>
#define MAX_INT 10000000

int p[20];

int matrixMultiplication(int x,int p[x], int N)
{
	int L,i, j, temp;
	int M[N][N];
	for(i=0; i<N; i++)
	      for(j=0; j<N; j++)
           M[i][j] = 0;       
  	for(L=2; L<N; L++)
	{
    		for(i=1; i<N-L+1; i++)
  		{
        		j = i+L-1;
        		M[i][j] = MAX_INT;
            		for(int k=i; k<j; k++)
			{
                		temp = M[i][k] + M[k+1][j] + p[i-1] * p[k] * p[j];
                		if(temp < M[i][j])
 					M[i][j] = temp;
            		}
        	}
    	}
	return M[1][N-1];
}

int main()
{
	clock_t start,end;
	int x;
      	printf("enter x i.e, the no. of matrices + 1:");
      	scanf("%d",&x);
      	int p[x];
      	printf("enter matrices size sequence:\n");
      	for(int i=0;i<x;i++)
		scanf("%d",&p[i]);
     	int n = sizeof(p)/sizeof(p[0]);
      	start=clock();
      	printf("Minimum no. of multiplications is:%d\n", matrixMultiplication(x,p,n));
      	end=clock();
	double time=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n\nTime taken :: \nStart = %ld\nEnd = %ld\nTotal time taken = %f\n\n",start,end,time);
	return 0;
}
