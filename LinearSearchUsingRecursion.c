#include <stdio.h>  
#include<time.h>
int LinearSearch(int arr[],  int search,int i,int n);  
int main()  
{  
    int n, search, result, m = 0, arr[100];  
    double tt,tt1,t1,t;
    t=clock();
    printf("Program on Linear Search\n");  
    printf("-------\n");  
    printf("Enter the total elements in the array\n");  
    scanf("%d", &n);  
    printf("Enter the array elements\n");  
    for (int i = 0; i < n; i++)  
    {  
        scanf("%d", &arr[i]);  
    }  
    printf("Enter the element to search \n");  
    scanf("%d", &search);  
    t1=clock();
    result =  LinearSearch(arr,  search,0,n);  
    if (result != 0)  
    {  
        printf("Element found at pos %d\n ", result);  
    }  
    else  
    {  
        printf("Element not found");  
    } 
    t1=clock()-t1;
    tt1=((double)t1)/CLOCKS_PER_SEC;
    printf("the total amount of time taken for the LinearSearch function is: %f\n",tt1);
    t=clock()-t;
    tt=((double)t)/CLOCKS_PER_SEC;
    printf("the total amount of time taken is: %f\n",tt);
return 0;  
}  
int LinearSearch(int arr[],int search,int i,int n)  
{  
    int key=0;  
    if(i>=n)  
    {  
        return 0;  
    }  
        if (arr[i] == search)  
        {  
            key = i+ 1;  
            return key;  
        }  
        else  
        {  
        return LinearSearch(arr, search,i+1,n);  
        }  
    return key;  
}  
