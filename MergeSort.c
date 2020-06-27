#include<stdlib.h> 
#include<stdio.h> 
#include<time.h>
double tt,t1,tt1,t;
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
      int L[n1], R[n2]; 
      for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
      i = 0;
    j = 0; 
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
int main() 
{ 
    int n,i,arr[50];
    t=clock();
    printf("enter array size:");
    scanf("%d",&n);
    for(i+0;i<n;i++)
    {
        printf("enter array element at[%d]:",i);
        scanf("%d",&arr[i]);
    }
    t1=clock();
    mergeSort(arr, 0, n - 1); 
    t1=clock()-t1;
    tt1=((double)t1)/CLOCKS_PER_SEC;
    printf("total execution time for mergesort function:%f",tt1);
    printf("\nSorted array is \n"); 
    printArray(arr, n); 
    t=clock()-t;
    tt=((double)t)/CLOCKS_PER_SEC;
    printf("total execution time:%f",tt);
    return 0; 
} 
