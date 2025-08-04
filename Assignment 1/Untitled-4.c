#include <stdio.h>

int main (){

float basicSalary,houseRent,medicalAllowance,providentFund,totalSalary;

printf ("Enter the basic salary:");
scanf ("%f",&basicSalary);

if (basicSalary<=40000){
  houseRent=0.25*basicSalary;
}
else if (basicSalary<=80000)
{
  houseRent=0.30*basicSalary;
}
else {
  houseRent=0.40*basicSalary;
}


if (medicalAllowance<=60000)
{
  medicalAllowance=0.50*basicSalary;
}
else{
  medicalAllowance=0.70*basicSalary;
}


if (basicSalary<=40000)
{
  providentFund=2000;
}
else if (basicSalary<=100000)
{
  providentFund=400;
}
else{
  providentFund=5000;
}


float incomeTax=1500;

totalSalary=basicSalary+houseRent+medicalAllowance-providentFund-incomeTax;

printf ("Total salary:%.2f\n",totalSalary);


  return 0;
}