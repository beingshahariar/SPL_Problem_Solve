#include <stdio.h>

int main (){
int n,sum=0;
printf ("Enter the terms of n:");
scanf ("%d",&n);

for (int i = 1,a=1; i <=n; i++,a+=2)
{
  if (i%2==1)
  {
    sum +=a;
  }
  else{
    sum -=a;
  }
  
}

printf ("Sum of the %dth terms:%d\n",n,sum);

  return 0;
}