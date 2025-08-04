#include <stdio.h>

int main (){

int n=10;
int fibonacci [n];

fibonacci[0]=1;
fibonacci[1]=1;

for (int i = 2; i < n; i++)
{
  fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
}
printf ("Frist 10 fibonacci number:\n");
for ( int i = 0; i < n; i++)
{
  printf ("%d ",fibonacci[i]);
}
printf ("\n");

printf ("Odd-indexed fibonacci number:\n");
for (int i = 0; i < n; i +=2)
{
  printf ("%d ",fibonacci[i]);
}
printf ("\n");

printf ("Even-indexed fibonacci number:\n");
for (int i = 1; i < n; i +=2)
{
  printf ("%d ",fibonacci[i]);
}
printf ("\n");

  return 0;
}