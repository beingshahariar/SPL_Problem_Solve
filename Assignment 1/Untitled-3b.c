#include <stdio.h>

int main (){

int n,i;
printf ("Enter the integer:");
scanf ("%d",&n);

for ( i = 0; i < n; i++)
{
  for (int j = 0; j < i; j++)
  {
    printf (" ");
  }
  for (int j = 1; j <=n+1; j++)
  {
    printf ("%d",j);
  }
  printf ("\n");
}

  return 0;
}