#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int h[50];

void heapify(int h[],int n)
{
  int i,j,n1,k,heap,v;
  n1=n;
  for(i=n1/2;i>=1;i--)
  {
    k=i;
    v=h[k];
    heap=0;
    while(!(heap)&&(2*k)<=n1)
    {
      j=2*k;
      if(j<n1)
        if(h[j]<h[j+1])
          j=j+1;
      if(v>=h[j])
        heap=1;
      else
      {
        h[k]=h[j];
        k=j;
      }
      h[k]=v;
    }
  }
}

int main()
{
  int i,n,size,t;
  clock_t start,end;
  double totaltime;
  //clrscr();
  printf("Enter value of n: ");
  scanf("%d",&n);
  //printf("Enter array elements\n");
  for(i=1;i<=n;i++)
  {
    h[i]=rand();
  }
  //scanf("%d",&h[i]);
  printf("Elements are\n");
  for(i=1;i<=n;i++)
  {
    printf("%d\n",h[i]);
  }
  start=clock();
  heapify(h,n);
  printf("Elemts heapified:\n");
  for(i=1;i<=n;i++)
    printf("%d\n",h[i]);
  for(i=n;i>=1;i--)
  {
    t=h[1];
    h[1]=h[i];
    h[i]=t;
    size=i-1;
    heapify(h,size);
  }
  end=clock();
  printf("Elemtents sorted\n");
  for(i=1;i<=n;i++)
    printf("%d\n",h[i]);
  totaltime=(double)(end-start)/CLOCKS_PER_SEC;
  printf("Time taken is %e",totaltime);
  //getch();
}


