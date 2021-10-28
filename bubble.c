#include <stdio.h>
#include<stdlib.h>
#include<time.h>
 
int main()
{
  int array[100], n, c, d, swap;
  clock_t start,end;
  double totaltime;	
 
  printf("Enter number of elements: ");
  scanf("%d", &n);
 
  printf("Enter %d integers\n", n);
 
  for (c = 0; c < n; c++)
  { 
    array[c]=rand();
    printf("%d\n", array[c]);
  }
  start=clock();

  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d+1]) /* For decreasing order use < */
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }
 end=clock();
totaltime=(double)(end-start)/CLOCKS_PER_SEC;
printf("Time taken is %e",totaltime);
 printf("\nSorted list in ascending order\n");
 
  for ( c = 0 ; c < n ; c++ )
     printf("%d\n", array[c]);
 
  return 0;
}
