#include<stdio.h>
#include<string.h>
#include<time.h> 
 
int i,j,m,n,c[50][50];
char x[50],y[50],b[50][50];
 
void lcs()
{
	m=strlen(x);
        n=strlen(y);
	for(i=0;i<=m;i++)
        	c[i][0]=0;
        for(i=0;i<=n;i++)
                 c[0][i]=0;
        for(i=1;i<=m;i++)
        	for(j=1;j<=n;j++)
                {
        	        if(x[i-1]==y[j-1])
                        {
        	                c[i][j]=c[i-1][j-1]+1;
                                b[i][j]='c';
                        }
                        else if(c[i-1][j]>=c[i][j-1])
                        {
        	                c[i][j]=c[i-1][j];
                                b[i][j]='u';
                        }
                        else
                        {
        	                c[i][j]=c[i][j-1];
                                b[i][j]='l';
                        }
		}
}
 
void print(int i,int j)
{
	if(i==0 || j==0)
	        return;
        if(b[i][j]=='c')
	{
        	print(i-1,j-1);
                printf("%c",x[i-1]);
        }
        else if(b[i][j]=='u')
        	print(i-1,j);
        else
        	print(i,j-1);
}
 
int main()
{       
	printf("Enter first sequence:");
        scanf("%s",x);
        printf("Enter second sequence:");
        scanf("%s",y);
	clock_t start,end;
	start=clock();
        printf("\nThe Longest Common Subsequence is ");
        lcs();
        print(m,n);
        end=clock();
	double time=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n\nTime taken :: \nStart = %ld\nEnd = %ld\nTotal time taken = %f\n\n",start,end,time);
	return 0;
}
