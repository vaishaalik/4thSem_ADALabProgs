#include<stdio.h>
#include<time.h>

int factorial(int x)
{
	int f=1;
	for(int i=1;i<=x;i++)
		f*=i;
	return f;
}

int main()
{
	int n,p,c,r,fn,fnr,fr;
	printf("Enter values for n and r to calculate Permutation and Combination :: ");
	scanf("%d%d",&n,&r);
	clock_t start,end;
	start=clock();
       	fn=factorial(n);
	fnr=factorial(n-r);
	fr=factorial(r);
	p=fn/fr;
	c=fn/(fr*fnr);
	printf("\nFor the above entered values \nPermutation == %d\nCombination == %d\n",p,c);
       	end=clock();
	double time=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n\nTime taken :: \nStart = %ld\nEnd = %ld\nTotal time taken = %f\n\n",start,end,time);
	return 0;
}
