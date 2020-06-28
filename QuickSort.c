#include<stdio.h>
#include<time.h>

void getarray(int n, int a[])
{
	printf("Enter array : \n");
	for(int i=0;i<n;i++)
	{
		printf("pos[%d] :: ",i+1);
		scanf("%d",&a[i]);
	}
}

void display(int n, int a[])
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	
}

void swap(int *a, int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

int partition(int low, int high, int a[])
{
	int i=low-1,pivot=a[high];
	for(int j=low;j<high;j++)
		if(a[j]<pivot)
		{
			i++;
			swap(&a[j],&a[i]);
		}
	swap(&a[i+1],&a[high]);
	return i+1;
}

void quicksort(int low, int high, int a[])
{
	if(low<high)
	{
		int pi=partition(low,high,a);
		quicksort(low,pi-1,a);
		quicksort(pi+1,high,a);
	}
}

int main()
{
	int n;
	printf("How many numbers do you want to enter?  ");
	scanf("%d",&n);
	int a[n];
	getarray(n,a);
	printf("Before any sorting, this is how your array looks like\n");
	display(n,a);
	clock_t start,end;
	start=clock();
	quicksort(0,n-1,a);
	printf("AFTER sorting, this is how your array looks like\n");
	display(n,a);
	end=clock();
	double time=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n\nTime taken :: \nStart = %ld\nEnd = %ld\nTotal time taken = %f\n\n",start,end,time);
	return 0;
}

