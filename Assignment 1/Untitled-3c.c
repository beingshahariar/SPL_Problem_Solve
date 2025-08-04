#include <stdio.h>

int main (){

int n,i;
printf ("Enter the integer:");
scanf ("%d",&n);

for (int i = 1; i <=n; i++)
{
  if (i%2==1)
  {
    for (int j = n+1; j>0; j--)
    {
      printf ("%d",j);
    } 
  }
  else{
    printf (" ");
  for (int k = 1; k < n+2; k++)
  {
    printf ("%d",k);
  }
  }
  printf ("\n"); 
}

return 0;
}