#include <stdio.h>

int main (){

int zeros [10]={ 0 };
int ones []={ 1, };
int superones [5]={1,1,1,1,1};
int fibosequence [7]={1,1,2,3,5,6,13};
int i;

for ( i = 0; i < 10; i++)
{
  printf ("%d ",zeros[i]);
}
puts ("");

for ( i = 0; i < 1; i++)
{
  printf ("%d ",ones[i]);
}
puts ("");

for ( i = 0; i < 5; i++)
{
  printf ("%d ",superones[i]);
}
puts ("");

for ( i = 0; i < 7; i++)
{
  printf ("%d ",fibosequence[i]);
}
puts ("");

  return 0;
}