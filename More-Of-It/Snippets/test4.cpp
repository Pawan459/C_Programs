#include<stdio.h>
int collatz(int n);
int main()
{
  int n,s;
  scanf("%d",&n);
  s=collatz(n);
  printf("%d",s);
}
int collatz(int n)
{
  static int count=0;
  if(n==1)
    return count;
  if(n%2==0)
  {
    count++;
    return collatz(n/2);
  }
  else
  {
    count++;
    return collatz(3*n+1);
  }
}
