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

void merge(int low, int mid, int high, int a[])
{
	int x=mid-low+1,y=high-mid;
	int L[x],R[y],i,j,k=low;
	for(int i=0;i<x;i++)
		L[i]=a[i+low];
	for(int j=0;j<y;j++)
		R[j]=a[j+mid+1];
	i=j=0;
	while(i<x && j<y)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<x)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<y)
	{
		a[k]=R[j];
		j++;
		k++;
	}
}

void mergesort(int low, int high, int a[])
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(low,mid,a);
		mergesort(mid+1,high,a);
		merge(low,mid,high,a);
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
	mergesort(0,n-1,a);
	printf("AFTER sorting, this is how your array looks like\n");
	display(n,a);
	end=clock();
	double time=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n\nTime taken :: \nStart = %ld\nEnd = %ld\nTotal time taken = %f\n\n",start,end,time);
	return 0;
}





