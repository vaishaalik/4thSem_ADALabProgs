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

int lsi(int n, int a[], int key)
{
	int p=-1;
	for(int i=0;i<n;i++)
		if(a[i]==key)
			p=i;
	return p;
}

int lsr(int n, int a[], int key, int i)
{
	if(n<i)
		return -1;
	else if(a[i]==key)
		return i;
	else
		return lsr(n,a,key,i+1);
}

int bsi(int n, int a[], int key)
{
	int low=0,high=n-1,mid;
	while(low<high)
	{
		mid=(low+high)/2;
		if(a[mid]==key)
			return mid;
		else if(key<=a[mid])
			high=mid-1;
		else if(key>a[mid])
			low=mid+1;
		else
			return -1;
	}
}
int bsr(int low, int high, int a[], int key)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		if(a[mid]==key)
			return mid;
		else if(key<=a[mid])
			return bsr(low,mid-1,a,key);
		else if(key>a[mid])
			return bsr(mid+1,high,a,key);
		else
			return -1;
	}
}
int main()
{
	printf("Welcome to teh search! We have :\n------------------------\n1. Linear Search - Iterative method\n2. Linear Search - Recursive method\n3. Binary Search - Iterative method\n4. Binary Search - Recursive method\n------------------------\nWhat type of search shall we do today? Please enter ( 1 / 2 / 3 / 4 ) :: ");
	int choice;
	scanf("%d",&choice);
	if(choice<1 || choice>5)
	{
		printf("Please enter a valid input. Sorry BYE.\n");
		return 0;
	}
	int n,key,pos;
	printf("What is the size of your array? ");
	scanf("%d",&n);
	int a[n];
	if(choice==3 || choice==4)
		printf("Please enter values into array in ascending order only.\n");
	getarray(n,a);
	printf("What element are we looking for? :: ");
	scanf("%d",&key);
	clock_t start,end;
	start=clock();
	switch(choice)
	{
		case 1: pos=lsi(n,a,key); break;
		case 2: pos=lsr(n,a,key,0); break;
		case 3: pos=bsi(n,a,key); break;
		case 4: pos=bsr(0,n-1,a,key); break;
		default : printf("Wrong option boss\n");
	}
	if(pos==-1)
		printf("Key element not found! Try again later.\n");
	else
		printf("%d element found at location %d in the array! Hurray!\n",key,pos+1);

	end=clock();
	double time=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\n\nTime taken :: \nStart = %ld\nEnd = %ld\nTotal time taken = %f\n\n",start,end,time);
	return 0;
	
}
