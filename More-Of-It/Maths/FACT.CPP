// Program to calculate big factorials in c
#include<stdio.h>
#include<conio.h>

int main()
{
int numArr[10000];			// Approximately , size of array depends on size of factorial.
int total,rem=0,count;		//rem use to save remainder of division(Carry Number).
register int i;
for(i=0;i<10000;i++)
	numArr[i]=0;		//set all array on NULL.

i=9999;				//start from end of array.
numArr[9999]=1;

for(count=2;count<=9999;count++)//It's Just simple math as we do we multiply the digits
{								// and forward the carry to the next digit
  while(i>0)
   {
      total=numArr[i]*count+rem;
      rem=0;
	if(total>9)
	 {
	  numArr[i]=total%10;
	  rem=total/10;
	 }
	else
	 numArr[i]=total;
      i--;
   }
rem=0;
total=0;
i=9999;
}

for(i=0;i<10000;i++)             // Display array's cell to show factorial 1000
{
	if(numArr[i]!=0 | count==1)
	{
	  printf("%d",numArr[i]);
	  count=1;
	}
}

getch();
}

