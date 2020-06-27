#include<stdio.h>
#include<time.h>
int a[50];double t, t1, tt, tt1;
void qsort (int, int);
int split (int, int);
int
main ()
{
  int n, i;
  t = clock ();
  printf ("\nHow many elements?\n");
  scanf ("%d", &n);
  printf ("\nEnter %d elements:\n", n);
  for (i = 0; i < n; i++)
    scanf ("%d", &a[i]);
  t1 = clock ();
  qsort (0, n - 1);
  t1 = clock () - t1;
  tt1 = ((double) t1) / CLOCKS_PER_SEC;
  printf ("\nthe total time taken by quicksort function:%f\n", tt1);
  printf ("\nThe resultant array:\n");
  for (i = 0; i < n; i++)
    printf ("%d  ", a[i]);
  t = clock () - t;
  tt = ((double) t) / CLOCKS_PER_SEC;
  printf ("\nthe total time taken for execution:%f\n", tt);
  return 0;
}

void
qsort (int start, int end)
{
  int s;
  if (start >= end)
    return;
  s = split (start, end);
  qsort (start, s - 1);
  qsort (s + 1, end);
}

int
split (int start, int end)
{
  int p = a[start];
  int i = start, j = end, temp;
  while (i < j)
    {
      while (a[i] <= p)
	i++;
      while (a[j] > p)
	j--;
      if (i < j)
	temp = a[i], a[i] = a[j], a[j] = temp;
    }
  a[start] = a[j];
  a[j] = p;
  return j;
}
