#include <stdio.h>

int main (){

int studentId,i;
printf ("Enter the student id:");
scanf ("%d",&studentId);

int b=(studentId%100)%21+5;
printf ("%d\n",b);

int A[10];
printf ("Array A:\n");

for ( i = 0; i < 10; i++)
{
  A[i]=(studentId%10000)%7+3*i;
  printf ("%d\n",A[i]);
}

int sumeven=0;
for ( i = 0; i < 10; i++)
{
  sumeven +=A[i];
}

printf ("Sum of the numbers of even integers:%d\n",sumeven);

  return 0;
}